/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:45:33 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/12 13:07:01 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define TRUE 1
# define FALSE 0

//OPERATORS
# define SQUOTE		39
# define DQUOTE		34

//HEREDOC TYPE
# define HD_PIPE "\033[1;34mpipe heredoc> \033[0m"
# define HERE_DOC "\033[1;34mheredoc> \033[0m"

//PROMPT
	//ARROW GREEN
# define G_ARROW_SIGN "\033[1;32m➜  \033[38;5;75m"
	//ARROW RED
# define R_ARROW_SIGN "\033[1;31m➜  \033[38;5;75m"
# define SPACE_SIGN "\033[1;96m "
# define X_SIGN "\033[1;33m ✗ \033[0m"

//PARSE ERROR
# define SYNTAX_ERROR "minishell: syntax error near unexpected token"

#endif