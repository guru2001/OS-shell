#include "header.h"
void kjob(char **command,int i)
{
	
	if(strcmp(command[0],"kjob") == 0)
	{
		if(i != 3)
	{
		printf("Please Enter Correct Number of Commands\n");
		return;
	}
	int print = 0;
	int q = 0;
	int pid = -2;
	for(; q < 1024;q++)
	{
		if(pr[q] != -2)
		{
		print++;
		int ch = atoi(command[1]);
		if(ch == print)
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
		int kil = atoi(command[2]);	
		if(kill(pid,kil) < 0)
		printf("Error in sending Signal\n");

	}
}