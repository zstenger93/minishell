<h1 align="center">
	📖 MINISHELL
</h1>
<h2 align="center">
	<b><i>A project to introduce you to depression</a></a></i></b><br>
</h2>
<img src="https://www.freeiconspng.com/uploads/hd-pepe-png-transparent-background-4.png" width="350" alt="Hd Pepe Png Transparent Background" />

---

<img align=center src="https://github.com/zstenger93/minishell/blob/master/mindmap.png">

---

<div align=center>
<h1 align="center">Allowed Functions</h1>
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

---

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

---

<div align=center>
<h1 align=center> </h1>
<h1 align=center>Our approach to the project</h1>
<h1 align=center>Input</h1>
<h3 align=center>Check for valid input, and if so we return our beautiful error message and how to use the program</h3>

---

<h1 align=center>Init</h1>
<h3>Initialize everything what's needed in normal mode</h3>
<h3>Or initialize the envless mode and extract the username</h3>

---

<h1 align=center>Signals</h1>
<h3>We have signals in the main loop for interactive mode</h3>
<h3>Signals in parent</h3>
<h3>Signals in child</h3>

---

<h1 align=center>Prompt</h1>
<h2 align=center>Normal mode</h2>
<h3>Arrow at the start which changes between green and red depending on if the cmd has been executed or not</h3>
<h3>Username which changes depending on the user</h3>
<h3>Space in between with colors</h3>
<h3>Folder name which always showing the current folder where you are</h3>
<h3>The green X sign at the end</h3>

---

<h2 align=center>No env</h2>
<h3>Works the same way except one thing which is the username</h3>
<h3>Since we don't have User in this case in out env</h3>
<h3>During the make I create a file with the makefile and echo the username to the file</h3>
<h3>Then when we launch the program instead of env, I read the username from the file :)</h3>
<h3>In case you try to delete the username from the file to break it, the prompt will change to a message</h3>
<h3>If you try to delete the file itself, it changes to another message as well ^^</h3>

---

<h1 align=center>Readline</h1>
<h3>After reading the input we trim the spaces from start-end and pass it to lexer</h3>
<h3>If the input is not empty, or not the exact same as the previous one then we store it in the history</h3>

---

<h1 align=center>Lexer</h1>
<h3>Since we kinda mixed lexer with the parser we have barely left with some checks at our lexer part</h3>
<h3>We look for wrong chars at line[0] like pipe or at the very end</h3>
<h3>Checks for wrong redirs right before pipes and if the last char is redir</h3>
<h3>A few other basic check, like empty imput or empty strings etc</h3>

---

<h1 align=center>Parser</h1>
<h3>First we did split with pipes int tokens and assign them to different types</h3>
<h3>One pipe is one command table</h3>
<h3>On each command table we have following</h3>
<h3>Command</h3>
<h3>Arguments</h3>
<h3>Redirections</h3>
<h3>Index</h3>
<h3>heredoc filename</h3>
<h3>**char for comamnd arguments</h3>

---

<h1 align=center>Executor</h1>
<h3>First we look for wrong redirections again and heredocs on the main process</h3>
<h3>If there is a wrong redirections, we execute heredocs until the wrong redir, after, not and delete the temp files</h3>
<h3>If no wrong redir, we execute heredocs the normal way and save all the file names in a **char</h3>
<h3>Now we can go pipe, fork and execute</h3>
<h3>Either execute a simple command without pipes</h3>
<h3>Or execute on the pipeline</h3>
<h3>In the child process</h3>
<h3>We handle redirections</h3>
<h3>Check for builtins</h3>
<h3>Then execute commands</h3>
<h3>Here we check for either direct path</h3>
<h3>Or we loop trough the PATH if the command is there or not</h3>
<h3>In the parent process</h3>
<h3>Waiting untill the last child process is going to finish and get it's exit status</h3>
<h3>Exec builtins to update structs/path if it is necessary</h3>

---

</div>
<h1 align=center>TO DO</h1>
<h2 align=center>Mandatory</h2>

<h3>Getting a headache from deciding who does what :white_check_mark:</h3>

<h3>check for leaks :white_check_mark:</h3>
<h3>builtins executed in child process :white_check_mark:</h3>
<h3>delete unused code :white_check_mark:</h3>
<h3>fix norm :white_check_mark:</h3>

