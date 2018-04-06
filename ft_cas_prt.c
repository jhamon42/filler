/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cas_prt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 05:19:39 bp->y_ink jhamon            #+#    #+#             */
/*   Updated: 2018/04/06 05:28:07 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_cas_prt(t_filler *p, char c)
{
	if (p->x_ink == p->x_map && p->y_ink == 0)
	{
		if (p->tb_map[p->y_ink + 1][p->x_ink] == c)
			if (p->tb_map[p->y_ink][p->x_ink - 1] == c)
				return (1);
	}
	else if (p->y_ink == p->y_map && p->x_ink == 0)
	{
		if (p->tb_map[p->y_ink - 1][p->x_ink] == c)
			if (p->tb_map[p->y_ink][p->x_ink + 1] == c)
				return (1);
	}
	else if (p->x_ink == 0 && p->y_ink == 0)
	{
		if (p->tb_map[p->y_ink + 1][p->x_ink] == c)
			if (p->tb_map[p->y_ink][p->x_ink + 1] == c)
				return (1);
	}
	else
	{
		if (p->tb_map[p->y_ink - 1][p->x_ink] == c)
			if (p->tb_map[p->y_ink][p->x_ink - 1] == c)
				return (1);
	}
	return (0);
}
