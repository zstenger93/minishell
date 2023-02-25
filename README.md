<h1 align="center">
	📖 MINISHELL
</h1>
<h2 align="center">
	<b><i>A project to introduce you to depression</a></a></i></b><br>
</h2>
<img src="https://www.freeiconspng.com/uploads/hd-pepe-png-transparent-background-4.png" width="350" alt="Hd Pepe Png Transparent Background" />













<div align=center>

| Function		| Manual Page		| From lib			| Description
| :--			| :--				| :--				| :--
| **printf**	| `man 3 printf`	| `<stdio.h>`		| write output to stdout
| **malloc**	| `man malloc`		| `<stdlib.h>`		| allocate dynamic memory
| **free**		| `man 3 free`		| `<stdlib.h>`		| free dynamic memory
| **read**		| `man 2 read`		| `<unistd.h>`		| read from a file descriptor
| **write**		| `man 2 write`		| `<unistd.h>`		| write to a file descriptor
| **open**		| `man 2 open`		| `<fcntl.h>`		| open and possibly create a file
| **close**		| `man 2 open`		| `<unistd.h>`		| close a file descriptor
| **fork**		| `man fork`		| `<unistd.h>`		| create a child process
| **wait**		| `man wait`		| `<sys/wait.h>`	| wait for process to change state
| **waitpid**	| `man waitpid`		| `<sys/wait.h>`	| wait for process to change state
| **wait3**		| `man wait3`		| `<sys/wait.h>`	| (obsolete) wait for process to change state, BSD style
| **wait4**		| `man wait4`		| `<sys/wait.h>`	| (obsolete) wait for process to change state, BSD style
| **signal**	| `man signal`		| `<signal.h>`		| ANSI C signal handling
| **kill**		| `man 2 kill`		| `<signal.h>`		| send signal to a process
| **exit**		| `man exit`		| `<stdlib.h>`		| cause normal process termination
| **getcwd**	| `man getcwd`		| `<unistd.h>`		| get current working directory
| **chdir**		| `man chdir`		| `<unistd.h>`		| change working directory
| **stat**		| `man 2 stat`		| `<sys/stat.h>`	| get file status by pathname
| **lstat**		| `man lstat`		| `<sys/stat.h>`	| get file status by pathname (for symlinks)
| **fstat**		| `man fstat`		| `<sys/stat.h>`	| get file status by fd
| **execve**	| `man execve`		| `<unistd.h>`		| execute program
| **dup**		| `man dup`			| `<unistd.h>`		| duplicate a file descriptor
| **dup2**		| `man dup2`		| `<unistd.h>`		| duplicate a file descriptor
| **pipe**		| `man pipe`		| `<unistd.h>`		| create pipe
| **opendir**	| `man opendir`		| `<dirent.h>`		| open a directory
| **readdir**	| `man readdir`		| `<dirent.h>`		| read a directory
| **closedir**	| `man closedir`	| `<dirent.h>`		| close a directory
| **strerror**	| `man strerror`	| `<string.h>`		| return string describing error number
| **errno**		| `man errno`		| `<errno.h>`		| number of last error
| **termcap**	| `man termcap`, `man termios`		| `<term.h>`		| direct curses interface to the terminfo capability database

_________________________________________________________________________________
|                               Used Previously                                 |
|_______________________________________________________________________________|
|                   printf, malloc, free, write, access exit                    |
|                    open, read, close, fork, wait, waitpid                     |
|                   dup, dup2, pipe, strerror, perror, execve                   |
|_______________________________________________________________________________|
|                                New Functions                                  |
|_______________________________________________________________________________|
|                getenv, tcsetattr, tcgetattr, tgetent, tgetflag                |
|                    tgetnum, tgetstr, tgoto, tputs, signal                     |
|                  readline, rl_clear_history, rl_on_new_line                   |
|                  rl_replace_line, rl_redisplay, add_history                   |
|                   sigaction, sigemptyset, sigaddset, kill                     |
|                  getcwd, chdir, stat, lstat, fstat, unlink                    |
|                       isatty, ttyname, ttyslot, ioctl                         |
|                   opendir, readdir, closedir, wait3, wait4                    |
|_______________________________________________________________________________|


<h2 align=center>TO DO</h2>
	<h3>
	Getting a headache from deciding who does what :white_check_mark:
	Using one global variable :x:
	Have a working history :x:
	Working relative or absolute PATH :x:
	Handle ' and " so shell won't interpret with it's content :x:
	Working redirections as:
		< redirect output :x:
		> redirect input :x:
		<< (heredoc) but doesn't have to update the history :x:
		>> should redirect in append mode to the file :x:
	Implement pipes :x:
	Handle environment variables :x:
	Handle $? (echo $?) which should display the last exit code :x:
	Handle ctrl-C, ctrl-D and ctrl-\ the way it works in bash
		ctrl + c displays a new prompt :x:
		ctrl + d exits the shell :x:
		ctrl + \ does nothing :x:
	Implement the followiung builtins:
		echo with option -n :x:
		cd with relative or absolute path :x:
		pwd :x:
		export :x:
		unset :x:
		env :x:
		exit :x:
	
	Bonus? :sweat_smile: :gun:

	implement && and || for priorities :x:
	wildcards * should work for the current working directory :x:
</h3>

</div>














