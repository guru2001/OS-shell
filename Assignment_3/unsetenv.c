#include "header.h"
void unseten(char **command,int i)
{
	if(strcmp(command[0],"unsetenv") == 0)
	{

	
	if( i == 1)
	{
	printf("Please enter correct number of arguements\n");
	}
	else 
	{
		if(unsetenv(command[1]) < 0)
		{
			printf("Such var doesn't exists\n");
		}

	}
}

}
