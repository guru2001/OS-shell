#include "header.h"
void pwd(char **command,int i)
{
	char cwd[1024];
	if(strcmp(command[0],"pwd") == 0)
	{
		if (!getcwd(cwd, sizeof(cwd)))
			perror("getcwd() error");
		else{
			printf("%s\n", cwd);
		}
	}
}