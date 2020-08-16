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

piping.c
.Implemented piping using one pipefd array of 2
.I duplicate stdin and stdout
.Then in 1st iteration write end is dup2 to stdout
.In last iteration read end is dup2 to stdin
.In all other iterations both dup2 occur
(This is done to transform output of 1 function to another function's input)
.In every iteration after reading or writing I bring back both stdin or stdout

redirection.c
.Assuming one output and input redirection at max
.First took cases onlu inp,only out(>> or >) and both
.Output case dup2 the stdout to file(for >> append is used while opening)
.Input case dup2 to stdin
.Both 1st stdin dup2 and then stdout dup2
.After every iteration it is stdin and stdout are restored back

piping + redirection
.I send it to pipe function,for implementation of commands send to redirection if it exists.

jobs.c
.Stored all bg processes pid into an array and printed the non negative values in array.
.Initialized with -2 and after exiting changing value in array to -2 as a flag

kjobs.c
.Iterate the array to get jobid number of non negative values to get pid
.Send signal using kill command 

bg.c
.Iterate to get the pid
.Send SIGCONT to the process

fg.c
.Iterate and get the pid 
.And wait till interrupt or completion

cronjob.c
.Assuming the input comes in the specified format
.Take -t and -p seconds as it occurs in the same place
.Send it to all commands inbuilt

ctrl + c
.signal --> SIGINT is sent when pressed which is handled by killing the present fg process

ctrl + z
.signal --> SIGTSTSP is sent when pressed which is handled by stopping the present fg process to bg
.Stored it into bg array

ctrl + d
.While taking input of fgets if NULL is returned an extra line is printed.

quit.c
.When quit is entered exit(0)
