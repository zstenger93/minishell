/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:43:20 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/18 21:55:28 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//check for cd ~/path
//FIX cd - if it's the first command. SHOULDN'T BE OLDPWD at STARTUP
void	cd(t_shell *shell)
{
	char	**split;
	t_env	*old_pwd;
	char	*old_pwd_content;

	old_pwd = find_env_var(shell->env_head, "PWD");
	old_pwd_content = old_pwd->content;
	split = ft_split(shell->trimmed_prompt, ' ');
	if (split[1] == NULL || strcmp_2(split[1], "~" ) == TRUE)
		cd_home(shell);
	else if (strcmp_2(split[1], "-" ) == TRUE)
		cd_oldpwd(shell);
	else if (split[2] == NULL && split[1] != NULL
		&& ft_strcmp(split[1], "..") != 1)
		cd_forward(split[1]);
	else if (ft_strcmp(split[1], "..") == 1
		|| (ft_strcmp(split[1], "..") == 1 && split[2] != NULL))
		cd_back(split[1], split[2]);
	free_char_array(split);
	update_pwd_and_oldpwd(shell, old_pwd->content);
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
		printf("");
	else if (chdir(hdr->content) == -1)
		p_err("%scd: %s: %s", SHELL, hdr->content, strerror(ENOENT));
}

void	cd_oldpwd(t_shell *shell)
{
	t_env	*old_pwd;

	old_pwd = find_env_var(shell->env_head, "OLDPWD");
	if (!old_pwd)
	{
		shell->exit_code = 1;
		p_err("%scd: %s: %s\n", SHELL, "OLDPWD", strerror(errno));
	}
	if (old_pwd->content == NULL)
		printf("\n");
	else if (chdir(old_pwd->content) == -1)
		p_err("%scd: %s: %s\n", SHELL, old_pwd->content, strerror(errno));
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
