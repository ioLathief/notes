//API Imports
        [DllImport("user32.dll", SetLastError = true)]
        public static extern bool RegisterHotKey(
            IntPtr hWnd, // handle to window    
            int id, // hot key identifier    
            KeyModifiers fsModifiers, // key-modifier options    
            Keys vk    // virtual-key code    
            );
        [DllImport("user32.dll", SetLastError = true)]
        public static extern bool UnregisterHotKey(
            IntPtr hWnd, // handle to window    
            int id      // hot key identifier    
            );
        const int HOTKEY_ID = 31197; //Any number to use to identify the hotkey instance
        public enum KeyModifiers        //enum to call 3rd parameter of RegisterHotKey easily
        {
            None = 0,
            Alt = 1,
            Control = 2,
            Shift = 4,
            Windows = 8
        }
        
        public bool setHotKey(KeyModifiers Kmds, Keys key)
        {
            return RegisterHotKey(this.Handle, HOTKEY_ID, Kmds, key);
        }
        public bool unSetHotKey()
        {
            return UnregisterHotKey(this.Handle, HOTKEY_ID);
        }
        const int WM_HOTKEY = 0x0312;//magic hotkey message identifier
        protected override void WndProc(ref Message message)
        {


            if(message.Msg==0x0312&message.WParam.ToInt32()=WM_HOTKEY){
                //do something
            }
            base.WndProc(ref message);

        }
        //put this code in the onload method of your form
           setHotKey(KeyModifiers.Alt | KeyModifiers.Shift, Keys.S);
        //and set up a form closed event and call
            unSetHotKey();