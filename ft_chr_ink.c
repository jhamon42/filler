/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_ink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 01:34:23 by jhamon            #+#    #+#             */
/*   Updated: 2018/04/10 17:06:10 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_phaseur_ion(t_filler *p)
{
	if (p->phase == 1)
		p->phase = 1;
	else if (p->phase == 2)
		p->phase = 2;
	else if (p->phase == 3)
		p->phase = 6;
	else if (p->phase == 4)
		p->phase = 5;
	else if (p->phase == 5)
		p->phase = 4;
	else if (p->phase == 6)
		p->phase = 3;
}

static void	ft_phaseur_elec(t_filler *p)
{
	if (p->phase == 1)
		p->phase = 6;
	else if (p->phase == 2)
		p->phase = 3;
	else if (p->phase == 3)
		p->phase = 9;
	else if (p->phase == 4)
		p->phase = 9;
	else if (p->phase == 5)
		p->phase = 9;
	else if (p->phase == 6)
		p->phase = 9;
	else if (p->phase == 7)
		p->phase = 4;
	else if (p->phase == 8)
		p->phase = 5;
}

static void	ft_phaseur_negatron(t_filler *p)
{
	if (p->phase == -1)
		p->phase = 7;
	else if (p->phase == -2)
		p->phase = 7;
	else if (p->phase == -3)
		p->phase = 1;
	else if (p->phase == -4)
		p->phase = 7;
	else if (p->phase == -5)
		p->phase = 7;
	else if (p->phase == -6)
		p->phase = 2;
}

static void	ft_phaseur_netron(t_filler *p)
{
	if (p->phase == 1)
		p->phase = 6;
	else if (p->phase == 2)
		p->phase = 3;
	else if (p->phase == 3)
		p->phase = 9;
	else if (p->phase == 4)
		p->phase = 2;
	else if (p->phase == 5)
		p->phase = 1;
	else if (p->phase == 6)
		p->phase = 9;
}

static int	ft_awesome_rchr(t_filler *p, char c)
{
	int f;
	int x;
	int y;

	f = p->phase;
	x = p->x_ink;
	y = p->y_ink;
	if (p->tb_map[y][x] != c)
		return (0);
	if ((x + 1 == p->x_map && y == 0) || (y + 1 == p->y_map && x == 0) || \
		(x == 0 && y == 0) || (x + 1 == p->x_map && y + 1 == p->y_map))
		return (ft_cas_prt(p, c));
	else if (f == 1 || f == 5 || f == 6 || f == -5 || f == -6 || f == -1 || f == 8)
	{
		if (p->tb_map[y - 1][x] == c)
			if (p->tb_map[y + 1][x] == c)
				return (1);
	}
	else if (f == 2 || f == 4 || f == 3 || f == -4 || f == -3 || f == -2 || f == 7)
	{
		if (p->tb_map[y][x - 1] == c)
			if (p->tb_map[y][x + 1] == c)
				return (1);
	}
	return (0);
}

void	ft_chr_ink(t_filler *p)
{
	if (p->phase != 9)
	{
		if (ft_awesome_rchr(p, '.'))
		{
			if (p->phase > 0 && p->phase < 7)
				;//ft_phaseur_ion(p);
		}
		else
		{
			if (ft_awesome_rchr(p, p->ply))
			{
				if (p->phase > 0)
					ft_phaseur_elec(p);
				// else
				// 	ft_phaseur_negatron(p);
			}
			else
				ft_phaseur_netron(p);
		}
	}
}
