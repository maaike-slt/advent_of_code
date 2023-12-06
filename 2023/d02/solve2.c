/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:16:48 by msloot            #+#    #+#             */
/*   Updated: 2023/12/06 19:22:51 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "d02.h"

size_t	power(t_cubes game)
{
	return (game.red * game.gre * game.blu);
}

size_t	solve(t_cubes games[], size_t size)
{
	size_t	i;
	size_t	ret;

	i = 0;
	ret = 0;
	while (i < size)
	{
		ret += power(games[i]);
		i++;
	}
	return (ret);
}