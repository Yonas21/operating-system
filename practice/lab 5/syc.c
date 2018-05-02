#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <semaphore.h>

void *updateBalance(void *ptr);

double balance = 1000.00;

int main(){
	printf("intial value of balance is:%d",balance);

	double deposit = 200.00;
	pthread_t thread_id1;
	pthread_t thread_id2;

	pthread_create(thread_id1,NULL,$updateBalance,(void*)&deposit);
	pthread_create(thread_id2,NULL,$updateBalance,(void * )&deposit);

	pthread_join(thread_id1,NULL);
	pthread_join(thread_id2,NULL);

	printf("the final balance is:%d",balance);
	return 0;
} 

void *updateBalance(void *ptr){
	double deposit_value = (double * ) ptr;
	sem_wait(&mutex);

	balance += *balance+=deposit;
	
}