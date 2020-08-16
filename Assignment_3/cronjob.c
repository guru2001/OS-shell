#include "header.h"
#include "header.h"
void cronjob(char **command,int i)
{
	if(strcmp(command[0],"cronjob") == 0)
	{
		if(i < 7)
		printf("Please Enter correct number of Arguements");
	
	char *send[1024];
	for(int r = 0;r < 1024;r++)
	{
	send[r] = (char *)malloc(1024);
	}

	 int cr = atoi(command[i - 1]);
	 int f = atoi(command[i - 3]);
	int command_end = 3;
	
	for(int check = 1;check<i;check++)
	{
		if(strcmp(command[check],"-t") == 0)
		{
				

			command_end = check;
			break;
		}
	}
	int r = 0;

	for(int a = 2;a < command_end;a++)
	{
		strcpy(send[r],command[a]);
		r++;
	}
	int pid;
	pid = fork();
	if(pid == 0)
	{
	while(cr)
	{
			sleep(f);
			printf("\n");
			process(send,r);
			pwd(send,r);
			echo(send,r);
			ls(send,r);
			cd(send,r,d1);
			pinfo(send,r);
			history(send,r,fd1,st);
			seten(send,r);
			unseten(send,r);
			jobs(send,r);
			kjob(send,r);
			overkill(send,r);
			quit(send,r);
			bg(send,r);
			fg(send,r);
			cr = cr - f;
	}
				kill(getpid(),SIGTERM);

	}
	if(pid < 0)
	printf("Error\n");
	}
}