/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:45:33 by zstenger          #+#    #+#             */
/*   Updated: 2023/03/05 13:47:27 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define TRUE 1
# define FALSE 0

//OPERATORS
# define HEREDOC	"<<"
# define APPEND		">>"
# define INPUT		"<"
# define OUTPUT		">"
# define PIPE		"|"
# define SQUOTE		39
# define DQUOTE		34

//HEREDOC TYPE
# define HD_PIPE "\033[1;34mpipe heredoc> \033[0m"
# define HERE_DOC "\033[1;34mheredoc> \033[0m"

#endif