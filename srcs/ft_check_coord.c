/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_coord.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 17:37:24 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/19 17:05:13 by lede-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

void	ft_save_coord(t_env *env, t_coord **coord)
{
	env->height = 1;
	while (env->strmap != '\0')
	{
		while (env->height < 4)
		{
			coord[env->height]->x -= coord[0]->x;
			coord[env->height]->y -= coord[0]->y;
			env->height++;
		}
		coord[0]->x = 0;
		coord[0]->y = 0;
		if (env->height == 4)
			return ;
	}
}

void	ft_check_coord(t_env *env)
{
	t_coord		**coord;
	int			i;

	i = -1;
	coord = (t_coord**)malloc(sizeof(t_coord*) * 4);
	env->height = 0;
	env->width = 0;
	while (env->map[env->nb_tetri][++i] != '\0')
	{
		if (env->map[env->nb_tetri][i] == '#' && env->height < 5)
		{
			coord[env->height] = (t_coord*)malloc(sizeof(t_coord));
			coord[env->height]->y = env->width;
			coord[env->height]->x = (i - ((4 + 1) * env->width));
			env->height++;
		}
		if (env->map[env->nb_tetri][i] == '\n')
			env->width++;
	}
	ft_save_coord(env, coord);
	if (!env->ltetri)
		ft_init_list(env, coord);
	else
		ft_create_tetri(env, coord);
	env->index++;
}
