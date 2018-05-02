#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <stdlib.h>

#define SHMSZ 50

int main(int argc, char const *argv[])
{
	int shm_id;
	key_t key;
	char *shm,*s;

	key = 1017;
	if ((shm_id =shmget(key,SHMSZ,IPC_CREAT | 0666))<0){
		printf("shmget error\n");
		exit(-1);
	}

	//attach to the memory for manipulation
	if ((shm = shmat(shm_id,NULL,0)) ==(char *)-1){
		printf("shmat error\n");
		exit(-1);
	}
	for (s=shm;*s != NULL;s++)
	{
		putchar(*s);
		putchar('\n');

		//change the character for inducating manipulation
		*shm = '*';
		exit(0);	
	}
	
	return 0;
}