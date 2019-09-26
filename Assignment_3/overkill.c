#include "header.h"
void overkill(char **command,int i)
{
	
	if(strcmp(command[0],"overkill") == 0)
	{
		if(i > 1)
	{
		printf("Please Enter Correct Number of Commands\n");
		return;
	}
	for(int q = 0; q < 1024;q++)
	{
		if(pr[q] != -2)
		{
		int pid = pr[q];	
		if(kill(pid,9) < 0)
		{
			printf("Signal not sent\n");
		}
		}
	}
	}
}