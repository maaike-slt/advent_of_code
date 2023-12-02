/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:50:51 by msloot            #+#    #+#             */
/*   Updated: 2023/12/02 16:59:41 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "d02.h"

bool	is_game_possible(t_cubes game)
{
	if (game.red > 12 || game.gre > 13 || game.blu > 14)
		return (false);
	return (true);
}

size_t	solve(t_cubes games[], size_t size)
{
	size_t	i;
	size_t	ret;

	i = 0;
	ret = 0;
	while (i < size)
	{
		if (is_game_possible(games[i]))
			ret += i + 1;
		i++;
	}
	return (ret);
}
