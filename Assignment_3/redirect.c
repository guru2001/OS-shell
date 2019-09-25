#include "header.h"
void redirect(char **command,int red,int i)
{
	
	char in_file[1024], out_file[1024];
	in_file = NULL;
	out_file = NULL;
	int com_out = 0,com_in = 0,in = 0,out = 0;
	if(!strcmp(command[i-1],">"))
	{
		perror("Less number of arguements");
	}
	if(!strcmp(command[0],"<"))
	{
		perror("Less number of arguements");
	}

	for(int a=0;a<i;a++)
	{
		if(!strcmp(command[a],">") && a != i-1)
		{
		strcmp(out_file,command[a+1]);
		com_out = a;
		}
		else if(!strcmp(command[a],"<") && a!=0)
		{	
		strcmp(in_file,command[a-1]);
		com_in = a;
		}
	}
	int fd_out,fd_in;
	fd_in = open(in_file, O_WRONLY);
	
	if(fd_in == -1) 
    {
      perror("Failed to open file");
    }

     if(dup2(0,fd_in) != 1)  // 0 refers to stdout
      perror("dup2 fail");

    close(fd_in);

	fd_out = open(out_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if(fd_out == -1) 
    {
      perror("Failed to open file");
    }

    if(dup2(fd_out, 1) != 1)  // 1 refers to stdout
      perror("dup2 fail");

    close(fd_out);

}