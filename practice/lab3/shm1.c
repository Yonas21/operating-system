#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int segment_id;
	double *data;
	//allocate shared memory with the size of double
	segment_id = shmget(IPC_PRIVATE,sizeof(int),IPC_CREAT | 0666);//returns system generated id

	//check if it is created
	if(segment_id ==-1){
		printf("error of creating shared memory\n");
		exit(-1);
	} else{
		printf("shared memory created with id:%d\n",segment_id );
	}

	//attach shared memory to manipulated it
	data = shmat(segment_id,NULL,0);
	if(data ==(double *)-1){
		printf("failed to attach\n");
		exit(-1);
	}
	//put some data in shared memory
	*data = 1017;

	//detach the segment before we exit
	shmdt(data);
	return 0;
}