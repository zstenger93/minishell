<h1 align="center">
	📖 MINISHELL
</h1>
<h2 align="center">
	<b><i>A project to introduce you to depression</a></a></i></b><br>
</h2>
<img src="https://www.freeiconspng.com/uploads/hd-pepe-png-transparent-background-4.png" width="350" alt="Hd Pepe Png Transparent Background" />













<div align=center>

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

_TO DO:_

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

</div>














