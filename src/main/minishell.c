/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 08:34:36 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/05 15:01:47 by zstenger         ###   ########.fr       */
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
	t_minishell	*hell;

	how_to_use(argc);
	hell->env = create_env(env);

	// printf("%s=%s\n", hell->env->start, hell->env->content);
	// printf("%s=%s\n", hell->env->next->start, hell->env->next->content);
	

	shell.envp = copy_env(env);
	path.paths = ft_split(get_env(shell.envp), ':');
	shell.user = get_user(shell.envp);
	// int i = 0;
	// while (path.paths[i] != NULL)
	// {
	// 	printf("%s\n", path.paths[i]);
	// 	i++;
	// }
	shell_loop(shell.envp);
	free_char_array(shell.envp);
	free_char_array(path.paths);
	exit(EXIT_SUCCESS);
}

char	*get_user(char **env)
{
	int		i;
	char	*user;

	i = 0;
	while(env[i] != NULL)
	{
		if (ft_strncmp(env[i], "USER=", 5) == 0)
		{
			user = env[i] + 5;
			return (user);
		}
		i++;
	}
	return (user);
}