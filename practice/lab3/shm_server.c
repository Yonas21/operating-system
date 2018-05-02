#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <stdlib.h>

#define SHMSZ 50
int main(int argc, char const *argv[])
{
	char c;
	int shm_id;
	key_t key;
	char *shm,*s;
	key = 1017;
	//create and check shared memory
	if((shm_id = shmget(key,SHMSZ,IPC_CREAT | 0666))<0){
		printf("shared memory creation error\n");
		exit(-1);
	}

	//now attach the memory for manipulation
	if ((shm = shmat(shm_id,NULL,0)) == (char *)-1){
		printf("shmat error\n");
		exit(-1);
	}
	
	//now stored some data things to shm.
	s = shm;
	for (c='a';c<='z';c++)
	{
		*s++ = c;
		*s = '\0';

	}

	//wait for the process to change the value
	while(*shm != '*')
		sleep(1);
	for (s= shm;*s != '\0';s++)
	{
		putchar(*s);
		putchar('\n');
		exit(0);
	}
	return 0;
}