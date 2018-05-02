#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#include <uns.h>


sem_t mutex;
double balance = 1000.0;

void main(){
    sem_init(&mutex,0,1);
    pthread_create()
    updateBalance();
}
void *updateBalance(void *ptr){
    double deposit = 200;
    double balance+=deposit;
    return balance;
}