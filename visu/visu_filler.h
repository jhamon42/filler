/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_filler.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:28:24 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/15 18:16:00 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_FILLER_H
# define VISU_FILLER_H

# include "../libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define ERROR_P ft_printf("{red}ERROR PCE : piece invalide{eoc}")
# define ERROR_M ft_printf("{red}ERROR MAP : map invalide{eoc}")

typedef struct		s_visu
{
	char			**tb_map;
	int				rec;
	int				y_map;
	int				x_map;
	int				ok;
	void			*mlx;
	void			*win;
	void			*img;
	unsigned char	*data;
	int				sline;
	int				endian;
	int				bpp;
	int				var_x;
	int				var_y;
	int				defwin_y;
	int				defwin_x;
	int				pause;
}					t_visu;

void				val_tab(t_visu *p);
void				ft_free_tb_v(char **tb);
void				ft_rec_v(t_visu *p);
void				ft_aff_v(t_visu *p);
int					my_keys_events(int key, t_visu *p);
void				mlx_put_pixi(t_visu *p, int x, int y, int color);

#endif
