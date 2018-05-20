/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 14:42:59 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/19 22:38:44 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			ft_free_tb(char **tb, int a)
{
	if (tb)
	{
		while (a >= 0)
			free(tb[a--]);
		free(tb);
	}
}

static void		ft_pars_map(t_filler *p)
{
	int i;

	i = p->y_map;
	if (!(p->tb_map = (char**)ft_memalloc(sizeof(char*) * (p->y_map + 1))))
		exit(ERROR_P);
	while (--i >= 0)
		if (!(p->tb_map[i] = (char*)ft_memalloc(sizeof(char) * (p->x_map + 1))))
			exit(ERROR_P);
}

static void		ft_pars_pce(char *line, t_filler *p)
{
	int i;

	if (p->tb_pce)
		ft_free_tb(p->tb_pce, p->y_pce);
	p->y_pce = ft_atoi(line + 6);
	p->x_pce = ft_atoi(ft_strchr(line + 6, ' '));
	i = p->y_pce;
	if (p->x_pce <= 0 || p->y_pce <= 0)
		exit(ERROR_P);
	if (!(p->tb_pce = (char**)ft_memalloc(sizeof(char*) * (p->y_pce + 1))))
		exit(ERROR_P);
	while (--i >= 0)
		if (!(p->tb_pce[i] = (char*)ft_memalloc(sizeof(char) * (p->x_pce + 1))))
			exit(ERROR_P);
	p->rec = 2;
}

void			ft_parseur(char *line, t_filler *p)
{
	if (p->vue_prs == 0)
	{
		if (ft_strnequ("Plateau", line, 7) && ft_strlen(line) > 10)
		{
			p->y_map = ft_atoi(line + 8);
			p->x_map = ft_atoi(ft_strchr(line + 8, ' '));
			if (p->x_map <= 0 || p->y_map <= 0)
				exit(ERROR_M);
			ft_pars_map(p);
			p->vue_prs++;
		}
		else if (ft_strnequ("$$$ exec p1", line, 11))
			p->ply = 'O';
		else if (ft_strnequ("$$$ exec p2", line, 11))
			p->ply = 'X';
	}
	else
	{
		if (ft_strnequ("    ", line, 4))
			p->rec = 1;
		else if (ft_strnequ("Piece", line, 5) && ft_strlen(line) > 9)
			ft_pars_pce(line, p);
	}
}
