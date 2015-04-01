/* msg.x: Remote msg printing protocol */
struct ldata {
	int val;
	int size;
};

program MESSAGEPROG {
   version PRINTMESSAGEVERS {
     int PRINTMSG(string) = 1;
	 int SQUAREIT(int) = 2;
	 int PRINTDATA(ldata) = 3;
   } = 1;
} = 0x20000002;