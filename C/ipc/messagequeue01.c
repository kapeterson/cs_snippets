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
	
};


extern int errno;       // error NO.

int main(){
	int keyval = 777;
	key_t msgkey;

	msgkey = ftok(".", keyval);
	printf("MSGKEY = %d\n", (int)msgkey);
	int result, len;
	
	int qid = msgget(msgkey, IPC_CREAT | 0660);

	
	

	
	if ( qid == -1 ) {
		printf("WE had an issue\n");
		return 1;
	}
	
	struct qmsg thismessage;
	//thismessage.id = 5;
	//thismessage.request = 14;
	thismessage.mtype = 1;
	thismessage.val = 44;
	strcpy(thismessage.mtext,"test");
	
	result = msgsnd(qid, &thismessage,  sizeof(struct qmsg) - sizeof(long), 0);
	if ( result == -1){
		perror("send_message");
		//perror( strerror(errno) );
		return 1;
	}
	
	struct qmsg newmsg;
	int rx = msgrcv(qid, &newmsg, sizeof(struct qmsg) - sizeof(long), 0, 0);
	printf("The rx text is %s\n", newmsg.mtext);
	printf("The rx val is %d\n", newmsg.val);
	printf("Result of send is %d\n", result);
	printf("OK\n");
	return 0;
}
