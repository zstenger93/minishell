/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_trim_n_edge_cases.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:45:47 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/26 12:21:45 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//TO BE CHECKED AND DELETED


bool	breaking_bad(const char *s1, size_t start, t_shell *shell)
{
	int	j;

	if (s1[5] == '-' && s1[6] == 'n' && ft_pf_strchr(SPACES, s1[7]) == NULL
		&& s1[7] != 'n')
	{
		shell->echo_flag = 1;
		return (TRUE);
	}
	if (s1[5] == '-' && s1[6] == 'n' && ft_pf_strchr(SPACES, s1[7]) == NULL
		&& s1[7] == 'n')
		if (no_space_after_n(s1, 7, shell) == TRUE)
			return (TRUE);
	if (s1[start] == '-' && s1[start + 1] == 'n' && s1[start + 2] == '-')
		return (TRUE);
	if (s1[start] == '-' && s1[start + 1] == 'n' && s1[start + 2] == 'n')
	{
		j = start + 2;
		while (s1[j] == 'n')
			j++;
		if (ft_pf_strchr(SPACES, s1[j]) == NULL)
			return (TRUE);
	}
	return (FALSE);
}

bool	no_space_after_n(const char *s1, int i, t_shell *shell)
{
	while (s1[i] == 'n')
		i++;
	if (ft_pf_strchr(SPACES, s1[i]) == NULL)
	{
		shell->echo_flag = 1;
		return (TRUE);
	}
	return (FALSE);
}
