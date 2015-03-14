#include <stdio.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <sys/shm.h>
#include<sys/errno.h>
#include<sys/msg.h>
#include<string.h>

struct qmsg {
	long mtype;
	char mtext[50];
	int val;
        char cc[2048];
	
};


extern int errno;       // error NO.

int main(){
	int keyval = 777;
	key_t msgkey;

	msgkey = ftok(".", keyval);
	printf("MSGKEY = %d\n", (int)msgkey);
	int result, len;
	

	int qid = msgget(msgkey, IPC_CREAT | 0660);
	printf("QID is %d\n", qid);


	struct qmsg newmsg;

	while ( 1 ) {
		int rx = msgrcv(qid, &newmsg, sizeof(struct qmsg) - sizeof(long), 0, 0);
		printf("The rx text is %s\n", newmsg.mtext);
		printf("The rx val is %d\n", newmsg.val);
		printf("Result of send is %d\n", result);
		printf("OK\n");
	}
	return 0;
}
