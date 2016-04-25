/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:11:34 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/11 16:52:25 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

void	ft_remove_tetri(t_env *env)
{
	int x;
	int y;

	y = 0;
	while (y < env->map_size)
	{
		x = 0;
		while (x < env->map_size)
		{
			if (env->map[y][x] >= env->current_tetri->letter)
				env->map[y][x] = '.';
			x++;
		}
		y++;
	}
}

void	ft_remember_tetri(t_env *env)
{
	env->current_tetri->placement->x = env->x;
	env->current_tetri->placement->y = env->y;
}

void	ft_next_place(t_env *env)
{
	if (env->x == env->map_size - 1 && env->y < env->map_size - 1)
	{
		env->x = 0;
		env->y++;
	}
	else if (env->x == env->map_size - 1 && env->y == env->map_size - 1)
		env->y++;
	else
		env->x++;
}

int		ft_try_place(t_env *env)
{
	int i;
	int falseret;

	i = 0;
	falseret = 0;
	while (i < 4)
	{
		if (env->current_tetri->coord[i]->x + env->x >= env->map_size ||
			env->current_tetri->coord[i]->y + env->y >= env->map_size ||
			(env->map[env->y + env->current_tetri->coord[i]->y]
					[env->x + env->current_tetri->coord[i]->x]) != '.')
			falseret++;
		i++;
	}
	return (falseret > 0 ? 1 : 0);
}

void	ft_solve_tetri(t_env *env)
{
	while (1)
	{
		while (env->y < env->map_size)
		{
			while (env->x < env->map_size)
			{
				if (env->index == env->nb_tetri)
					return ;
				if (ft_try_place(env) == 0)
				{
					ft_remember_tetri(env);
					ft_place_tetri(env);
					if (env->index == env->nb_tetri)
						return ;
					env->index++;
					ft_update_tetri(env);
				}
				if (ft_try_place(env) == 1)
					ft_next_place(env);
			}
			ft_next_place(env);
		}
		ft_solve_bis(env);
	}
}
