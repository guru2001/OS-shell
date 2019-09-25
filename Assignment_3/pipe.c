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
	int op = 0;
	
	while(it < a)
	{
	int pipefd_o[2],pipefd_e[2];
	pid_t pid;
	if (it % 2 != 0)
	{
		pipe(pipefd_o); // for odd i
	}
	else
	{
		pipe(pipefd_e); // for even i
	}
	pid = fork();
	printf("[%d]\n", pid);
	if(pid < 0)
	{
		perror("Fork - pipe");
	}
	if(pid == 0)
	{
	if(it == 0)
	{
		dup2(pipefd_e[1],1);
	}
	else if(it == a - 1)
	{
		if(op)
		{
			dup2(pipefd_o[0],0);
		}
		else dup2(pipefd_e[0],0);

	}
	else if(!op)
	{
		dup2(pipefd_o[0],0);
		dup2(pipefd_e[1],1);
	}
	else
	{
		dup2(pipefd_e[0],0);
		dup2(pipefd_o[1],1);
	}
		c1[0] = strtok(token[it], " "); 
		int c1c = 0;
		while(c1[c1c] != NULL)
		{
		c1[++c1c] = strtok(NULL," "); 
		}
			// pwd(c1,c1c);
			// echo(c1,c1c);
			// ls(c1,c1c);
			// cd(c1,c1c,d1);
			// pinfo(c1,c1c);
			// seten(c1,c1c);
			// unseten(c1,c1c);	
			// printf("else\n");
			if (execvp(c1[0],c1) < 0)
			{
				kill(getpid(),SIGTERM);
				return;
			}	
	if (it == 0)
		{
			close(pipefd_e[1]);
		}
		else if(it == a - 1)
		{
			if(op)
			{
				close(pipefd_o[0]);
			}
			else
			{
				close(pipefd_e[0]);
			}
		}
		else
		{
			if(op)
			{
				close(pipefd_e[0]);
				close(pipefd_o[1]);
			}
			else
			{
				close(pipefd_o[0]);
				close(pipefd_e[1]);
			}
		}
	}
	waitpid(pid,NULL,0);
	op = !op;
	it++;		
	printf("asd\n");
	}
print();
}