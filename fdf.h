/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 22:09:57 by toliver           #+#    #+#             */
/*   Updated: 2017/12/06 18:08:04 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include <math.h>
# include <stdio.h>

typedef struct		s_vector4
{
	double			x;
	double			y;
	double			z;
	int				w;
}					t_vector4;

typedef struct		s_map
{
	char			*str;
	char			**splitted;
	size_t			array_size;
	int				*posz;
	int				*color;
	struct s_map	*next;
}					t_map;

typedef struct		s_parsedmap
{
	t_vector4		*point;
	t_vector4		*pointp;
	size_t			array_size;
	double			xmid;
	double			ymid;
}					t_parsedmap;

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*menu;
	char			*img_str;

	int				winx;
	int				winy;

	int				key[279];
	int				button[7];
	int				buttonx[7];
	int				buttony[7];

	int				isinmenu;
	t_vector4		tran;
	t_vector4		sca;
	t_vector4		rot;
	t_vector4		rotrad;
	t_map			*map;
	t_parsedmap		*isomap;
}					t_data;

void				*initialize(void);
void				array_init(t_data *data);
void				vector_init(t_data *data);
int					map_array_init(t_map *map);
int					checkparam(int argc, char **argv);
int					hexvalue(char c);
int					ft_get_hexcolor(char *str);
int					map_array_fill(t_map *map);
int					copyparam(t_map *map, t_parsedmap *copy);
int					printtab(t_parsedmap *map);
t_map				*map_parsing(char *str);
t_map				*mapnew(void);
t_parsedmap			*copymap(t_map *map);
void				ft_error(char *str);

/*
** printing functions
*/

int					maptoscreen(t_data *data);
int					isprintable(t_vector4 a, t_vector4 b, t_data *data);
int					whichside(t_vector4 a, int winx, int winy);
int					leo_kot_prime_numbers
									(t_vector4 a, t_vector4 b, int wx, int wy);
int					aux_lkot_primen(double cd, double oalo, int winx, int winy);
int					in_range(double to_check, int wintocheck);
void				mlx_px_to_img(t_data *dat, char *img, t_vector4 a, int col);
void				mlx_img_init(t_data *data);
void				putlinepart(t_vector4 a, t_vector4 b, t_data *data);
void				putline(t_vector4 a, t_vector4 b, t_data *data);
char				get_color(t_vector4 a, char color);
void				setangle(t_vector4 *anglerad, t_vector4 angle);
void				jointoprec(size_t i, t_vector4 *vector, t_data *data);
void				jointoupper(size_t i, t_vector4 *vector, t_data *data);
void				jointodiag(size_t i, t_vector4 *vector, t_data *data);
void				rloop(size_t i, t_vector4 angle,
							t_parsedmap *map, t_data *data);
/*
** keyboard functions
*/

int					key_on(int keycode, t_data *param);
int					resetiso(t_data *data);

/*
** mouse functions
*/

int					button_on(int button, int x, int y, t_data *param);
int					button_off(int button, int x, int y, t_data *param);
int					mouse_mov(int x, int y, t_data *data);
int					middle_button(int x, int y, t_data *data, int i);
int					left_button(int x, int y, t_data *data, int i);
int					right_button(int x, int y, t_data *data, int i);

/*
** rot functions
*/

int					scale(t_data *data, double value);
int					rotx(t_data *data, double value);
int					roty(t_data *data, double value);
int					rotz(t_data *data, double value);

#endif
