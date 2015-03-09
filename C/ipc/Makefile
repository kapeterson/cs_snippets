CC=gcc
LDFLAGS = -lpthread

all: sendmsg getmsg sem_client sem_server

sendmsg: messagequeue01.o
	$(CC) -o sendmsg messagequeue01.o -I.

getmsg: messagereadwait.o
	$(CC) -o getmsg messagereadwait.o





sem_client: sem_client.o
	$(CC) -o sem_client sem_client.o $(LDFLAGS)



sem_server: sem_server.o
	$(CC) -o sem_server sem_server.o $(LDFLAGS)




clean: 
	rm -fr *.o sendmsg getmsg sem_client sem_server
