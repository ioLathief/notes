using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void callbakcdel();

        [DllImport("Project1.dll")]
        public static extern void TestDelegate(callbakcdel f,[MarshalAs(UnmanagedType.LPStr)]string lpString);

        public static void cb_func()
        {
            Console.WriteLine("callback process");
        }
        public static callbakcdel smod;
        static void Main(string[] args)
        {
            
            smod = new callbakcdel(cb_func);
            TestDelegate(smod,"simple_lpString");

            Console.ReadLine();
        }

        
    }
}
