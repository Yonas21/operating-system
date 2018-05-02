#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#define THREADS 10

void *sayHello(void *tid){
	//prints greeting for the users
	printf("Hello world.Greetings from threads %d\n",tid );
	pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{	pthread_t threads[THREADS];
	int status ,i;
	for (int i = 0; i < THREADS; ++i)
	{
		printf("Main Here ,creating Threads %d\n",i );

		//create threads
		status = pthread_create(&threads[i],NULL,sayHello,(void *)i);

		if(status !=0){
			printf("unable to create thread %d\n",status );
			exit(-1);
		}
		/* code */
	}
	exit(NULL);
	return 0;
}

