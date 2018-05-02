#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

#define Nthreads 5
char *messages[Nthreads];

void *printHello(void *threadid){
	int *id_ptr,taskid;
	sleep(1);
	id_ptr = (int *)threadid;
	taskid = *id_ptr;
	printf("%s From %d\n",messages[taskid],taskid);
	pthread_exit(NULL);
}
int main(){
	pthread_t threads[Nthreads];
	int *taskids[Nthreads];
	int ntrd,i;
	messages[0] = "English:Hello";
	messages[1] = "French: Bonjour";
	messages[2] = "Spanish: Hola";
	messages[3] = "German: Guten";
	messages[4] = "Amharic: selam";
	for(i= 0;i<Nthreads;i++){
		taskids[i] = (int *)malloc(sizeof(int));
		*taskids[i] = i;
		printf("Creating threads %d\n",i );
		ntrd = pthread_create(&threads[i],NULL,printHello,(void *)taskids[i]);
		if(ntrd ){
			printf("ERROR of creating threads %d\n",ntrd);
			exit(-1);
		}
	}
	pthread_exit(NULL);
}