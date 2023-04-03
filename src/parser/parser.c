/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:15:57 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/03 11:57:45 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
parser creates cmd_tbls for each pipe
then checks cmd_tbls and returns 
true/false depending the input is good/bad
 */
bool	parser(t_shell *shell)
{
	char	**pipes;
	int		start;
	int		end;
	int		index;

	end = -1;
	start = 0;
	index = -1;
	pipes = split_with_pipes(shell->trimmed_prompt, start, end, index);
	shell->cmd_tbls = create_cmd_table(pipes, shell);
	free_char_array(pipes);
	return (table_check(shell->cmd_tbls));
}

/* 
table_check takes cmd_tbls as input
goes through the tables and checks redirs
if redirs have only redirection type tokens -> returns false;
if there is at least one WORD type token (file name) it returns true.
Double protection!
 */
bool	table_check(t_cmd_tbl *tables)
{
	t_token	*token;
	bool	result;

	result = FALSE;
	while (tables != NULL)
	{
		token = tables->redirs;
		if (token == NULL)
			result = TRUE;
		while (token != NULL)
		{
			if (token->type == WORD)
				return (TRUE);
			token = token->next;
		}
		tables = tables->next;
	}
	return (result);
}

/* 
split_with_pipes gets trimmed prompt as input (str)
and returns 2d array of chars. Each array is a separate pipe
this function is called once for each prompt call
We pass start, end and index to function to save space
start = 0, end = -1, index = -1; By default
 */
char	**split_with_pipes(char *str, int start, int end, int index)
{
	char	**tokens;
	char	*tmp;

	if (str == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * (count_pipes(str) + 1));
	if (tokens == NULL)
		return (p_err("%s%s\n", SHELL, MALLOC_FAIL), NULL);
	while (str[++end] != '\0')
	{
		end = skip_quotes(str, end);
		if (ft_strlen(str) > end && str[end] != '\0'
			&& str[end] == '|' && str[end - 1] != SQUOTE
			&& nb_esc_chars(str, end) % 2 == 0)
		{
			tmp = ft_strdup2(str, start, end);
			tokens[++index] = ft_strtrim(tmp, SPACES);
			free(tmp);
			start = end + 1;
		}
	}
	tmp = ft_strdup2(str, start, end);
	tokens[++index] = ft_strtrim(tmp, SPACES);
	tokens[++index] = NULL;
	return (free(tmp), tokens);
}

/* 
skip_quotes takes a trimmed prompt and index as input.
if str[index] is quote then it returns the index of
closing quote in the string
 */
int	skip_quotes(char *str, int index)
{
	int	quote;

	if (str[index] != SQUOTE && str[index] != DQUOTE)
		return (index);
	quote = str[index++];
	while (str[index] != quote
		&& nb_esc_chars(str, index) % 2 == 0)
	{
		if (str[index] == '\0')
			return (index);
		index++;
	}
	return (index);
}

/* 
count_pipes takes trimmed prompt
and counts pipes inside it and returns the count of pipes.
The function is needed to create 2d array of pipes
 */
int	count_pipes(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	if (str == NULL)
		return (1);
	while (str[++i] != '\0')
	{
		i = skip_quotes(str, i);
		if (ft_strlen(str) > i
			&& str[i] != '\0'
			&& str[i] == '|'
			&& nb_esc_chars(str, i) % 2 == 0)
			count++;
	}
	return (count + 1);
}
