/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 12:07:36 by jhamon            #+#    #+#             */
/*   Updated: 2018/04/06 06:06:14 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"

# define ERROR_P ft_printf("{red}ERROR PCE : piece invalide{eoc}")
# define ERROR_M ft_printf("{rec}ERROR MAP : map invalide{eoc}")

typedef struct	s_filler
{
	char		ply;
	char		**tb_map;
	char		**tb_pce;
	int			y_ply;
	int			x_ply;
	int			y_ink;
	int			x_ink;
	int			rec;
	int			prs;
	int			y_map;
	int			x_map;
	int			y_pce;
	int			x_pce;
	int			y_ini_en;
	int			x_ini_en;
	int			y_ini_me;
	int			x_ini_me;
	int			finish;
	int			vue_prs;
	int			tour;
	int			ink_i;
	int			phase;
	FILE		*fd_trace;
	FILE		*fd_vm;
}				t_filler;


void			ft_parseur(char *line, t_filler *p);
void			ft_rec_tb(char *line, t_filler *p);
void			ft_rsv_flr(t_filler *p);
void			ft_free_tb(char **tb);
void			ft_chr_ink(t_filler *p);
int				ft_vrf_plc(t_filler *p);
void 			ft_iter_ink(t_filler *p);
void			ft_hercul(t_filler *p);
int				ft_cas_prt(t_filler *p, char c);

#endif