#include "header.h"
void jobs(char **command,int i)
{
	
	if(strcmp(command[0],"jobs") == 0)
	{
		if(i >= 2)
	{
		printf("Please Enter Correct Number of Commands\n");
	}
		int print = 1;
		for(int q = 0; q < 1024;q++)
		{
	
			if(pr[q] != -2)
			{
				char path[1024];
				sprintf(path,"/proc/%d/stat",pr[q]);				
				int fd = open(path,O_RDONLY);
				if(fd < 0)
				{
					perror("p1");
				}
				char file[1000000];
				read(fd,file,1000000);
				char* tok = strtok(file, " "); 
  					int cnt = 1;
  					char status[20];
    			while (tok != NULL) 
    			{ 
    				cnt++;
        			tok = strtok(NULL, " "); 
        			if(cnt == 3)
        			{
        				if(strcmp(tok,"T") == 0)
        				strcpy(status,"Stopped");
        				else
        				strcpy(status,"Running");
        				break;
        			}

        		}

					printf("[%d] %s %s[%d]\n",print,status,coma[q],pr[q]);
					print++;
		
			}
		}


	}


}
