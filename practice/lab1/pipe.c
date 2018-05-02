#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char *message = "This is a Message!!!";

int main(int argc, char const *argv[])
{
	char buf[1024];
	int fd[2];
	pipe(fd); //create pipe

	if(fork()!=0){
		//am parent
		write(fd[1],message,strlen(message)+1);
	} else{
		read(fd[0],buf,1024);
		printf("got from the parent %d\n",buf );
	}
	return 0;
}