/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:44:38 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/03 11:11:52 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	nb_delimited_words(char *s, char c)
{
	int	boo;
	int	count;
	int	index;

	boo = 0;
	index = 0;
	count = 0;
	while (s[index] != '\0')
	{
		if (s[index] == c)
			boo = 0;
		else if (s[index] != c && boo == 0)
		{
			count++;
			boo = -1;
		}
		index++;
	}
	return (count);
}

bool	strcmp_2(char *str1, char *str2)
{
	int		i;

	i = 0;
	if (str1 == NULL || str2 == NULL)
		return (FALSE);
	if (ft_strlen(str1) != ft_strlen(str2))
		return (FALSE);
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	update_pwd_and_oldpwd(t_shell *shell, char *old_pwd)
{
	char	*new_pwd;
	char	*pwd_join;
	char	*old_pwd_join;
	char	path[PATH_MAX];
	int		save_code;

	add_oldpwd_to_env(shell);
	save_code = shell->exit_code;
	new_pwd = getcwd(NULL, sizeof(path));
	pwd_join = ft_nm_strjoin("PWD=", new_pwd);
	old_pwd_join = ft_nm_strjoin("OLDPWD=", old_pwd);
	replace_var_content(shell, old_pwd_join, "OLDPWD");
	replace_var_content(shell, pwd_join, "PWD");
	shell->exit_code = save_code;
	free(old_pwd_join);
	free(pwd_join);
	free(new_pwd);
}

void	add_oldpwd_to_env(t_shell *shell)
{
	if (find_env_var(shell->env_head, "OLDPWD") == 0)
		add_new_variable(shell, "OLDPWD");
}

void	cd_slash_is_first_cmd(t_shell *shell)
{
	if (shell->print == TRUE)
		p_err("%scd: %s\n", SHELL, PWNED);
	shell->exit_code = 1;
}
