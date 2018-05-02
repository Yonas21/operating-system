#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define SIZE 10
#define true 1
sem_t empty;
sem_t full;
int buf[SIZE];

void *producer(void *ptr);
void * consumer(void *ptr);

int in,out;

int main(){
	printf("Generate Random\n");

	pthread_t thread_id1;
	pthread_t thread_id2;

	//create threads
	pthread_create(&thread_id1,NULL,&producer,(void * )random);
	pthread_create(&thread_id2,NULL,&consumer,(void *)random);

	//initialize semaphore

	sem_init(&empty,0,SIZE);
	sem_init(&full,0,0);

	pthread_join(thread_id1,NULL);
	pthread_join(thread_id2,NULL);

	sem_destroy(&empty);
	sem_destroy(&full);

	printf("Generated Random is:%d\n",random );

	return 0;

}


void *producer(void *ptr){
	while(true){
	int random =rand() %10;

	sem_wait(&empty);

	buf[in] = random;
	random = (random+1) % SIZE;

	sem_post(&full); //signalling the consumer after the produce the item;
	}
}

void *consumer(void *ptr){
	while(true){
		sem_wait(&full);
		int random = buf[out];

		printf("number consumed is :%d\n", random);
		out = (out+1) % SIZE;

		sem_post(&empty);//signalling the producer that buffer is empty
		sem_post(&mutex);


	}
}