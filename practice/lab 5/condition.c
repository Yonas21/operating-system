#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_var = PTHREAD_MUTEX_INITIALIZER;

int count =0  ;

#define true 1
#define count_done 0


void *counter(void *ptr);
void *printer(void *ptr);

int main(){
	pthread_t th_id1,th_id2;

	pthread_create(&th_id1,NULL,&counter,(void * count));
	pthread_create(&th_id2,NULL,&printer,(void * NULL));

	pthread_join(th_id1,NULL);
	pthread_join(th_id2,NULL);

	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond_var);

	return 0;
}

void *counter(void *ptr){
	while(true){
		pthread_mutex_lock(&mutex);
		count++;
		if(count ==5){
			pthread_cond_signal(&cond_var);
		}

		pthread_mutex_unlock(&mutex);

		if(count == count_done){
			pthread_exit(EXIT_SUCCESS);
		}
	}

}
void *printer(void *ptr){
	while(true){
		pthread_mutex_lock(&mutex);
		pthread_cond_wait(&cond_var,&mutex);

		printf("the value of count is :%d\n",count );

		pthread_mutex_unlock(&mutex);
		if(count == count_done){
			pthread_exit(EXIT_SUCCESS);
		}

	}
}