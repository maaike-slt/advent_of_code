/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:50:51 by msloot            #+#    #+#             */
/*   Updated: 2023/12/06 20:00:20 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define DEF "\033[0m"

#define NUM	"\033[1;32m"
#define H_NUM "\033[1;32;44m"

#define SYM	"\033[1;31m"

bool	is_symbol(char c)
{
	return (!ft_isalnum(c) && c != '.');
}

void	pretty_print(char c)
{
	if (is_symbol(c))
	{
		ft_putstr(SYM);
		ft_putchar(c);
		ft_putstr(DEF);
	}
	else if (ft_isdigit(c))
	{
		ft_putstr(NUM);
		ft_putchar(c);
		ft_putstr(DEF);
	}
	else
		ft_putchar(' ');
}

size_t	solve(char *engine[], size_t size)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (engine[x][y] != '\0')
		{
			pretty_print(engine[x][y]);
			y++;
		}
		ft_putchar('\n');
		x++;
	}
	return (0);
}
