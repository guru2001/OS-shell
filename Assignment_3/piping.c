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
	int stdin,stdout;
	stdin = dup(0);
	stdout = dup(1);
	while(it < a)
	{
	// int pidfd = fork();
	// if(pidfd == -1)
	// {
	// printf("Forkerror\n");
	// }
	// if(pidfd == 0)
	// {	
	if(it == 0)
	{		
		pipe(pipefd);
		dup2(pipefd[1],1);
		close(pipefd[1]);
	}
	else if(it == a-1)
	{
		dup2(pipefd[0],0);
		close(pipefd[0]);
	}
	else 
	{
		dup2(pipefd[0],0);
		close(pipefd[0]);
		
		pipe(pipefd);
		
		dup2(pipefd[1],1);
		close(pipefd[1]);
	}
		int red = 0;
		c1[0] = strtok(token[it], " "); 
		int c1c = 0;
		while(c1[c1c] != NULL)
		{
		if(strstr(c1[c1c],">") != NULL || strstr(c1[c1c],"<") != NULL || strstr(c1[c1c],">>") != NULL)
		{
			red++;
		}
		c1[++c1c] = strtok(NULL," "); 
		}
			if(!red)
			{
			process(c1,c1c);
			pwd(c1,c1c);
			echo(c1,c1c);
			ls(c1,c1c);
			cd(c1,c1c,d1);
			pinfo(c1,c1c);
			history(c1,c1c,fd1,st);
			seten(c1,c1c);
			unseten(c1,c1c);
			jobs(c1,c1c);
			kjob(c1,c1c);
			overkill(c1,c1c);
			quit(c1,c1c);
			bg(c1,c1c);
			}
		else
		{
			char com[1024];
			strcpy(com,c1[0]);
			for(int q = 1; q < c1c;q++)
			{
				strcat(com," ");
				strcat(com,c1[q]);
			}
			printf("%s\n",com);
			redirect(com);
		}
		if(dup2(stdout,1) < 0)
			perror("stdout");
		if(dup2(stdin,0) < 0)
		perror("stdin");			
		// }
		it++;
			// waitpid(pidfd,NULL,0);
	}

}