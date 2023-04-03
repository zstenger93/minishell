/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:45:33 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/03 09:17:41 by zstenger         ###   ########.fr       */
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
# define PIPE "|"
# define OPERATORS "|><"
# define REDIRECTIONS "><"
# define SPACES " \t\n\v\r\f"

//OPEN
# define GIVE_PERM_WTH_RW 0644

//TMP HEREDOC FILES
# define TMP_S "/tmp/heredoc"
# define TMP_E ".XXXXXX"

//HEREDOC TYPE
# define HD_PIPE "\033[1;34mpipe heredoc> \033[0m"
# define HERE_DOC "\033[1;34mheredoc> \033[0m"

//PROMPT
	//ARROW GREEN
# define G_ARROW_SIGN "\001\e[1m\e[32m\002\001\u279c\002  \001\e[1m\e[34m\002"
	//ARROW RED
# define R_ARROW_SIGN "\001\e[1m\e[31m\002\001\u279c\002  \001\e[1m\e[34m\002"
# define SPACE_SIGN "\001\033[1;96m\002 "
# define X_SIGN "\001\e[1m\e[33m\002 \001\u2718\002 \001\e[0m\002"

//PARSE ERROR
# define SYNTAX_ERROR "syntax error near unexpected token"
# define SYNTAX_ERROR_NEWLINE "syntax error near unexpected token `newline'"

//STDERRORS
# define FORK_ERROR "fork faild, no child has been created, we used protection"
# define UNAME_REMOVED "Username not found. Please stop f*ckin around."
# define UFILE_DELETED "Open failed: Username cannot be extracted."
# define PIPE_ERROR "pipe failed, the pipeline is broken"
# define MALLOC_FAIL "memory allocation failed"
# define CMD_NOT_FND "command not found"
# define INVALID_CMD "command not found"
# define NAR "numeric argument required"
# define NVI "not a valid identifier"
# define TMA "too many arguments"
# define HOMELESS "HOME not set"
# define PWNED "OLDPWD not set"
# define ISDIR "is a directory"
# define DNE "does not exist."
# define C_D "/usr/bin/cd"

#endif