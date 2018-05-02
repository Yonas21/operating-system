#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

void *isdivisible(void *ptr){
	printf("Enter the smaller Number:");
	int smaller,larger;
	scanf("%d",&smaller);
	int otherNumber  = smaller+250;
	for(int i = 0;i<otherNumber;i++){
		int finalResult = otherNumber/17;
		if(otherNumber/17 ==0){
			printf("otherNumber :%d is divisible\n",otherNumber );
		}
		else{
			printf("number %d id indivisible\n",otherNumber);
		}
	}
}

int main(){
	int threadid,status;//declaring the variables for status and thread attributes.
	//thread one
	pthread_create(&threadid,NULL,isdivisible,NULL);
	pthread_exit(&status);
	//thread two
	pthread_create(&threadid,NULL,isdivisible,NULL);
	pthread_exit(&status);
	//thread three
	pthread_create(&threadid,NULL,isdivisible,NULL);
	pthread_exit(&status);
	//thread four
	pthread_create(&threadid,NULL,isdivisible,NULL);
	pthread_exit(&status);
	//exit after finish
	exit(-1);
}