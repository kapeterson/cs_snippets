#ifndef IPCSTRUCT_H
#define IPC_STRUCT_H

typedef struct {
	int value;
	pthread_mutex_t memMutex;
	pthread_cond_t  cvProxyGo;
	pthread_cond_t  cvCacheGo;
	int thekey;

} ipcstruct;


#endif
