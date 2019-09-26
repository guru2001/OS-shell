#include "header.h"
void quit(char **command,int i)
{
	if(strcmp(command[0],"quit") == 0)
	{
		if(i > 1)
		{
			printf("Enter Correct Number of Arguements\n");
		}
		else {
			while(1)
			exit(0);
			}
	}
}