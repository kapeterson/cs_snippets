CC=cc
CFLAGS = -Wall
LIBS = -lnsl


all: rpcserver rpcclient

rpcserver: 
	$(CC) $(CFLAGS) -o rpcserver msg_procs.c msg_svc.c $(LIBS)

rpcclient:
	$(CC) $(CFLAGS) -o rpcclient rpcclient.c msg_clnt.c $(LIBS)

clean:
	rm -f rpcserver rpcclient
	rm -f *.o
