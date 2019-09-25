#include "header.h"
void echo(char **command,int i)
{
	if(strcmp(command[0],"echo") == 0 && strcmp(command[i-1],"&") != 0)
	{
		for(int a=1;a<i;a++)
		{
		printf("%s ",command[a]);
		}	
		 printf("\n");
	}
}
