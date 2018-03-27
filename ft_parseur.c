/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 14:42:59 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/27 17:39:44 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_pars_tab(t_filler *p)
{
	int i;

	i = p->y_map;
	if (!(p->tb_map = (char**)malloc(sizeof(char*)*p->y_map + 1)))
		exit(ERROR_P);
	p->tb_map[i] = NULL;
	while (--i != 0)
	{
		if (!(p->tb_map[i] = (char*)malloc(sizeof(char)*p->x_map + 1)))
			exit(ERROR_P);
		p->tb_map[i][p->x_map] = '\0';
	}
	if (!(p->tb_map[i] = (char*)malloc(sizeof(char)*p->x_map + 1)))
		exit(ERROR_P);
	p->tb_map[i][p->x_map] = '\0';
	p->rec = 1;
}

static void		ft_pars_pce(char *line, t_filler *p)
{
	int i;

	p->y_pce = ft_atoi(line + 6);
	p->x_pce = ft_atoi(ft_strchr(line + 6, ' '));
	if (p->x_pce <= 0 || p->y_pce <= 0)
		exit(ERROR_P);
	i = p->y_pce;
	if (p->tb_pce)
		free(p->tb_pce);
	if (!(p->tb_pce = (char**)malloc(sizeof(char*)*p->y_pce + 1)))
		exit(ERROR_P);
	p->tb_pce[i] = NULL;
	while (--i != 0)
	{
		if (!(p->tb_pce[i] = (char*)malloc(sizeof(char)*p->x_pce + 1)))
			exit(ERROR_P);
		p->tb_pce[i][p->x_pce] = '\0';
	}
	if (!(p->tb_pce[i] = (char*)malloc(sizeof(char)*p->x_pce + 1)))
		exit(ERROR_P);
	p->tb_pce[i][p->x_pce] = '\0';
	p->rec = 2;
}

void			ft_parseur(char *line, t_filler *p)
{
	static int vue;

	if (vue == 0)
	{
		if (ft_strnequ("Plateau", line, 7))
		{
			p->y_map = ft_atoi(line + 8);
			p->x_map = ft_atoi(ft_strchr(line + 8, ' ')); 
			if (p->x_map <= 0 || p->y_map <= 0)
				exit(ERROR_M);
			ft_pars_tab(p);
			vue++;
		}
		else if (ft_strnequ("$$$ exec p1", line, 11))
			p->ply = 'O';
		else if (ft_strnequ("$$$ exec p2", line, 11))
			p->ply = 'X';
	}
	else
	{
		if (ft_strnequ("Plateau", line, 7))
			p->rec = 1;
		if (ft_strnequ("Piece", line, 5))
			ft_pars_pce(line, p);
	}
}
