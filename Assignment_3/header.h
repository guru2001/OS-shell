#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<errno.h>
#include<stdlib.h>
#include<pwd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>
#include<grp.h>
#include<fcntl.h>
#include<limits.h>
#include<stdlib.h>
#include<sys/wait.h> 
#include<signal.h>
extern char *d1;
extern char **coma;
extern int *pr;
extern void jobs(char **command,int i);
extern void pwd(char **command,int i);
extern void echo(char **command,int i);
extern void ls(char **command,int i);
extern void cd(char **command,int i,char *d1);
extern void pinfo(char **command,int i);
extern void history(char **command,int i,int fd1,int sz);
extern void print();
extern void process(char **command,int i);
extern void pip(char *command);
extern void seten(char **command,int i);
extern void unseten(char **command,int i);
extern void kjob(char **command,int i);
extern void overkill(char **command,int i);