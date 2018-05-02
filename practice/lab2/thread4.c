#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

#define threads 5

void *printHello(void *thread_id){
	int id_ptr = (int *)thread_id;
	printf("Hello from: %d\n",id_ptr );
	pthread_exit(NULL);
}

int main(){
	pthread_t thread[threads];
	int tnum,i;

	for(i = 0;i<threads;i++){
		printf("creating threads :%d\n",i );
		tnum = pthread_create(&thread[i],NULL,printHello,(void *)&i);
		if(tnum !=0 ){
			printf("Error of creating threads\n");
			exit(-1);
		}
	}
	pthread_exit(NULL);
}