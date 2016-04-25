/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 16:55:46 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/19 16:35:23 by lede-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_env	*env;
	t_coord	**coord;
	int		i;

	i = 0;
	if (!(coord = (t_coord**)malloc(sizeof(t_coord*) * 4)))
		ft_error();
	if (ac == 2)
	{
		env = ft_init_env();
		env->strmap = ft_read_map(av[1]);
		ft_launch_check(env);
		ft_free_map(env);
		env->map_size = ft_sqrt(env->nb_tetri * 4);
		ft_create_map(env);
		env->current_tetri = env->ltetri->first;
		ft_solve_tetri(env);
		ft_print_map(env);
	}
	else
		ft_error();
	return (0);
}
