/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_tetri.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 17:09:22 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/11 16:38:34 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

void	ft_update_tetri(t_env *env)
{
	int i;

	i = 0;
	env->current_tetri = env->ltetri->first;
	while (i < env->index)
	{
		if (env->current_tetri->next != NULL)
			env->current_tetri = env->current_tetri->next;
		i++;
	}
}

void	ft_update_low_tetri(t_env *env)
{
	int i;

	i = 0;
	env->current_tetri = env->ltetri->first;
	while (i < env->index)
	{
		env->current_tetri = env->current_tetri->next;
		i++;
	}
}

void	ft_solve_bis(t_env *env)
{
	if (ft_try_place(env) == 1 && env->current_tetri->letter != 'A')
	{
		env->index--;
		ft_update_low_tetri(env);
		ft_remove_tetri(env);
		env->x = env->current_tetri->placement->x;
		env->y = env->current_tetri->placement->y;
		ft_next_place(env);
	}
	else if (ft_try_place(env) == 1 && env->current_tetri->letter == 'A')
	{
		ft_free_map(env);
		env->map_size++;
		ft_create_map(env);
		ft_reset_param(env);
		ft_solve_tetri(env);
	}
}
