/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:20:09 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/29 08:25:22 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	cd_tilde(t_shell *shell, char *folder_path)
{
	t_env	*home;
	char	*path;
	char	*tilde_trimmed;

	home = find_env_var(shell->env_head, "HOME");
	tilde_trimmed = ft_strtrim(folder_path, "~");
	path = ft_nm_strjoin(home->content, tilde_trimmed);
	if (chdir(path) == -1)
	{
		p_err("%scd: %s: %s\n", SHELL, path, strerror(errno));
		free(tilde_trimmed);
		free(path);
	}
	else
	{
		free(tilde_trimmed);
		free(path);
	}
}

void	cd_home(t_shell *shell)
{
	t_env	*hdr;

	hdr = find_env_var(shell->env_head, "HOME");
	if (!hdr)
	{
		shell->exit_code = 1;
		p_err("%scd: %s\n", SHELL, HOMELESS);
	}
	else if (ft_strlen(hdr->content) < 1)
		printf("\n");
	else if (chdir(hdr->content) == -1)
		p_err("%scd: %s: %s", SHELL, hdr->content, strerror(ENOENT));
}

void	cd_oldpwd(t_shell *shell)
{
	t_env	*old_pwd;
	t_env	*curr_pwd;

	if (shell->prev_prompt == NULL)
	{
		if (shell->print == TRUE)
		{
			curr_pwd = find_env_var(shell->env_head, "PWD");
			printf("%s\n", curr_pwd->content);
			return ;
		}
		return ;
	}
	old_pwd = find_env_var(shell->env_head, "OLDPWD");
	if (!old_pwd)
	{
		shell->exit_code = 1;
		p_err("%scd: %s: %s\n", SHELL, "OLDPWD", strerror(errno));
	}
	else if (old_pwd->content == NULL)
		printf("\n");
	else if (chdir(old_pwd->content) == -1)
		p_err("%scd: %s: %s\n", SHELL, old_pwd->content, strerror(errno));
	else if (shell->print == TRUE)
		printf("%s\n", old_pwd->content);
}

void	cd_forward(char *folder_path)
{
	if (chdir(folder_path) == -1)
		p_err("%scd: %s: %s\n", SHELL, folder_path, strerror(errno));
}

void	cd_back(char *dotdot, char *folder_path)
{
	if (ft_strcmp(dotdot, "..") == 1 && folder_path == NULL)
	{
		if (chdir(dotdot) == -1)
			;
	}
	else if (chdir(folder_path) == -1)
		p_err("%scd: %s: %s\n", SHELL, folder_path, strerror(errno));
}
