/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 08:34:36 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/02 17:49:04 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	*read_line2(t_shell *shell);
void	shell_loop2(t_shell *shell);

void	free_at_exit2(t_shell *shell);

int	*read_line2(t_shell *shell)
{
	char	*line;

	shell->exec_on_pipe = FALSE;
	shell->should_execute = FALSE;
	shell->trimmed_prompt = ft_strtrim(shell->prompt, SPACES);
	if (shell->prompt == NULL)
		return (NULL);
	return ((void *)1);
}

void	shell_loop2(t_shell *shell)
{
	while (TRUE)
	{
		// signals(&shell->mirror_termios);
		// terminal_prompt(shell);
		// if (read_line2(shell) == NULL)
		// 	break ;
		// update_env(shell);
		if (lexer(shell) == TRUE && parser(shell) == TRUE)
			execute(shell, shell->cmd_tbls);
		// addhistory(shell);
		break ;
	}
}

int	main2(int argc, char *argv, char **env)
{	
	t_shell	shell;

	// atexit(&leaks);
	// how_to_use(argc);
	init_shell(&shell, env);
	shell.prompt = ft_strdup(argv);
	shell.trimmed_prompt = ft_strtrim(shell.prompt, SPACES);
	shell_loop2(&shell);
	free_at_exit2(&shell);
	free(shell.prompt);
	return (shell.exit_code);
}

void	free_at_exit2(t_shell *shell)
{
	t_token	*token;

	// if (shell->print == FALSE)
	// 	printf("exit\n");
	if (shell->trimmed_prompt != NULL)
		free_cmd_tbls(shell->cmd_tbls);
	free_char_array(shell->cmd_paths);
	// free(shell->terminal_prompt);
	free(shell->trimmed_prompt);
	free_char_array(shell->env);
	free_env(shell->env_head);
	free(shell->prev_prompt);
	free(shell->heredoc);
	// free(shell->prompt);
	rl_clear_history();
}




// argv[2] will contains the content of the line for example "echo something ; ls -la" 
int main(int argc, char **argv, char **env)
{
  // Your code...
  if (argc >= 3 && !ft_strncmp(argv[1], "-c", 3))
  {
    int exit_status = main2(argc, argv[2], env);
    exit(exit_status);
  }
    // Above this is the function that normally launch your minishell, instead 
    // of reading line with a get_next_line or a read() on fd 0, you just have to get
    // the argv[2] (which contains the content) and execute it.
    // Your function should return the good exit status otherwise the tests may be considered as false.
  // Your code ...
}