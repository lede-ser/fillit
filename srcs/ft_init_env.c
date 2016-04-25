/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 18:44:23 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/19 16:39:56 by lede-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

t_env	*ft_init_env(void)
{
	t_env	*env;

	if (!(env = (t_env*)malloc(sizeof(t_env))))
		ft_error();
	env->strmap = NULL;
	env->map = NULL;
	env->x = 0;
	env->y = 0;
	env->width = 0;
	env->height = 0;
	env->nb_tetri = 0;
	env->map_size = 0;
	env->ltetri = NULL;
	env->tetri = NULL;
	env->current_tetri = NULL;
	env->index = 0;
	return (env);
}
