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
| **access**			| `man access`		| `<unistd.h>`		| checks the access permissions
| **perror**			| `man perror`		| `<stdio.h>`		| look up the error message string corresponding to an error

<h2>New Functions</h2>

| Function				| Manual Page		| From lib			| Description
| :--					| :--				| :--				| :--
| **getenv**			|					|					| getting the value of variables from the env list
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
| **isatty**			| `man isatty`		| `<unistd.h>`		| determines if the file descriptor fd refers to a valid terminal
| **ttyname**			| `man ttyname`		| `<unistd.h>`		| gets the related device name of a file descriptor for which isatty() is true
| **ttyslot**			| `man ttyslot`		| `<unistd.h>`		| returns the name stored in a static buffer which will be overwritten on subsequent calls
| **ioctl**				| `man ioctl`		| `<sys/ioctl.h>`	| manipulates the underlying device parameters of special files
| **unlink**			| `man unlink`		| `<unistd.h>`		| deletes a name from the filesystem
| **sigaction**			| `man sigaction`	| `<signal.h>`		| assigns an action for a signal specified by sig
| **sigemptyset**		| `man sigemptyset`	| `<signal.h>`		| initializes a signal set to be empty
| **sigaddset**			| `man sigaddset`	| `<signal.h>`		| adds the specified signal signo to the signal set
| **tcsetattr**			| `man tcsetattr`	| `<termios.h>`		| setting the termios structure
| **tcgetattr**			| `man tcgetattr`	| `<termios.h>`		| getting the termios structure
| **tgetent**			| `man tgetent`		| `<curses.h>` `<term.h>`| loads the entry for name
| **tgetflag**			| `man tgetflag`	| `<curses.h>` `<term.h>`| gets the boolean entry for id, or zero if it is not available
| **tgetnum**			| `man tgetnum`		| `<curses.h>` `<term.h>`| gets the numeric entry for id, or -1 if it is not available
| **tgetstr**			| `man tgetstr`		| `<curses.h>` `<term.h>`| returns the string entry for id, or zero if it is not available
| **tgoto**				| `man tgoto`		| `<curses.h>` `<term.h>`| instantiates the parameters into the given capability
| **tputs**				| `man tputs`		| `<curses.h>` `<term.h>`| applies  padding  information  to the string str and outputs it
| **readline**			| 					| `<stdio.h>` `<readline/readline.h>` `<readline/history.h>`| will read a line from the terminal and return it, using prompt as a prompt
| **rl_clear_history**	| 					| `<stdio.h>` `<readline/readline.h>` `<readline/history.h>`| Clear the history list by deleting all of the entries
| **rl_on_new_line**	| 					| `<stdio.h>` `<readline/readline.h>` `<readline/history.h>`| Tell the update functions that we have moved onto a new (empty) line, usually after outputting a newline
| **rl_replace_line**	| 					| `<stdio.h>` `<readline/readline.h>` `<readline/history.h>`| Replace the contents of rl_line_buffer with text
| **rl_redisplay**		| 					| `<stdio.h>` `<readline/readline.h>` `<readline/history.h>`| Change what’s displayed on the screen to reflect the current contents of rl_line_buffer
| **add_history**		|					| `<stdio.h>` `<readline/readline.h>` `<readline/history.h>`| Saving the line into the history


<h1 align=center>TO DO</h1>
<h2 align=center>Mandatory</h2>

<h3>Getting a headache from deciding who does what :white_check_mark:</h3>
<h3>Using one global variable :white_check_mark:</h3>
<h3>Have a working history :white_check_mark:</h3>
<h3>Working relative or absolute PATH :white_check_mark:</h3>
<h3>Check for unclosed quotes :white_check_mark:</h3>
<h3>Handle ' and " so shell won't interpret with it's content :x::white_check_mark:</h3>
<h3>Working main loop with readline :white_check_mark:</h3>
<h3>Custom prompt with curr User and Dir :white_check_mark:</h3>
<h3>Working redirections as:</h3>
	<h3>< redirect output :x:</h3>
	<h3>> redirect input :x:</h3>
	<h3><< (heredoc) but doesn't have to update the history :white_check_mark:</h3>
	<h3>>> should redirect in append mode to the file :x:</h3>
<h3>Handle environment variables with expander :white_check_mark:</h3>
<h3>SIGNALS:</h3>
<h3>Handle ctrl-C, ctrl-D and ctrl-\ the way it works in bash:</h3>
	<h3>ctrl + c displays a new prompt :white_check_mark:</h3>
	<h3>ctrl + d exits the shell :white_check_mark:</h3>
	<h3>ctrl + \ does nothing :white_check_mark:</h3>
<h3>LEXER:</h3>
	<h3>heredoc arg :x:</h3>
	<h3>chechk valid operators :white_check_mark:</h3>
	<h3>tokenize the prompt using 4 different token type :white_check_mark:</h3>
<h3>EXPANDER:</h3>
	<h3>expand env variables :white_check_mark:</h3>
	<h3>Handle dollar+? (echo dollar+?) which should display the last exit code :white_check_mark:</h3>
<h3>PARSER:</h3>
	<h3>check for edge, error cases and what we dont have to handle :x:</h3>
<h3>EXECUTOR:</h3>
	<h3>check for valid commands after split while turning them into lowercase :x:</h3>
	<h3>split heredoc arg for execute :white_check_mark:</h3>
	<h3>split arguments to pass for execve :white_check_mark:</h3>
	<h3>Implement pipes :x:</h3>
<h3>Implement the followiung BUILTINS:</h3>
	<h3>echo with option -n :white_check_mark:</h3>
	<h3>cd with relative or absolute path :white_check_mark:</h3>
	<h3>pwd :white_check_mark:</h3>
	<h3>export :white_check_mark:</h3>
	<h3>unset :white_check_mark:</h3>
	<h3>env :white_check_mark:</h3>
	<h3>exit :white_check_mark:</h3>

<h2>Bonus? :sweat_smile: :gun:</h2>

<h3>implement && and || for priorities :x:</h3>
<h3>wildcards * should work for the current working directory :x:</h3>


</div>














