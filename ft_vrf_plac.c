/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vrf_plac.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 11:35:46 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/06 15:28:18 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	int	ft_pce_ega(t_filler *p, int y, int x)
{
	static int i;

	if (y == -1)
		return (i = 0);
	if (y == -2)
	{
		if (i == 1)
		{
			i = 0;
			return (1);
		}
		return (i = 0);
	}
	if (p->tb_pce[y][x] == '.')
		return (1);
	if (p->tb_pce[y][x] == p->ply)
		i++;
	if (i < 2)
		return (1);
	return (0);
}

static	int	ft_pce_noega(t_filler *p, int y, int x, int a)
{
	if (a == 1)
	{
		if (p->tb_pce[y][x] == '.')
			return (1);
		if (p->tb_pce[y][x] == p->ply &&
		p->tb_map[p->y_ply + y][p->x_ply + x] == '.')
			return (1);
		return (0);
	}
	if (p->tb_pce[y][x] != '.')
		return (0);
	return (1);
}

int			ft_vrf_plac(t_filler *p)
{
	int x;
	int y;
	int ok;

	y = -1;
	ok = 0;
	while (++y < p->y_pce)
	{
		x = -1;
		while (++x < p->x_pce)
		{
			if (p->y_ply + y < 0 || p->x_ply + x < 0 ||
				p->y_ply + y > p->y_map - 1 || p->x_ply + x > p->x_map - 1)
				ok = ft_pce_noega(p, y, x, 2);
			else if (p->tb_pce[y][x] == p->tb_map[p->y_ply + y][p->x_ply + x])
				ok = ft_pce_ega(p, y, x);
			else
				ok = ft_pce_noega(p, y, x, 1);
			if (!ok)
				return (ft_pce_ega(p, -1, 0));
		}
	}
	return (ft_pce_ega(p, -2, 0));
}
