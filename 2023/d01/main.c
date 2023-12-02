/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:10:50 by msloot            #+#    #+#             */
/*   Updated: 2023/12/02 16:14:41 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

size_t	solve(char *input[], size_t size);

int	main(int ac, char *av[])
{
	printf("%zu\n", solve(av + 1, ac - 1));
}
