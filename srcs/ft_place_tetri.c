/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-ser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:39:47 by lede-ser          #+#    #+#             */
/*   Updated: 2016/03/10 21:14:55 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

void	ft_place_tetri(t_env *env)
{
	int i;

	i = 0;
	while (i < 4)
	{
		env->map[env->y + env->current_tetri->coord[i]->y]
			[env->x + env->current_tetri->coord[i]->x] =
			env->current_tetri->letter;
		i++;
	}
	env->x = 0;
	env->y = 0;
}
