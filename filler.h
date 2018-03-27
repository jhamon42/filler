/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 12:07:36 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/27 17:39:50 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"

# define ERROR_P ft_printf("piece invalide")
# define ERROR_M ft_printf("map invalide")

typedef struct	s_filler
{
	char		ply;
	char		**tb_map;
	char		**tb_pce;
	int			y_ply;
	int			x_ply;
	int			rec;
	int			prs;
	int			y_map;
	int			x_map;
	int			y_pce;
	int			x_pce;
	int			finish;
}				t_filler;


void			ft_parseur(char *line, t_filler *p);
void			ft_rec_tb(char *line, t_filler *p, int la);


#endif