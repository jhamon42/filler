/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 18:46:13 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/20 02:41:02 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEN_MAP_H
# define GEN_MAP_H

# include "../libft/libft.h"

# define ERR_U ft_printf("Usage : ./gen_map \"Y X\" -p1 \"Y X\" -p2  \"Y X\"\n")
# define ERR_M ft_printf("MAP : y:(min: 15 max: 270) x:(min: 15 max: 480)\n")
# define ERR_P ft_printf("PIECE : coordonner pas valide\n")

typedef struct		s_gen
{
	int		x_map;
	int		y_map;
	int		x_p1;
	int		y_p1;
	int		x_p2;
	int		y_p2;
	int		p1;
	int		p2;
	FILE	*fd;
}					t_gen;

void				write_map(t_gen *p);

#endif
