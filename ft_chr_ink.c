/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_ink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 01:34:23 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/06 14:27:06 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_phaseur_ion(t_filler *p)
{
	if (p->phase == 15)
		p->phase = 16;
	else if (p->phase == 16)
		p->phase = 15;
	else if (p->phase == 2)
		p->phase = 1;
	else if (p->phase == 1)
		p->phase = 2;
}

static void	ft_phaseur_elec(t_filler *p)
{
	if (p->phase == 15)
		p->phase = -16;
	else if (p->phase == 14)
		p->phase = 16;
	else if (p->phase == 16)
		p->phase = -15;
	else if (p->phase == 2)
		p->phase = -1;
	else if (p->phase == 1)
		p->phase = -2;
}

static void	ft_phaseur_netron(t_filler *p)
{
	if (p->phase == 16)
		p->phase = 2;
	else if (p->phase == 15)
		p->phase = 2;
	else if (p->phase == 2)
		p->phase = -1;
	else if (p->phase == 1)
		p->phase = -2;
	else
		p->phase = 100;
}

static int	ft_awesome_rchr(t_filler *p, char c)
{
	int f;

	f = p->phase;
	if (f == 2 || f == 1 || f == -1 || f == -2)
		return (ft_wall_check(p));
	if (p->tb_map[p->y_ink][p->x_ink] == c)
		return (1);
	if (f == 15 || f == -15 || f == 16 || f == -16)
	{
		if (c == '.')
			return (ft_cas_prt(p, c));
		else
			return (ft_cas_val(p, c));
	}
	return (0);
}

void		ft_chr_ink(t_filler *p)
{
	if (p->phase != 100)
	{
		if (ft_awesome_rchr(p, '.'))
		{
			if (p->phase > 0 && p->phase != 14)
				ft_phaseur_ion(p);
		}
		else
		{
			if (ft_awesome_rchr(p, p->ply))
			{
				(p->phase > 0) ? ft_phaseur_elec(p) : (p->phase = 100);
			}
			else
				ft_phaseur_netron(p);
		}
	}
}
