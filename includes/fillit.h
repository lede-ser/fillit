/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 11:56:28 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/12 17:35:54 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <libft.h>

# define BUFF_SIZE 546
# define MAX_TETRI 27

struct							s_coord
{
	int							x;
	int							y;
};

typedef struct s_coord	t_coord;

struct							s_ltetri
{
	struct s_tetri				*first;
};

typedef struct s_ltetri	t_ltetri;

struct							s_tetri
{
	char						letter;
	int							index;
	struct s_coord				*placement;
	struct s_tetri				*next;
	struct s_coord				**coord;
};

typedef struct s_tetri	t_tetri;

struct							s_env
{
	char						*strmap;
	char						**map;
	int							width;
	int							height;
	int							x;
	int							y;
	int							nb_tetri;
	int							map_size;
	int							index;
	struct s_ltetri				*ltetri;
	struct s_tetri				*tetri;
	struct s_tetri				*current_tetri;
};

typedef struct s_env		t_env;

void							ft_bpoint(t_env *env);
void							ft_error(void);
char							*ft_read_map(char *file);
void							ft_update_tetri(t_env *env);
void							ft_place_tetri(t_env *env);
void							ft_update_low_tetri(t_env *env);
void							ft_reset_param(t_env *env);
void							ft_save_coord(t_env *env,
		t_coord **coord);
void							ft_check_coord(t_env *env);
void							ft_remove_tetri(t_env *env);
void							ft_remember_tetri(t_env *env);
void							ft_next_place(t_env *env);
int								ft_try_place(t_env *env);
void							ft_solve_tetri(t_env *env);
int								ft_tetriminos_valid(t_env *env,
		int i);
int								ft_verif_grid(t_env *env);
char							*ft_check_tetri(char *map,
		t_env *env);
void							ft_launch_check(t_env *env);
void							ft_init_list(t_env *env,
		t_coord **coord);
t_coord							ft_create_coord(void);
void							ft_create_tetri(t_env *env,
		t_coord **coord);
void							ft_push_back(t_ltetri *ltetri,
		t_tetri *n_tetri);
void							ft_free_map(t_env *env);
void							ft_create_map(t_env *env);
void							ft_print_map(t_env *env);
t_env							*ft_init_env(void);
void							ft_init_map(t_env *env);
void							ft_solve_bis(t_env *env);
void							ft_cut_tetri(t_env *env, char *map,
		int i);

#endif
