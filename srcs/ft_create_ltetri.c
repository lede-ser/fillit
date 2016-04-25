/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_ltetri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-ser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:59:42 by lede-ser          #+#    #+#             */
/*   Updated: 2016/03/19 16:38:41 by lede-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

void	ft_push_back(t_ltetri *ltetri, t_tetri *n_tetri)
{
	t_tetri *tetri;

	tetri = ltetri->first;
	if (tetri)
	{
		while (tetri->next)
			tetri = tetri->next;
		tetri->next = n_tetri;
	}
	else
		tetri = n_tetri;
}

void	ft_create_tetri(t_env *env, t_coord **coord)
{
	t_tetri	*tetri;

	if (!(tetri = (t_tetri *)malloc(sizeof(t_tetri))))
		ft_error();
	tetri->coord = coord;
	tetri->index = env->index;
	tetri->letter = 'A' + tetri->index;
	if (!(tetri->placement = (t_coord*)malloc(sizeof(t_coord))))
		ft_error();
	tetri->next = NULL;
	ft_push_back(env->ltetri, tetri);
}

void	ft_init_list(t_env *env, t_coord **coord)
{
	t_tetri		*tetri;

	if (!(env->ltetri = (t_ltetri *)malloc(sizeof(t_ltetri))))
		ft_error();
	if (!(tetri = (t_tetri *)malloc(sizeof(t_tetri))))
		ft_error();
	tetri->coord = coord;
	tetri->index = env->index;
	tetri->letter = 'A' + tetri->index;
	if (!(tetri->placement = (t_coord*)malloc(sizeof(t_coord))))
		ft_error();
	tetri->next = NULL;
	env->ltetri->first = tetri;
}
