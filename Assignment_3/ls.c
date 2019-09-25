#include "header.h"
int che = 0;
void ls(char **command,int i)
{
	char dirname[1024];
	DIR *dir;
	struct dirent *d;
	if(strcmp(command[0],"ls") == 0 && strcmp(command[i-1],"&") != 0)
	{
		if(i==1)
		{		
			strcpy(dirname,".");
			dir=opendir(dirname);
			if(dir == NULL)
			{
				perror("Cannot find directory");
				exit(-1);
			}
			while(d=readdir(dir))
			{
				char check[1000] ;
				strcpy(check,d->d_name);
				//printf("%c\n",check[0]);
				if(check[0] != '.')
					printf("%s ", d->d_name);
			}
			printf("\n");	
			while ((closedir(dir) == -1) && (errno == EINTR)) ;

		}	
		else if(strcmp(command[1],"-a") == 0 && i <= 2 )
		{
			strcpy(dirname,".");
			dir=opendir(dirname);
			char buf[512];
			int i1 =0;
			if(dir == NULL)
			{
				perror("Cannot find directory");
				exit(-1);
			}
			while(d=readdir(dir))
			{
				printf("%s ", d->d_name);
			}
			while ((closedir(dir) == -1) && (errno == EINTR)) ;
			printf("\n");
		}
		else if(strcmp(command[1],"-l") == 0 && i<=2)
		{
			// printf("ocha boss\n");
			strcpy(dirname,".");
			dir=opendir(dirname);
			if(dir==NULL)
			{
				perror("Cannot find directory");
				exit(-1);
			}
			char buf[512];
			int i1 =0;
			int total = 0;
			while(d = readdir(dir))
			{
								struct stat fileInfo;
				if(stat (d->d_name , &fileInfo) == 0)
				{
					char check[1000];
					strcpy(check,d->d_name);
					if(check[0] == '.')
					continue;
					total = fileInfo.st_blocks + total;
				}
	
			}
			printf("total = %d\n",total/2);
			rewinddir(dir);
			while(d=readdir(dir))
			{
				char check[1000];
				strcpy(check,d->d_name);
				if(check[0] == '.')
					continue;
				struct stat fileInfo;
				if(stat (d->d_name , &fileInfo) == 0)
				{
	
					struct passwd * pInfo = getpwuid(fileInfo.st_uid);  //username
					struct group * gInfo = getgrgid(fileInfo.st_gid);  ///grpname
					sprintf(buf, "%s/%s", dirname,d->d_name);
					stat(buf, &fileInfo); ///stat file inf
					struct tm *foo; //time struct
					foo = localtime(&(fileInfo.st_mtime));
					printf( (S_ISDIR(fileInfo.st_mode)) ? "d" : "-");
					printf( (fileInfo.st_mode & S_IRUSR) ? "r" : "-");
					printf( (fileInfo.st_mode & S_IWUSR) ? "w" : "-");
					printf( (fileInfo.st_mode & S_IXUSR) ? "x" : "-");
					printf( (fileInfo.st_mode & S_IRGRP) ? "r" : "-");
					printf( (fileInfo.st_mode & S_IWGRP) ? "w" : "-");
					printf( (fileInfo.st_mode & S_IXGRP) ? "x" : "-");
					printf( (fileInfo.st_mode & S_IROTH) ? "r" : "-");
					printf( (fileInfo.st_mode & S_IWOTH) ? "w" : "-");
					printf( (fileInfo.st_mode & S_IXOTH) ? "x " : "- ");
					printf("%ld ",fileInfo.st_nlink); //hard links
					printf("%s %s ",pInfo->pw_name,gInfo->gr_name);
					printf("%zu ",fileInfo.st_size);  //storage space
					if(foo->tm_mon == 0) 
						printf("Jan "); 
					if(foo->tm_mon == 1)
						printf("Feb "); 
					if(foo->tm_mon == 2)
						printf("Mar "); 
					if(foo->tm_mon == 3)
						printf("Apr "); 
					if(foo->tm_mon == 4)
						printf("May "); 
					if(foo->tm_mon == 5)
						printf("Jun "); 
					if(foo->tm_mon == 6)
						printf("Jul "); 
					if(foo->tm_mon == 7)
						printf("Aug "); 
					if(foo->tm_mon == 8)
						printf("Sep "); 
					if(foo->tm_mon == 9)
						printf("Oct "); 
					if(foo->tm_mon == 10)
						printf("Nov "); 
					if(foo->tm_mon == 11)
						printf("Dec "); 
					printf("%d ", foo->tm_mday); 
					printf("%d:", foo->tm_hour);
					printf("%d ", foo->tm_min);
					printf("%s\n", d->d_name);
				}
			}


		}
		else if( strcmp(command[1],"-la") == 0 || strcmp(command[1],"-al") == 0 || ( !strcmp(command[1],"-l") && !strcmp(command[2],"-a")) || strcmp(command[1],"-al") == 0 || ( !strcmp(command[1],"-a") && !strcmp(command[2],"-l")))
		{	
			strcpy(dirname,".");
			dir=opendir(dirname);
			if(dir==NULL)
			{
				perror("Cannot find directory");
				exit(-1);
			}
			char buf[512];
			int i1 =0;
			int total = 0;
			while(d = readdir(dir))
			{
								struct stat fileInfo;
				if(stat (d->d_name , &fileInfo) == 0)
				{
					total = fileInfo.st_blocks + total;
				}
	
			}
			printf("total = %d\n",total/2);
			rewinddir(dir);
			while(d=readdir(dir))
			{
				struct stat fileInfo;
				
				if(stat (d->d_name , &fileInfo) == 0)
				{

					struct passwd * pInfo = getpwuid(fileInfo.st_uid);  //username
					struct group * gInfo = getgrgid(fileInfo.st_gid);  ///grpname
					sprintf(buf, "%s/%s", dirname,d->d_name);
					stat(buf, &fileInfo); ///stat file inf
					struct tm *foo; //time struct
					foo = localtime(&(fileInfo.st_mtime));
					printf( (S_ISDIR(fileInfo.st_mode)) ? "d" : "-");
					printf( (fileInfo.st_mode & S_IRUSR) ? "r" : "-");
					printf( (fileInfo.st_mode & S_IWUSR) ? "w" : "-");
					printf( (fileInfo.st_mode & S_IXUSR) ? "x" : "-");
					printf( (fileInfo.st_mode & S_IRGRP) ? "r" : "-");
					printf( (fileInfo.st_mode & S_IWGRP) ? "w" : "-");
					printf( (fileInfo.st_mode & S_IXGRP) ? "x" : "-");
					printf( (fileInfo.st_mode & S_IROTH) ? "r" : "-");
					printf( (fileInfo.st_mode & S_IWOTH) ? "w" : "-");
					printf( (fileInfo.st_mode & S_IXOTH) ? "x " : "- ");
					printf("%ld ",fileInfo.st_nlink); //hard links
					printf("%s %s ",pInfo->pw_name,gInfo->gr_name);
					printf("%zu ",fileInfo.st_size);  //storage space
					if(foo->tm_mon == 0) 
						printf("Jan "); 
					if(foo->tm_mon == 1)
						printf("Feb "); 
					if(foo->tm_mon == 2)
						printf("Mar "); 
					if(foo->tm_mon == 3)
						printf("Apr "); 
					if(foo->tm_mon == 4)
						printf("May "); 
					if(foo->tm_mon == 5)
						printf("Jun "); 
					if(foo->tm_mon == 6)
						printf("Jul "); 
					if(foo->tm_mon == 7)
						printf("Aug "); 
					if(foo->tm_mon == 8)
						printf("Sep "); 
					if(foo->tm_mon == 9)
						printf("Oct "); 
					if(foo->tm_mon == 10)
						printf("Nov "); 
					if(foo->tm_mon == 11)
						printf("Dec "); 
					printf("%d ", foo->tm_mday); 
					printf("%d:", foo->tm_hour);
					printf("%d ", foo->tm_min);
					printf("%s\n", d->d_name);
				}
			}
		}	

		else
		{
			if(strcmp(command[1],"~") == 0)
			strcpy(dirname,d1);	
			else strcpy(dirname,command[1]);
			dir=opendir(dirname);
			if(dir == NULL)
			{
				perror("Cannot find directory");
				return;
			}
			while(d=readdir(dir))
			{
				if(strcmp(d->d_name,".") && strcmp(d->d_name,"..") )
					printf("%s ", d->d_name);
			}
			printf("\n");	


		}

	}

}
