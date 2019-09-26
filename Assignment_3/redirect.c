#include "header.h"
void redirect(char *command,int i)
{
	
	int inp = 0,out = 0;
	char in_file[1024], out_file[1024];
	char *token[1024];
	if(strstr(command,">") != NULL)
	{
		out = 1;
	}
	if(strstr(command,"<") != NULL)
	{
		inp = 1;
	}
	if(inp == 1)
	{
	token[0] = strtok(command,"<"); 	
	}		
	else strcpy(token[0],command);
		printf("%s\n",token[0]);
	token[1] = strtok(NULL,"<");
	if(token[1] = NULL)
	{	
		token[2] = strtok(token[1],">");
	}
	token[3] = strtok(NULL,">");
	printf("%s %s %s\n",token[0],token[1],token[3]);
	// if(inp == 1 && inp1 != 0)
	// {
	// 	strcpy(in_file,command[inp1 -1]);
	// }

	// int out1 = i - 1;
	// for(out1 = i - 1; out1 >= 0;out1--)
	// {
	
	// }
	// if(out == 1 && out1 != 0)
	// {
	// 	strcpy(out_file,command[out1 + 1]);
	// }
	// int t = 0;
	// for(int c = inp1 + 1;c < out1;c++)
	// {
	// 	strcpy(token[t],command[c]);
	// 	printf("%s\n",token[t]);
	// 	t++;
	// }
	// printf("%s %s",in_file,out_file);


	
}