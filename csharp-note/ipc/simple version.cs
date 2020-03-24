using System;
using System.IO;
using System.IO.Pipes;
using System.Text;
using System.Threading;

namespace serverProEd
{
    internal class Program
    {
        private static NamedPipeServerStream _pipeServer;
        private static StreamString _ss;
        public static void Main(string[] args)
        {
            _pipeServer = new NamedPipeServerStream("dtestpipe", PipeDirection.InOut, 1);
            _ss = new StreamString(_pipeServer);
            
            Console.WriteLine("waiting for connection");
            _pipeServer.WaitForConnection();
            
            //use following stream class to simply read and write (and somefun is complete version of this)

            _pipeServer.Close();
        }
    }
    
    public class StreamString
    {
        private Stream ioStream;
        private UnicodeEncoding streamEncoding;

        public StreamString(Stream ioStream)
        {
            this.ioStream = ioStream;
            streamEncoding = new UnicodeEncoding();
        }

        public string ReadString()
        {
            int len = 0;
            len = ioStream.ReadByte() * 256;
            len += ioStream.ReadByte();
            byte[] inBuffer = new byte[len];
            ioStream.Read(inBuffer, 0, len);

            return streamEncoding.GetString(inBuffer);
        }

        public int WriteString(string outString)
        {
            byte[] outBuffer = streamEncoding.GetBytes(outString);
            int len = outBuffer.Length;
            if (len > UInt16.MaxValue)
                len = (int) UInt16.MaxValue;
            //here we go
            ioStream.WriteByte((byte) (len / 256));
            ioStream.WriteByte((byte) (len & 255));
            ioStream.Write(outBuffer, 0, len);
            ioStream.Flush();

            return outBuffer.Length + 2;
        }
    }
}