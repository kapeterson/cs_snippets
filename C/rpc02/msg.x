/* msg.x: Remote msg printing protocol */
program MESSAGEPROG {
   version PRINTMESSAGEVERS {
     int PRINTMSG(string) = 1;
   } = 1;
} = 0x20000002;