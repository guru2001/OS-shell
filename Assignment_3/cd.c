#include "header.h"
void cd(char **command,int i,char *d1)
{

if(strcmp(command[0],"cd") == 0  && strcmp(command[i-1],"&") != 0)
{
	if(i==1)
	{
	chdir(d1);
	}
	else if(command[1][0] == '~')
	{
		char d3[1024],d6[1024];
		strcpy(d3,d1);
		strcat(d3,&command[1][1]);
		if(chdir(d3) < 0)
		perror("d3");
	}

	else {
		//printf("%s\n",command[1]);
		if(chdir(command[1])<0)
		{
			perror("d");
			return;
		}
		
	}

}
}
