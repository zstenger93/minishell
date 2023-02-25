<h1 align="center">
	📖 MINISHELL
</h1>
<h2 align="center">
	<b><i>A project to introduce you to depression</a></a></i></b><br>
</h2>
<img src="https://www.freeiconspng.com/uploads/hd-pepe-png-transparent-background-4.png" width="350" alt="Hd Pepe Png Transparent Background" />













<div align=center>


<h2>Used previously</h2>

| Function				| Manual Page		| From lib			| Description
| :--					| :--				| :--				| :--
| **printf**			| `man 3 printf`	| `<stdio.h>`		| write output to stdout
| **malloc**			| `man malloc`		| `<stdlib.h>`		| allocate dynamic memory
| **free**				| `man 3 free`		| `<stdlib.h>`		| free dynamic memory
| **read**				| `man 2 read`		| `<unistd.h>`		| read from a file descriptor
| **write**				| `man 2 write`		| `<unistd.h>`		| write to a file descriptor
| **open**				| `man 2 open`		| `<fcntl.h>`		| open and possibly create a file
| **close**				| `man 2 open`		| `<unistd.h>`		| close a file descriptor
| **fork**				| `man fork`		| `<unistd.h>`		| create a child process
| **wait**				| `man wait`		| `<sys/wait.h>`	| wait for process to change state
| **waitpid**			| `man waitpid`		| `<sys/wait.h>`	| wait for process to change state
| **exit**				| `man exit`		| `<stdlib.h>`		| cause normal process termination
| **execve**			| `man execve`		| `<unistd.h>`		| execute program
| **dup**				| `man dup`			| `<unistd.h>`		| duplicate a file descriptor
| **dup2**				| `man dup2`		| `<unistd.h>`		| duplicate a file descriptor
| **pipe**				| `man pipe`		| `<unistd.h>`		| create pipe
| **strerror**			| `man strerror`	| `<string.h>`		| return string describing error number
| **errno**				| `man errno`		| `<errno.h>`		| number of last error
| **access**			|					|					|
| **perror**			|					|					|

<h2>New Functions</h2>

| Function				| Manual Page		| From lib			| Description
| :--					| :--				| :--				| :--
| **getenv**			|					|					|
| **wait3**				| `man wait3`		| `<sys/wait.h>`	| (obsolete) wait for process to change state, BSD style
| **wait4**				| `man wait4`		| `<sys/wait.h>`	| (obsolete) wait for process to change state, BSD style
| **signal**			| `man signal`		| `<signal.h>`		| ANSI C signal handling
| **kill**				| `man 2 kill`		| `<signal.h>`		| send signal to a process
| **getcwd**			| `man getcwd`		| `<unistd.h>`		| get current working directory
| **chdir**				| `man chdir`		| `<unistd.h>`		| change working directory
| **stat**				| `man 2 stat`		| `<sys/stat.h>`	| get file status by pathname
| **lstat**				| `man lstat`		| `<sys/stat.h>`	| get file status by pathname (for symlinks)
| **fstat**				| `man fstat`		| `<sys/stat.h>`	| get file status by fd
| **opendir**			| `man opendir`		| `<dirent.h>`		| open a directory
| **readdir**			| `man readdir`		| `<dirent.h>`		| read a directory
| **closedir**			| `man closedir`	| `<dirent.h>`		| close a directory
| **isatty**			| `man isatty`		|					|
| **ttyname**			| `man ttyname`		|					|
| **ttyslot**			| `man ttyslot`		|					|
| **ioctl**				| `man ioctl`		|					|
| **unlink**			| `man unlink`		|					|
| **sigaction**			| `man sigaction`	|					|
| **sigemptyset**		| `man sigemptyset`	|					|
| **sigaddset**			| `man sigaddset`	|					|
| **tcsetattr**			| `man tcsetattr`	|					|
| **tcgetattr**			| `man tcgetattr`	|					|
| **tgetent**			| `man tgetent`		|					|
| **tgetflag**			| `man tgetflag`	|					|
| **tgetnum**			| `man tgetnum`		|					|
| **tgetstr**			| `man tgetstr`		|					|
| **tgoto**				| `man tgoto`		|					|
| **tputs**				| `man tputs`		|					|
| **readline**			| `man readline`	|					|
| **rl_clear_history**	| `man rl_clear_history`|					|
| **rl_on_new_line**	| `man rl_on_new_line`|					|
| **rl_replace_line**	| `man rl_replace_line`	|					|
| **rl_redisplay**		| `man rl_redisplay`|					|
| **add_history**		| `man add_history`	|					|


<h1 align=center>TO DO</h1>
<h2 align=center>Mandatory</h2>

<h3>Getting a headache from deciding who does what :white_check_mark:</h3>
<h3>Using one global variable :x:</h3>
<h3>Have a working history :x:</h3>
<h3>Working relative or absolute PATH :x:</h3>
<h3>Handle ' and " so shell won't interpret with it's content :x:</h3>
<h3>Working redirections as:</h3>
	<h3>< redirect output :x:</h3>
	<h3>> redirect input :x:</h3>
	<h3><< (heredoc) but doesn't have to update the history :x:</h3>
	<h3>>> should redirect in append mode to the file :x:</h3>
<h3>Implement pipes :x:</h3>
<h3>Handle environment variables :x:</h3>
<h3>Handle $? (echo $?) which should display the last exit code :x:</h3>
<h3>Handle ctrl-C, ctrl-D and ctrl-\ the way it works in bash</h3>
	<h3>ctrl + c displays a new prompt :x:</h3>
	<h3>ctrl + d exits the shell :x:</h3>
	<h3>ctrl + \ does nothing :x:</h3>
<h3>Implement the followiung builtins:</h3>
	<h3>echo with option -n :x:</h3>
	<h3>cd with relative or absolute path :x:</h3>
	<h3>pwd :x:</h3>
	<h3>export :x:</h3>
	<h3>unset :x:</h3>
	<h3>env :x:</h3>
	<h3>exit :x:</h3>

<h2>Bonus? :sweat_smile: :gun:</h2>

<h3>implement && and || for priorities :x:</h3>
<h3>wildcards * should work for the current working directory :x:</h3>


</div>














