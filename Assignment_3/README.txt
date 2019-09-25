SHELL:
->Run the command make to compile the files to get the executable file.

Makefile:
.All files to be compiled under gcc.

header.h
.Contains all the headers ,functions and two variables command and d1(~ 's absolute path).

disp.c
.A infinite while loop is run to take user input.
.Used getlogin_r to get username ,gethostname to get hostname
.Stored pwd in dir_name and ~'s path in d1(By chdir to the executable file directory)
.Compared dir_name and d1 for printing.
.Used End_Spaces and Start_Spaces to delete spaces in the command.
.Used strtok to tokenize for ; and " " b/w the commands.

pwd.c
.Implementation of pwd.
.Used getcwd() to get the absolute path of the present directory from system's root.

echo.c
.Implementation of echo
.printed everything except the first token of echo.

cd.c
.Implementation of cd
.Two types of input - absolute and relative path. Relative path change directory and for absolute path change ~ to d1 and chdir.
Base case cd -- change to d1

print.c
.Get pwd and we know d1.
.Comparing if both are equal print ~ 
.If length of pwd < d1 ,print pwd absolute path
.If length of pwd > d1 ,print ~/rel_path if d1 is substring of pwd or print pwd

pinfo.c
.getpid() to get pid if not mentioned.
.Iterarted in /proc/[pid]/stat file to get status and memory in 3rd and 23rd token of space separated file.
.realpath() to decrypt this symbolic link present in file /proc/[pid]/exe



ls.c
. no flag-- iterate in the present directory and print everything except files/directories starting with .(hidden)
. -a print every file and directory name while iterating
(Using struct dirent *d)
. -al or -la 
.Get every stat file info ..First add up size_blocks to get block_size
.Use getpwuid,getgrpid to get user and group names
.Use _nlinks to get number of hardlinks
.Use _mode to get octal permissions
.Use struct tm to get modifcation time
.Used rewinddir() to again start iterating after block size

process.c
.Created a process either fg or bg using fork() and got pid using getpid()
.Checked if last command in is & which results in bg process.
.Using Signal I am sending it to a function after the present function is finished to print pid of bg process.
.Used waitpid to get the status of the operation.
.WIFEXITED(status) when it is exited

hist.c
.Implemented history 
.written command length arguements in file
.read it 