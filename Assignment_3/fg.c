#include "header.h"
void fg(char **command,int i)
{
	
	if(strcmp(command[0],"fg") == 0)
	{
		if(i != 2)
	{
		printf("Please Enter Correct Number of Commands\n");
		return;
	}
	int print = 0;
	int q = 0;
	int pid = -2;
	for(; q < 1024;q++)
	{
		int ch = atoi(command[1]);
		if(pr[q] != 2)
		{
		print++;
		int ch = atoi(command[1]);
		if(print == ch)
		{
		pid = pr[q];
			break;
		}
		}
	}
		if(pid == -2)
		{
			printf("No job id found\n");
			return;
		}
		else{
			int statu;
			kill(pid,SIGCONT);
		waitpid(pid,&statu,WUNTRACED);
		if(inte == 1)
		pr[q] = -2; 
		inte = 0;
		}
		
	}
}
