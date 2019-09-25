#include "header.h"
void kjob(char **command,int i)
{
	
	if(strcmp(command[0],"kjob") == 0)
	{
		if(i >= 4)
	{
		printf("Please Enter Correct Number of Commands\n");
		return;
	}
	int print = 1;
	int q = 0;
	for(; q < 1024;q++)
	{
		if(pr[q] != -2)
		{
		print++;
		}
		int ch = atoi(command[0]);
		if(ch == print)
		{
		break;
		}
	}	
		int pid = pr[q];
		int kil = atoi(command[1]);		
		if(kill(pid,kil) < 0)
		printf("Error in sending Signal\n");
		
		pr[q] = -2;
	}
}