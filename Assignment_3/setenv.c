#include "header.h"
void seten(char **command,int i)
{
	if(strcmp(command[0],"setenv") == 0)
	{
	if(i == 1 || i > 3)
	{
	printf("Please enter correct number of arguements\n");
	}
	else if(i == 2)
	{
		char tmp[12] = {0X0};
		if(setenv(command[1],tmp,1) < 0)
		{
			printf("Error:Not correct env name\n");	
		}

	}
	else 
	{
		if(command[2][0] == '[' && command[2][strlen(command[2]) - 1] == ']')
		{
			command[2][strlen(command[2]) - 1] = '\0';
			strcpy(command[2],&command[2][1]);
		}

		if(setenv(command[1],command[2],2) < 0)
		{
			
			printf("Error:Not correct env name\n");
		}

	}
}
}