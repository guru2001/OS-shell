#include "header.h"
void pip(char *command)
{
	char *c1[1024];
	char *token[1024];
	for(int q = 0 ; q < 1024 ; q++)
	{
		c1[q] = (char *)malloc(1024);
		token[q] = (char *)malloc(1024);
	}
	token[0] = strtok(command,"|");
	int a = 0;
	if(token[0] == NULL)
	{
			printf("Less number of commands\n");
			print();
			return;
	}
	while(token[a] != NULL)
	{	
		token[++a] = strtok(NULL,"|");
	}
	if( a == 1)
	{
		printf("Less number of commands\n");
		print();
		return;
	}
	int it = 0;
	int pipefd[2];
	// pipe(pipefd);
	int stdin,stdout;
	stdin = dup(0);
	stdout = dup(1);
	while(it < a)
	{

	//printf("sdsaddsa\n");
	// pid_t pid;
	// pid = fork();
	// printf("[%d]\n", pid);
	// if(pid < 0)
	// {
	// 	perror("Fork - pipe");
	// }
	// if(pid == 0)
	// {
	if(it == 0)
	{		
		printf("vacha1\n");
		pipe(pipefd);
		dup2(pipefd[1],1);
		close(pipefd[1]);
	}
	else if(it == 1)
	{
				printf("vacha\n");
		dup2(pipefd[0],0);
		close(pipefd[0]);
	}
	else 
	{
						printf("vacha2\n");
		dup2(pipefd[0],0);
		close(pipefd[0]);
		pipe(pipefd);
		
		dup2(pipefd[1],1);
		close(pipefd[1]);
	}
		c1[0] = strtok(token[it], " "); 
		int c1c = 0;
		while(c1[c1c] != NULL)
		{
		//printf("dasda\n");
		c1[++c1c] = strtok(NULL," "); 
		}
			process(c1,c1c);	
			pwd(c1,c1c);
			echo(c1,c1c);
			ls(c1,c1c);
			cd(c1,c1c,d1);
			pinfo(c1,c1c);
			seten(c1,c1c);
			unseten(c1,c1c);
			// printf("else\n");
			// if (execvp(c1[0],c1) < 0)
			// {
			// 	kill(getpid(),SIGTERM);
			// 	return;
			// }	

		if(dup2(stdout,1)<0)
			perror("stdout");
		// close(stdout);
		if(dup2(stdin,0)<0)
		perror("stdin");			
		// close(stdin);
		it++;
		printf("%d\n",it );	
	}
	print();
}