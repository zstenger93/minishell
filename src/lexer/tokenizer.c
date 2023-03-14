/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:15:57 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/14 19:56:53 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"





t_token *create_node(char* data)
{
    t_token* node = malloc(sizeof(t_token));
    node->content = strdup(data);
    node->next = NULL;
    return node;
}

void add_node(t_token** head_ref, char* data)
{
    t_token* node = create_node(data);
    node->next = *head_ref;
    *head_ref = node;
}

void tokenizer(char *prompt)
{
    char* token;
    char* rest = prompt;
    int in_quotes = 0;
    char *tmp;
    t_token *head = NULL;

    tmp = NULL;
    while ((token = strtok_r(rest, " ", &rest)))
    {
        if (token[0] == '\'' || token[0] == '\"')
        {
            in_quotes = 1;
            tmp = ft_strdup(token + 1);
            while (!ft_pf_strchr(token, token[0]))
            {
                token = strtok_r(rest, " ", &rest);
                if (!token)
                {
                    printf("Missing closing quote.\n");
                    return;
                }
                tmp = ft_nm_strjoin(tmp, " ");
                tmp = ft_nm_strjoin(tmp, token);
            }
            tmp[ft_strlen(tmp) - 1] = '\0';
            add_node(&head, tmp);
            in_quotes = 0;
            tmp = NULL;
        }
        else
        {
            add_node(&head, token);
        }
    	printf("%s\n", head->content);
    }

}
















size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i = 0;

	while (s[i] != '\0')
	{
		if (ft_pf_strchr(accept, s[i]) == 0)
			break;
		++i;
	}
	return (i);
}


size_t  ft_strcspn(const char *s, const char *reject)
{
    int     i = 0;
    int     j = 0;

    while (s[i] != '\0')
    {
		j = 0;
        while (reject[j] != '\0')
        {
            if(s[i] == reject[j])
                return (i);
            j++;
        }
        i++;
    }
    return (i);
}

char	*ft_strtok_r(char *str, char const *sep, char **saveptr)
{
	char	*tok;

	if (str == NULL && *saveptr == NULL)
		return (NULL);
	if (str == NULL)
		tok = *saveptr;
	else
		tok = str;
	tok += ft_strspn(tok, sep);
	if (tok[0] == '\0')
	{
		*saveptr = NULL;
		return (NULL);
	}
	*saveptr = tok + ft_strcspn(tok, sep);
	*saveptr += ft_strspn(*saveptr, sep);
	tok[ft_strcspn(tok, sep)] = '\0';
	return (tok);
}





// void	print_token(t_token *tokens)
// {
// 	t_token	*curr;

// 	curr = tokens;
// 	while (curr->next != NULL)
// 	{
// 		printf("%s\n", curr->content);
// 		curr = curr->next;
// 	}
// }

// void	add_token(t_token **tokens, char *content)
// {
// 	t_token	*new;
// 	t_token	*curr;

// 	new = malloc(sizeof(t_token));
// 	new->content = content;
// 	new->next = NULL;
// 	if (*tokens == NULL)
// 	{
// 		*tokens = new;
// 		return ;
// 	}
// 	curr = *tokens;
// 	while (curr->next != NULL)
// 		curr = curr->next;
// 	curr->next = new;
// }
