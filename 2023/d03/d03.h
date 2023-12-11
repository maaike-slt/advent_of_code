/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d03.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:14:56 by msloot            #+#    #+#             */
/*   Updated: 2023/12/11 18:57:19 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef D03_H
# define D03_H

# include "libft.h"

# define DEF	"\033[0m"

# define NUM	"\033[1;32m"
# define H_NUM	"\033[1;32;44m"

# define SYM	"\033[1;31m"

typedef struct s_engine
{
	char	**engine;
	size_t	size;
}	t_engine;

size_t	solve(t_engine *e);

ssize_t	parse_engine_part(t_engine *e, size_t y, size_t x);

bool	is_symbol(char c);

#endif
