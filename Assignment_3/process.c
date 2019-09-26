#include "header.h"
int a = 0,iter = 1,nv;
pid_t pid;
int pi =0;
char ans[1024];
void process(char **command,int i)
{

	if(strcmp(command[0],"ls") == 0 || strcmp(command[0],"cd") == 0 || strcmp(command[0],"pwd") == 0  || strcmp(command[0],"echo") == 0  || strcmp(command[0],"setenv") == 0  || strcmp(command[0],"unsetenv") == 0  || strcmp(command[0],"history") == 0 || strcmp(command[0],"pinfo") == 0 || strcmp(command[0],"jobs") == 0 || strcmp(command[0],"kjob") == 0 || strcmp(command[0],"overkill") == 0 || strcmp(command[0],"quit") == 0 || strcmp(command[0],"bg") == 0)
	return;
	int bg = 0,status,pid1;
	if(strcmp(command[i-1],"&") == 0 && i>=2)
	{		
		bg = 1;
		command[i-1] = NULL;
		strcpy(ans,command[0]);
	}
	
	pid = fork();
	if(pid < 0)
	{
		perror("fork");
		return;
	}
	else if(pid == 0)
	{	
		if(bg)
		{
			setpgid(0,0);
		}
		if (execvp(command[0],command) < 0) 
		{    	
			nv = 1;
			printf("No such command\n");
	    	return;
	    }	   
	}
	else if(!bg)
	{
		
		fg_pid = pid;
		strcpy(fg_proc,command[0]);
		for(int z = 1; z < i ; z++)
		{
			strcat(fg_proc," ");
			strcat(fg_proc,command[z]);
		}
		waitpid(-1,&status,WUNTRACED);
		fg_pid = -2;
		nv = 0;
		
	}
	else 
	{
		// if(nv)
		// {
		// kill(pid,9);
		// }
		if(!nv)
		{
		strcpy(coma[a],command[0]);
		for(int z = 1; z < i-1 ; z++)
		{
			strcat(coma[a]," ");
			strcat(coma[a],command[z]);
		}
		pr[a] = pid;
		a++;
		printf("[%d] %d\n",iter,pid);
		iter++;
		}
		nv = 0;	
	}

} 