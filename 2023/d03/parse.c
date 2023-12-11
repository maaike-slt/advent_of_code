/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:11:20 by msloot            #+#    #+#             */
/*   Updated: 2023/12/11 19:19:03 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "d03.h"

bool	is_symbol(char c)
{
	return (!ft_isdigit(c) && c != '.' && c != '\0');
}

static bool	has_symbol_around(t_engine *e, size_t y, size_t x)
{
	if (y > 0 && x > 0 && is_symbol(e->engine[y - 1][x - 1]))
		return (true);
	else if (y > 0 && is_symbol(e->engine[y - 1][x]))
		return (true);
	else if (y > 0 && is_symbol(e->engine[y - 1][x + 1]))
		return (true);
	else if (x > 0 && is_symbol(e->engine[y][x - 1]))
		return (true);
	else if (is_symbol(e->engine[y][x + 1]))
		return (true);
	else if (y < e->size - 1 && x > 0 && is_symbol(e->engine[y + 1][x - 1]))
		return (true);
	else if (y < e->size - 1 && is_symbol(e->engine[y + 1][x]))
		return (true);
	else if (y < e->size - 1 && is_symbol(e->engine[y + 1][x + 1]))
		return (true);
	else
		return (false);
}

ssize_t	parse_engine_part(t_engine *e, size_t y, size_t x)
{
	ssize_t	ret;
	bool	has_symbol;

	has_symbol = false;
	ret = 0;
	while (ft_isdigit(e->engine[y][x]))
	{
		ret *= 10;
		ret += e->engine[y][x] - '0';
		if (has_symbol_around(e, y, x))
			has_symbol = true;
		x++;
	}
	if (has_symbol)
		return (ret);
	return (-1);
}
