#include "header.h"
char d5[1024];
char *d1;
char *storage[21];
int st = 0;
int fd1;
char **coma;
int *pr;
void End_Spaces(char * str)
{
    int index = 1 , i = 0;
    while(str[i] != '\0')
    {
        if(str[i] != ' ' && str[i] != '\t' && str[i] != '\n')  //Finding last known character index
        {
            index= i;
        }

        i++;
    }
    str[index + 1] = '\0';
}
void Start_Spaces(char * str)
{
    int index = 0, i, j;
    while(str[index] == ' ' || str[index] == '\t' || str[index] == '\n') //Finding first known character index
    {
        index++;
    }
    if(index != 0)
    {
        i = 0;
        while(str[i + index] != '\0')       //Shifting
        {
            str[i] = str[i + index];
            i++;
        }
        str[i] = '\0'; 
    }
}
int main(int argc,char **argv)
{
	pr = (int *)malloc(1024*(sizeof(int)));
	coma = (char **)malloc(1024 * sizeof(char *)); 
	for(int m = 0;m < 1024;m++)
	{
		pr[m] = -2;
	}
	for(int x = 0;x<1024;x++)
	{
		coma[x] = (char *)malloc(1024); 
	}
	
	fd1 = open("history",O_CREAT | O_RDWR,0700);
	for(int i=0;i<21;i++)
	{
		storage[i] = (char*)malloc(1024*sizeof(char));
	}
	d1 = (char *)malloc(1024);
	int ch =0 ;
	while(1)
	{
		int sta;
 		int val = waitpid(-1,&sta,WNOHANG); 
        if(val > 0)
           	{
           		int m = 0;
           		for(m;m<1024;m++)
           		{
           			if(pr[m] == val)
           			break;
           		}

           		printf("\n%s with pid %d has finished\n",coma[m],pr[m]);
	        	pr[m] = -2;
	        	print();
	        }
	 	if(ch == 0)
		{
		ch++;
		char uname[1024],hname[1024],dir_name[1024];
		uname[1023] = '\0';
		hname[1023] = '\0';
		dir_name[1023] = '\0';
		getlogin_r(uname, sizeof(uname));
		gethostname(hname, sizeof(hname));
		//getcwd(d1, sizeof(d1));
		getcwd(dir_name, sizeof(dir_name));
		strcpy(d1,dir_name);
		char pwdir[1024];
		strcpy(pwdir,argv[0]);
		
		if(strlen(pwdir) >  8)
		{
			strcpy(&pwdir[strlen(pwdir) - 6],"\0");
			// *pwdir = *pwdir + 1;			{
			if(chdir(pwdir) < 0)
			perror("change");
			
			getcwd(d5, sizeof(d5));				
			strcpy(d1,d5);  //Root mama idi --a.out unna path
			chdir(dir_name);
			if(strlen(dir_name) < strlen(d1))
				printf("%s@%s:%s >",uname,hname,dir_name);
			else if(strlen(dir_name) == strlen(d1))
					{
						printf("%s@%s ~ >",uname,hname);
					}
			else 
			{

				if(strstr(dir_name,d1))
				{
					char path[1024];
					int x = 0;
					for(int i = strlen(d1) + 1 ; i < strlen(dir_name) ; i++)
					{
						path[x] = dir_name[i]; 
						x++;
					}
					path[x] = '\0';
					// printf("%s\n",path );
					printf("%s@%s: ~/%s >",uname,hname,path);

				}	

				else printf("%s@%s:%s >",uname,hname,d1);
			}
		}
		else printf("%s@%s ~ >",uname,hname);
		}
		char *command;
		command = (char *)malloc(1024);
		fgets(command, 1024, stdin);
		int red = 0;
		if(strcmp(command,"\n") == 0)
		{
			if(ch != 0)
			print();
			continue;
		}

		st = 1;
		strcpy(storage[st],command);
		write(fd1,storage[st],strlen(command));
		st++;
		if(st==21)
		{
			lseek(fd1,0,SEEK_SET);
			st = 1;
		}

		End_Spaces(command);
		Start_Spaces(command);
		
		if(strstr(command,"|"))
		{
			pip(command);
			continue;
		}
		char *token[1000];
		token[0] = strtok(command,";");
		int a=0,p3[100],p3c = 0,i=0;
		if(token[0] == NULL)
		{
			if(ch != 0)
			print();
			continue;
		}
		while(token[a] != NULL)
		{	
			token[++a] = strtok(NULL,";");
		}
		for(int c=0; c<a ;c++)
		{  	
			int f4 = 0;
			for(int l=0;l<strlen(token[c]);l++)
			{
				if((int)token[c][l] != 32)
				{
					f4 =1;
					break;
				}
			}
			if(f4 == 0)
			continue;
			char *token1[1000];
			token1[0] = strtok(token[c], " "); 
			i = 0;
			
			while(token1[i] != NULL)
			{
				token1[++i] = strtok(NULL," "); 
			}

			process(token1,i);
			pwd(token1,i);
			echo(token1,i);
			ls(token1,i);
			cd(token1,i,d1);
			pinfo(token1,i);
			history(token1,i,fd1,st);
			seten(token1,i);
			unseten(token1,i);
			jobs(token1,i);
			kjob(token1,i);
			overkill(token1,i);
		}
		print();
		
	}
}