#include "header.h"

void history(char **command,int i,int fd1,int sz)
{
	if(strcmp(command[0],"history") == 0)
	{
	char buffer[1000000];
	lseek(fd1,0,SEEK_SET);
	if(i == 1)
	{
		read(fd1,buffer,10 * 1024);
		printf("%s\n",buffer);
	}
	else {
			int len = atoi(command[1]);
			read(fd1,buffer,len*1024);
			printf("%s\n",buffer);
	}
	lseek(fd1,sz-1 *1024,SEEK_SET);
}
}