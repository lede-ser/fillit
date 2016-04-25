/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 17:32:18 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/19 16:39:28 by lede-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

void	ft_free_map(t_env *env)
{
	int y;

	y = 0;
	while (y < env->map_size)
	{
		free(env->map[y]);
		y++;
	}
	env->map = NULL;
}

void	ft_create_map(t_env *env)
{
	int y;
	int x;

	y = 0;
	if (!(env->map = (char**)malloc(sizeof(char*) * env->map_size)))
		ft_error();
	while (y < env->map_size)
	{
		if (!(env->map[y] = (char*)malloc(sizeof(char) * env->map_size)))
			ft_error();
		x = 0;
		while (x < env->map_size)
		{
			env->map[y][x] = '.';
			x++;
		}
		env->map[y][x] = '\0';
		y++;
	}
}

void	ft_print_map(t_env *env)
{
	int y;

	y = 0;
	while (y < env->map_size)
	{
		ft_putendl(env->map[y]);
		y++;
	}
}
