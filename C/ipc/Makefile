CC=gcc
LDFLAGS = -lpthread -lrt

all: sendmsg getmsg sem_client sem_server memside01 memside02 posix01 posix02

sendmsg: messagequeue01.o
	$(CC) -o sendmsg messagequeue01.o -I.

getmsg: messagereadwait.o
	$(CC) -o getmsg messagereadwait.o

sem_client: sem_client.o
	$(CC) -o sem_client sem_client.o $(LDFLAGS)

sem_server: sem_server.o
	$(CC) -o sem_server sem_server.o $(LDFLAGS)

memside01: memside01.o
	$(CC) -o $@ $(CFLAGS) $(CURL_CFLAGS) $^ $(LDFLAGS) $(CURL_LIBS)

	
memside01: memside01.o
	$(CC) -o $@ $(CFLAGS) $(CURL_CFLAGS) $^ $(LDFLAGS) $(CURL_LIBS)
	
posix01: posix01.o
	$(CC) -o $@ $(CFLAGS) $(CURL_CFLAGS) $^ $(LDFLAGS) $(CURL_LIBS)

posix02: posix02.o
	$(CC) -o $@ $(CFLAGS) $(CURL_CFLAGS) $^ $(LDFLAGS) $(CURL_LIBS)
	
clean: 
	rm -fr *.o sendmsg getmsg sem_client sem_server
