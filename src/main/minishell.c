/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 08:34:36 by zstenger          #+#    #+#             */
/*   Updated: 2023/02/28 13:57:49 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// int main(int argc, char **argv)
// {
// 	check this, check that
// 	bimbumbam
// 	wooow
// 	return(mybrain_please);
// }

int main(int argc, char **argv, char **env)
{
	t_path		path;
	t_minishell	shell;

	how_to_use(argc);
	shell.envp = copy_env(env);
	path.paths = ft_split(get_env(shell.envp), ':');
	int i = 0;
	while (path.paths[i] != NULL)
	{
		printf("%s\n", path.paths[i]);
		i++;
	}
	shell_loop(shell.envp);
	free_char_array(shell.envp);
	free_char_array(path.paths);
	exit(EXIT_SUCCESS);
}

void	shell_loop(char **env_path)
{
	t_path		path;
	t_prompt	prompt;

	terminal_prompt("startup");
	while (TRUE)
	{
		prompt.line = readline("");
		env_xprt_xt(env_path, prompt.line);
		lexer(prompt.line);
		free(prompt.line);
		terminal_prompt("in_loop");
	}
	clear_history();
	rl_clear_history();
}


void	env_xprt_xt(char **env_path, char *prompt)
{
	if (ft_strncmp(prompt, "env", 3) == 0 || ft_strncmp(prompt, "export", 6) == 0)
		print_env(env_path, prompt);
	if (ft_strncmp(prompt, "exit", 4) == 0)
	{
		free(prompt);
		ft_putendl_fd("exit", STDOUT_FILENO);
		//cleanup function
		clear_history();
		rl_clear_history();
		exit(EXIT_SUCCESS);
	}
	if(prompt[0] != '\0')
		add_history(prompt);
	else
		printf("\n");
}

void	terminal_prompt(char *type)
{
	if (ft_strncmp(type, "startup", 7) == 0)
		ft_printf(BOLD GREEN "➜  " CYAN "minishell" YELLOW " ✗ " C_END);
	else if (ft_strncmp(type, "in_loop", 7) == 0)
	{
		//0. ➜ at start				valid prompt -> green, bad promt -> red
		//1. get username			cyan
		//2. get current folder		blue
		//3. ✗ or % at the end		yellow
		ft_printf(BOLD GREEN "➜  " CYAN "minishell" YELLOW " ✗ " C_END);
	}
}

char	**copy_env(char **env)
{
	size_t i;
	int len;
	char **copy;
	
	i = 0;
	len = 0;
	while (env[len] != NULL)
		len++;
	copy = ft_calloc(sizeof(char *), len + 1);
	if (!copy)
		return (NULL);
	while (env[i] != NULL)
	{
		copy[i] = ft_strdup(env[i]);
		if (copy[i] == NULL)
		{
			free_char_array(copy);
			return(copy);
		}
		i++;
	}
	return (copy);
}

void	print_env(char **env_path, char *line)
{
	int		i;
	char	**split;

	i = 0;
	if (ft_strncmp(line, "env", 3) == 0)
	{
		while (env_path[i] != NULL)
		{
			printf("%s\n", env_path[i]);
			i++;
		}
	}
	else if (ft_strncmp(line, "export", 6) == 0)
	{
		while (env_path[i] != NULL)
		{
			split = ft_split(env_path[i], '=');
			printf("declare -x %s=\"%s\"\n", split[0], split[1]);
			free_char_array(split);
			i++;
		}
	}
}

char	*get_env(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}
