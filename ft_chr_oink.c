/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_oink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 12:48:27 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/18 20:26:30 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_awesome_rchr(t_filler *p, char c)
{
	int f;

	f = p->phase;
	if (ft_wall_check(p, 1))
		return (ft_wall_check(p, 2));
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
