/* msg.x: Remote msg printing protocol */
program MESSAGEPROG {
   version PRINTMESSAGEVERS {
     int PRINTMSG(string) = 1;
	 int SQUAREIT(int) = 2;
   } = 1;
} = 0x20000002;