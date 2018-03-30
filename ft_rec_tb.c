/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rec_tb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:30:03 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/30 21:07:29 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_pce_rec(char *line, t_filler *p, int i_pce)
{
	int i;

	i = -1;
	while (++i < p->x_pce)
	{
		if (line[i])
		{
			if (line[i] == '*')
				p->tb_pce[i_pce][i] = p->ply;
			else
				p->tb_pce[i_pce][i] = line[i];
		}
	}
	
}

static void		ft_map_rec(char *line, t_filler *p, int i_map)
{
	int i;
	int j;
	int tmp;

	j = 0;
	i = ft_strchr_int(line, ' ');
	tmp = p->x_map + (i + 1);
	while (++i < tmp)
	{
		if (line[i])
			p->tb_map[i_map][j++] = line[i];
		if (line[i] == p->ply)
			ft_hercul(p, i_map, j);
	}
}

void			ft_rec_tb(char *line, t_filler *p)
{
	static int i_map;
	static int i_pce;

	if (p->rec == 1)
	{
		if (p->y_map - 1 == i_map)
		{
			ft_map_rec(line, p, i_map);
			i_map = 0;
			p->rec = 0;
		}
		else
			ft_map_rec(line, p, i_map++);
	}
	else
	{
		if (p->y_pce - 1 == i_pce)
		{
			ft_pce_rec(line, p, i_pce);
			i_pce = 0;
			p->rec = 3;
		}
		else
			ft_pce_rec(line, p, i_pce++);
	}
}
