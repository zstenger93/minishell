/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:45:33 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/19 02:09:02 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define TRUE 1
# define FALSE 0
# define FAIL 999

# define SHELL "minishell: "

//OPERATORS
# define SQUOTE 39
# define DQUOTE 34

//OPEN
# define GIVE_PERM_WTH_RW 0644

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

//STDERRORS
# define FORK_ERROR "fork faild, no child has been created, we used protection"
# define UNAME_REMOVED "Username not found. Please stop f*ckin around."
# define UFILE_DELETED "Open failed: Username cannot be extracted."
# define MALLOC_FAIL "memory allocation failed"
# define CMD_NOT_FND "command not found"
# define INVALID_CMD "command not found"
# define TMA "too many arguments"
# define PIPE_ERROR "pipe failed"
# define HOMELESS "HOME not set"
# define DNE "does not exist."
# define PWNED "PWD not set"

#endif