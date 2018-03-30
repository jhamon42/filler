/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vrf_plc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 11:35:46 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/30 18:57:45 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int ft_vrf_pce(t_filler *p, int y, int x)
{
	if (p->tb_pce[y][x] != '.')
		return (0);
	return (1);
}

static int ft_pce_ega(t_filler *p, int y, int x)
{
	int static i;

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
	return(0);
}

static int ft_pce_noega(t_filler *p, int y, int x)
{
	if (p->tb_pce[y][x] == '.')
		return (1);
	if (p->tb_pce[y][x] == p->ply && \
		p->tb_map[p->y_ply + y][p->x_ply + x] != '.')
		return (0);
	if (p->tb_pce[y][x] == p->ply && \
		p->tb_map[p->y_ply + y][p->x_ply + x] == '.')
		return (1);
	return(0);
}

int	ft_vrf_plc(t_filler *p)
{
	int i_x_pce;
	int i_y_pce;
	int ok;

	i_y_pce = -1;
	while (++i_y_pce < p->y_pce)
	{
		i_x_pce = -1;
		while (++i_x_pce < p->x_pce)
		{
			if (p->y_ply + i_y_pce < 0 || p->x_ply + i_x_pce < 0)
				ok = ft_vrf_pce(p, i_y_pce, i_x_pce);
			else if (p->y_ply + i_y_pce > p->y_map - 1 || \
					p->x_ply + i_x_pce > p->x_map - 1)
				ok = ft_vrf_pce(p, i_y_pce, i_x_pce);
			else if (p->tb_pce[i_y_pce][i_x_pce] == \
				p->tb_map[p->y_ply + i_y_pce][p->x_ply + i_x_pce])
				ok = ft_pce_ega(p, i_y_pce, i_x_pce);
			else
				ok = ft_pce_noega(p, i_y_pce, i_x_pce);
			if (!ok)
				return (ft_pce_ega(p, -1, 0));
		}
	}
	return (ft_pce_ega(p, -2, 0));
}