<h3>check redirections at start :white_check_mark:</h3>
<h3>check how is awk being splitted for args :white_check_mark:</h3>
<h3>assign the correct exit codes :white_check_mark:</h3>
<h3>wexitstatus function for exit code :white_check_mark:</h3>
<h3>fix segfault problems with first cmd :white_check_mark:</h3>
<h3>set the executed variable for prompt at executions :white_check_mark:</h3>
<h3>make sure special chars are being ignored or causing errors when its needed :white_check_mark:</h3>
<h3>check thru while running wtihout env :white_check_mark:</h3>
<h3>when no env, might store the user in struct and not in ENV :white_check_mark:</h3>
<h3>execute builtins in child if they are called in pipes :white_check_mark:</h3>

<h3>Using one global variable :white_check_mark:</h3>
<h3>Be able to run without environment :white_check_mark:</h3>
<h3>Have a working history :white_check_mark:</h3>
<h3>Working relative or absolute PATH :white_check_mark:</h3>
<h3>Check for unclosed quotes :white_check_mark:</h3>
<h3>Handle ' and " so shell won't interpret with it's content :white_check_mark:</h3>
<h3>Working main loop with readline :white_check_mark:</h3>
<h3>Custom prompt with curr User and CWD :white_check_mark:</h3>
<h3>Working redirections as:</h3>
	<h3>< redirect output :white_check_mark:</h3>
	<h3>> redirect input :white_check_mark:</h3>
	<h3><< (heredoc) but doesn't have to update the history :white_check_mark:</h3>
	<h3>>> should redirect in append mode to the file :white_check_mark:</h3>
	<h3> do not create or do anything in case of error in redirs :white_check_mark:</h3>
	<h3> only execute heredocs but only until the faulty redir and return prompt :white_check_mark:</h3>
	<h3>exapand variables in heredoc :white_check_mark:</h3>
	<h3>execute heredocs before anything else :white_check_mark:</h3>
<h3>Handle environment variables with expander :white_check_mark:</h3>
<h3>SIGNALS:</h3>
<h3>Handle ctrl-C, ctrl-D and ctrl-\ the way it works in bash:</h3>
	<h3>ctrl + c displays a new prompt :white_check_mark:</h3>
	<h3>ctrl + d exits the shell :white_check_mark:</h3>
	<h3>ctrl + \ does nothing :white_check_mark:</h3>
	<h3>they shouldn't print anything on the line when received :white_check_mark:</h3>
<h3>LEXER:</h3>
	<h3>heredoc arg :white_check_mark:</h3>
	<h3>chechk valid operators :white_check_mark:</h3>
	<h3>tokenize the prompt using 4 different token type :white_check_mark:</h3>
	<h3>protect aginst valid special chars which aren't supposed to be handled :white_check_mark:</h3>
	<h3>splitting by pipes. one pipe = one table :white_check_mark:</h3>
<h3>EXPANDER:</h3>
	<h3>expand env variables :white_check_mark:</h3>
	<h3>only expand when we supposed to (' and ".....) :white_check_mark:</h3>
	<h3>Handle dollar+? (echo dollar+?) which should display the last exit code :white_check_mark:</h3>
<h3>PARSER:</h3>
	<h3>create the command table :white_check_mark:</h3>
	<h3>organize the table as follows:</h3>
	<h3>command on *char :white_check_mark:</h3>
	<h3>arguments for the command with type and content option :white_check_mark:</h3>
	<h3>arguments converted to **char for execve :white_check_mark:</h3>
	<h3>redirections with type and content option :white_check_mark:</h3>
	<h3>check for edge, error cases and what we dont have to handle :white_check_mark:</h3>
<h3>EXECUTOR:</h3>
	<h3>turn builtins which accepted with uppercase letters as well into lowercase :white_check_mark:</h3>
	<h3>split redir args for execute :white_check_mark:</h3>
	<h3>get arguments on **char to pass for execve :white_check_mark:</h3>
	<h3>Execute simple cmd without pipes :white_check_mark:</h3>
	<h3>Execute on pipeline :white_check_mark:</h3>
<h3>Implement the followiung BUILTINS:</h3>
	<h3>echo with option -n :white_check_mark:</h3>
	<h3>cd with relative or absolute path :white_check_mark:</h3>
	<h3>pwd :white_check_mark:</h3>
	<h3>export :white_check_mark:</h3>
	<h3>unset :white_check_mark:</h3>
	<h3>env :white_check_mark:</h3>
	<h3>exit :white_check_mark:</h3>

<h2>Bonus? :sweat_smile: :gun:</h2>

<h3>implement (), && and || for priorities :x:</h3>
<h3>wildcards * should work for the current working directory :x:</h3>


</div>














