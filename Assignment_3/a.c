// for(int q = 0;q < 1024;q++)
	// {
	// 	token[q] = (char *)malloc(1024);
	// }
	// token[0] = strtok(command,">");
	// int a = 0;
	// if(token[0] == NULL)
	// {
	// 		printf("Less number of commands\n");
	// 		print();
	// 		return;
	// }
	// while(token[a] != NULL)
	// {	
	// 	token[++a] = strtok(NULL,">");
	// }
	// for(int a=0;a<i;a++)
	// {
	// 	if(!strcmp(command[a],">") && a != i-1)
	// 	{
	// 	strcmp(out_file,command[a+1]);
	// 	com_out = a;
	// 	}
	// 	else if(!strcmp(command[a],"<") && a!=0)
	// 	{	
	// 	strcmp(in_file,command[a-1]);
	// 	com_in = a;
	// 	}
	// }

	// int fd_out,fd_in;
	// fd_in = open(in_file, O_WRONLY);
	
	// if(fd_in == -1) 
 //    {
 //      perror("Failed to open file");
 //    }

 //     if(dup2(0,fd_in) != 1)  // 0 refers to stdout
 //      perror("dup2 fail");

 //    close(fd_in);

	// fd_out = open(out_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);

 //    if(fd_out == -1) 
 //    {
 //      perror("Failed to open file");
 //    }

 //    if(dup2(fd_out, 1) != 1)  // 1 refers to stdout
 //      perror("dup2 fail");

 //    close(fd_out);
