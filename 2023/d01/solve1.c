/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:49:16 by msloot            #+#    #+#             */
/*   Updated: 2023/12/02 16:14:30 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

bool	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	get_digit(const char *line)
{
	size_t	i;
	size_t	ret;

	i = 0;
	while (line[i] != '\0' && !ft_isdigit(line[i]))
		i++;
	ret = (line[i] - '0') * 10;
	i = ft_strlen(line) - 1;
	while (i + 1 > 0 && !ft_isdigit(line[i]))
		i--;
	ret += line[i] - '0';
	return (ret);
}

size_t	solve(char *input[], size_t size)
{
	size_t	i;
	size_t	ret;

	i = 0;
	ret = 0;
	while (i < size)
	{
		ret += get_digit(input[i]);
		i++;
	}
	return (ret);
}
