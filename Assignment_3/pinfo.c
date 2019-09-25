#include "header.h"
char status[1000],execute[100000],pin[1000000];
void pinfo(char **command,int i)
{
if(strcmp(command[0],"pinfo") == 0)
{
	int p;
	char pid[1000];
	if(i == 1)
	{
		p =  getpid();
			sprintf(pid,"%d",p);
	}
	else strcpy(pid,command[1]);
	printf("pid -- %s\n",pid);
	strcpy(status,"/proc/");
	strcat(status,pid);
	strcpy(execute,status);
	strcat(status,"/stat");//Has status information of the process.
	strcat(execute,"/exe"); /*this file is a symbolic link con‐
              taining the actual pathname of the executed command.  This
              symbolic link can be dereferenced*/
	int fd = open(status,O_RDONLY);
	if(fd < 0)
	{
		perror("p1");
	}
	char file[1000000];
	read(fd,file,1000000);
	char* tok = strtok(file, " "); 
  	int cnt = 1;
    while (tok != NULL) 
    { 
    	cnt++;
        tok = strtok(NULL, " "); 
        if(cnt == 3)
        printf("Process status -- %s\n",tok);
    	if(cnt == 23)
    	{
    	printf("Memory -- %s\n",tok);
    	break;
    	}
    }
	realpath(execute,pin);

	char ans[1024];
	if(strstr(pin,d1) != NULL)
	{
	strcpy(ans,"~");
	strcat(ans,&pin[strlen(d1)]);
	printf("Executable Path -- %s\n",ans);
	}
	else printf("Executable Path --%s\n",pin);
}

}
