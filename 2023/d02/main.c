/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:10:50 by msloot            #+#    #+#             */
/*   Updated: 2023/12/06 19:16:30 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "d02.h"

t_cubes	parse_line(char *line)
{
	t_cubes	c;
	size_t	i;
	size_t	n;
	size_t	tmp;

	i = strlen(line) - 1;
	n = 0;
	while (i + 1 > 0)
	{
		if (line[i] == ' ')
			line[i] = '\0';
		if (i == 0 || line[i - 1] == ' ')
		{
			tmp = atoi(&line[i]);
			if (n == 0)
				c.blu = tmp;
			else if (n == 1)
				c.gre = tmp;
			else
				c.red = tmp;
			n++;
		}
		i--;
	}
	return (c);
}

int	main(int ac, char *av[])
{
	t_cubes	games[100];
	size_t	i;

	i = 1;
	while (i < (size_t)ac)
	{
		games[i - 1] = parse_line(av[i]);
		i++;
	}
	printf("%zu\n", solve(games, ac - 1));
	return (0);
}
