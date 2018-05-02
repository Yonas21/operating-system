#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int globalVar = 10;

void *childFunction(void *ptr){
	printf("child process ,with data of:%d \n",globalVar);

	//assign the value to global variable 
	globalVar = 15;
	printf("other child ,with data of: %d \n",globalVar);
}
int main(){
	pthread_t tid;
	int status;
	pthread_create(&tid,NULL,childFunction,NULL);
	printf("parent process with id:%d \n",getpid() );
	//fork();
	globalVar = 5;
	pthread_join(tid,NULL);
	printf("End of Program:%d \n",getpid() );
}