/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 18:00:48 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/19 16:37:28 by lede-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		ft_tetriminos_valid(t_env *env, int i)
{
	int sharp;

	sharp = 0;
	if (env->strmap[i] == '#' && i <= 20 && sharp < 5)
	{
		sharp++;
		env->strmap[i] = env->nb_tetri + 1;
		sharp += ft_tetriminos_valid(env, i + 1);
		sharp += ft_tetriminos_valid(env, i - 1);
		sharp += ft_tetriminos_valid(env, i + 5);
		sharp += ft_tetriminos_valid(env, i - 5);
	}
	return (sharp);
}

int		ft_verif_grid(t_env *env)
{
	int i;
	int nb_sharp;
	int nb_point;

	i = 0;
	nb_sharp = 0;
	nb_point = 0;
	while (env->strmap[i] != '\0')
	{
		if (env->strmap[i] == '.')
			nb_point++;
		if (env->strmap[i] == '#')
			nb_sharp = ft_tetriminos_valid(env, i);
		i++;
	}
	if (i != 20 || nb_sharp != 4 || nb_point != 12)
		ft_error();
	return (1);
}

char	*ft_check_tetri(char *map, t_env *env)
{
	env->strmap = map;
	if (ft_verif_grid(env) == 1)
		return (env->strmap);
	ft_error();
	return (NULL);
}

void	ft_launch_check(t_env *env)
{
	int		i;
	char	*map;

	i = 20;
	map = env->strmap;
	if (!(env->map = (char **)malloc(sizeof(char*) * MAX_TETRI)))
		ft_error();
	while (map[++i] != '\0')
	{
		if (i % 21 == 0)
			ft_cut_tetri(env, map, i);
	}
	if (map[i] == '\0')
		ft_cut_tetri(env, map, i);
	free(env->map);
	if (ft_strlen(map) != ((size_t)((env->nb_tetri) * 21) - 1))
		ft_error();
	env->strmap = map;
	env->index = 0;
}

void	ft_cut_tetri(t_env *env, char *map, int i)
{
	env->map[env->nb_tetri] = ft_strdup(ft_strsub(map, i - 21, 20));
	ft_check_tetri(ft_strsub(map, i - 21, 20), env);
	ft_check_coord(env);
	env->nb_tetri++;
}
