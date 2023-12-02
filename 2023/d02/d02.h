/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d02.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:44:45 by msloot            #+#    #+#             */
/*   Updated: 2023/12/02 16:59:56 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef D02_H
# define D02_H

# include <unistd.h>
# include <stdbool.h>

typedef struct s_cubes
{
	size_t	red;
	size_t	gre;
	size_t	blu;
}	t_cubes;

size_t	solve(t_cubes games[], size_t size);

#endif
