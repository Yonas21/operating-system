#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

void *kidFun(void *p){
	printf("Kid id --> %d\n",getpid());
}

void main(){
	pthread_t kid;
	pthread_create(&kid,NULL,kidFun,NULL);

	printf("parent id -->%d\n",getpid());

	pthread_join(kid,NULL);
	printf("No kid no more\n");
	fork();
	pthread_create(&kid,NULL,kidFun,NULL);
	printf("parent process id: %d\n",getpid() );
}