/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:50:51 by msloot            #+#    #+#             */
/*   Updated: 2023/12/11 19:32:22 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "d03.h"

static void	pretty_print_symbol(char c)
{
	ft_putstr(SYM);
	ft_putchar(c);
	ft_putstr(DEF);
}

static void	pretty_print_number(
	t_engine *e, size_t y, size_t *x, bool is_engine_part)
{
	if (is_engine_part)
		ft_putstr(NUM);
	while (ft_isdigit(e->engine[y][*x]))
	{
		ft_putchar(e->engine[y][*x]);
		*x += 1;
	}
	if (is_engine_part)
		ft_putstr(DEF);
	*x -= 1;
}

static size_t	process(t_engine *e, size_t y, size_t *x)
{
	ssize_t	n;

	n = parse_engine_part(e, y, *x);
	if (n < 0)
	{
		pretty_print_number(e, y, x, false);
		return (0);
	}
	pretty_print_number(e, y, x, true);
	return (n);
}

size_t	solve(t_engine *e)
{
	size_t	ret;
	size_t	y;
	size_t	x;

	ret = 0;
	y = 0;
	while (y < e->size)
	{
		x = 0;
		while (e->engine[y][x] != '\0')
		{
			if (ft_isdigit(e->engine[y][x]))
				ret += process(e, y, &x);
			else if (is_symbol(e->engine[y][x]))
				pretty_print_symbol(e->engine[y][x]);
			else
				ft_putchar(e->engine[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
	return (ret);
}
