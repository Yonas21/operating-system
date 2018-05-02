
/*process creation for the parent and the child one 
*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	pid_t pid;
	//create the child process
	pid = fork();

	//checking for the process types
	if (pid <0)
	{
		//unable to create child process
		printf(stderr,"Fork Failed\n");
	}else if (pid ==0)
	{
		/* code */
		execlp("/bin/ls","ls",NULL);
	} else{
		//parent process
		wait(NULL); //wait for child process to complete
		printf("Child process Completed pid = %d \n",getpid());
	}

	return 0;
}
