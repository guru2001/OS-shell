#include "header.h"
void print(char **argv)
{
	   	// printf("ocha\n");
	   	char uname[1024],hname[1024];
		uname[1023] = '\0';
		hname[1023] = '\0';
		getlogin_r(uname, sizeof(uname));
		gethostname(hname, sizeof(hname));
		char d2[1024];
		getcwd(d2,sizeof(d2));
			
		if(strlen(d1) > strlen(d2))
		{
		printf("%s@%s:%s >",uname,hname,d2);
		}
		else if(strcmp(d1,d2) == 0)
		{
		printf("%s@%s: ~ >",uname,hname);
		}
		else 
			{

				if(strstr(d2,d1))
				{
					char path[1024];
					int x = 0;
					for(int i = strlen(d1) + 1 ; i < strlen(d2) ; i++)
					{
						path[x] = d2[i]; 
						x++;
					}
					path[x] = '\0';
					printf("%s@%s: ~/%s >",uname,hname,path);

				}	

				else printf("%s@%s:%s >",uname,hname,d2);
			}
	
	}

