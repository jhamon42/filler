/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_oink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 12:48:27 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/09 14:48:29 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// static void	ft_phaseur_ion(t_filler *p)
// {
// 	if (p->phase == 16)
// 		p->phase = 1;
// 	else if (p->phase == 1)
// 		p->phase = 16;
// 	else if (p->phase == 2)
// 		p->phase = 15;
// 	else if (p->phase == 15)
// 		p->phase = 2;
// }

// static void	ft_phaseur_elec(t_filler *p)
// {
// 	if (p->phase == 15)
// 		p->phase = -1;
// 	else if (p->phase == 16)
// 		p->phase = 100;
// 	else if (p->phase == 2)
// 		p->phase = -16;
// 	else if (p->phase == 1)
// 		p->phase = -15;
// }

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

void		ft_chr_oink(t_filler *p)
{
	if (p->phase != 100)
	{
		if (ft_awesome_rchr(p, '.'))
			p->phase = 3;
		else
			p->phase = 100;
	}
}