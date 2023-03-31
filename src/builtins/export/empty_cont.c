/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_cont.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:08:31 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/31 19:13:01 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*empty_content_allocate(char *content)
{
	content = malloc(sizeof(char) * 2);
	content[0] = ' ';
	content[1] = '\0';
	return (content);
}
