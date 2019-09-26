#include "header.h"
void redirect(char *command)
{
	int stdoutCopy = dup(1);
	int stdinCopy = dup(0);
	char *c1[1024],*c2[1024];
	int inp = 0,out = 0,b = 0,t = 0;
	int fd1,fd2;
	char *token[1024];
	for(int i = 0;i<1024;i++)
	{
		token[i] = (char *)malloc(1024);
		c1[i] = (char *)malloc(1024);
		c2[i] =(char *)malloc(1024);
	}
	if(strstr(command,">") != NULL && strstr(command,">>") == NULL )
	{
		out = 1;
	}
	if(strstr(command,">>") != NULL)
	{
		t = 1;
	}
	if(strstr(command,"<") != NULL)
	{
		inp = 1;
	}
	if((inp == 1 && out == 1 )|| (inp == 1 && t == 1))
	{
		b = 1;
	}
	if(inp == 1 && out == 0 && t == 0)
	{
	token[1] = strtok(command,"<"); 	
	token[0] = strtok(NULL,"<");
	c1[0] = strtok(token[1], " "); 
		int c1c = 0;
		while(c1[c1c] != NULL)
		{
		c1[++c1c] = strtok(NULL," "); 
		}
		End_Spaces(token[0]);
		Start_Spaces(token[0]);
		fd2 = open(token[0],O_RDONLY);
		if(fd2 < 0)
		{
		printf("Error Reading the file\n");
		return;
		}
		if(dup2(fd2,0) != 0)
		{
			printf("Dup2 error\n");
				return;
		}

			process(c1,c1c);
			pwd(c1,c1c);
			echo(c1,c1c);
			ls(c1,c1c);
			cd(c1,c1c,d1);
			pinfo(c1,c1c);
			history(c1,c1c,fd1,st);
			seten(c1,c1c);
			unseten(c1,c1c);
			jobs(c1,c1c);
			kjob(c1,c1c);
			overkill(c1,c1c);
			quit(c1,c1c);
			bg(c1,c1c);	

			if(dup2(stdinCopy,0) != 0)
			{
			printf("Dup2 error\n");
			return;
			}
		

	}	
	if(inp == 0 && out == 1 && t == 0)
	{
	token[0] = strtok(command,">"); 	
	token[1] = strtok(NULL,">");
	End_Spaces(token[1]);
	Start_Spaces(token[1]);
		c1[0] = strtok(token[0], " "); 
		int c1c = 0;
		while(c1[c1c] != NULL)
		{
		c1[++c1c] = strtok(NULL," "); 
		}
			fd1 = open(token[1],O_CREAT|O_WRONLY|O_TRUNC,0644);
			if(fd1 < 0)
			{
			printf("Opening error\n");
			return;
			}
			if(dup2(fd1,1) != 1)
			{
				printf("Dup2 error\n");
				return;
			}
			process(c1,c1c);
			pwd(c1,c1c);
			echo(c1,c1c);
			ls(c1,c1c);
			cd(c1,c1c,d1);
			pinfo(c1,c1c);
			history(c1,c1c,fd1,st);
			seten(c1,c1c);
			unseten(c1,c1c);
			jobs(c1,c1c);
			kjob(c1,c1c);
			overkill(c1,c1c);
			quit(c1,c1c);
			bg(c1,c1c);	

			if(dup2(stdoutCopy,1) != 1)
			{
			printf("Dup2 error\n");
			return;
			}
	}
	else if(inp == 0 && out == 0 && t == 1)
	{
	token[0] = strtok(command,">>"); 	
	token[1] = strtok(NULL,">>");
	End_Spaces(token[1]);
	Start_Spaces(token[1]);
		c1[0] = strtok(token[0], " "); 
		int c1c = 0;
		while(c1[c1c] != NULL)
		{
		c1[++c1c] = strtok(NULL," "); 
		}
			fd1 = open(token[1],O_CREAT|O_WRONLY|O_APPEND,0644);
			if(fd1 < 0)
			{
				printf("Opening error\n");
				return;
			}
			if(dup2(fd1,1) != 1)
			{
			printf("Dup2 error\n");
			return;
			}
			process(c1,c1c);
			pwd(c1,c1c);
			echo(c1,c1c);
			ls(c1,c1c);
			cd(c1,c1c,d1);
			pinfo(c1,c1c);
			history(c1,c1c,fd1,st);
			seten(c1,c1c);
			unseten(c1,c1c);
			jobs(c1,c1c);
			kjob(c1,c1c);
			overkill(c1,c1c);
			quit(c1,c1c);
			bg(c1,c1c);	

			if(dup2(stdoutCopy,1) != 1)
			{
				printf("Dup2 error\n");
				return;
			}
	}
	else if(b && t == 1)
	{
		printf("dsasdsa\n");
		token[0] = strtok(command,">>"); 	//---command
		token[1] = strtok(NULL,">>");  //---outfile
		token[2] = strtok(token[0],"<"); 	
		token[3] = strtok(NULL,"<"); // infile
		printf("%s %s %s\n", token[0],token[1],token[3] );
		c1[0] = strtok(token[2], " "); 
		int c1c = 0;
		while(c1[c1c] != NULL)
		{
		c1[++c1c] = strtok(NULL," "); 
		}
		End_Spaces(token[3]);
		Start_Spaces(token[3]);
		fd2 = open(token[3],O_RDONLY);
		if(fd2 < 0)
		{
		printf("Error Reading the file\n");
		return;
		}
		if(dup2(fd2,0) != 0)
		{
			printf("Dup2 error\n");
				return;
		}
		fd1 = open(token[1],O_CREAT|O_WRONLY|O_APPEND,0644);
		if(fd1 < 0)
		{
			printf("Opening error\n");
			return;
		}
		if(dup2(fd1,1) != 1)
		{
		printf("Dup2 error\n");
		return;
		}
		printf("%d %d\n",fd1,fd2);
			process(c1,c1c);
			pwd(c1,c1c);
			echo(c1,c1c);
			ls(c1,c1c);
			cd(c1,c1c,d1);
			pinfo(c1,c1c);
			history(c1,c1c,fd1,st);
			seten(c1,c1c);
			unseten(c1,c1c);
			jobs(c1,c1c);
			kjob(c1,c1c);
			overkill(c1,c1c);
			quit(c1,c1c);
			bg(c1,c1c);	
			if(dup2(stdoutCopy,1) != 1)
			{
			printf("Dup2 error\n");
			return;
			}
			if(dup2(stdinCopy,0) != 0)
			{
			printf("Dup2 error\n");
			return;
			}

	}	

		
}