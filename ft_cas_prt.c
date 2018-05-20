/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cas_prt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 05:19:39 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/18 20:27:30 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_cas_prt(t_filler *p, char c)
{
	if (p->x_ink + 1 == p->x_map)
	{
		if (p->tb_map[p->y_ink][p->x_ink - 2] != c || \
			p->tb_map[p->y_ink][p->x_ink - 1] != c)
			return (0);
	}
	if (p->x_ink == 0)
	{
		if (p->tb_map[p->y_ink][p->x_ink + 2] != c || \
			p->tb_map[p->y_ink][p->x_ink + 1] != c)
			return (0);
	}
	if (p->y_ink == 0)
	{
		if (p->tb_map[p->y_ink + 2][p->x_ink] != c || \
			p->tb_map[p->y_ink + 1][p->x_ink] != c)
			return (0);
	}
	if (p->y_ink + 1 == p->y_map)
	{
		if (p->tb_map[p->y_ink - 2][p->x_ink] != c || \
			p->tb_map[p->y_ink - 1][p->x_ink] != c)
			return (0);
	}
	return (1);
}

int		ft_cas_val(t_filler *p, char c)
{
	if (p->x_ink + 1 == p->x_map)
	{
		if (p->tb_map[p->y_ink][p->x_ink - 2] == c || \
			p->tb_map[p->y_ink][p->x_ink - 1] == c)
			return (1);
	}
	if (p->x_ink == 0)
	{
		if (p->tb_map[p->y_ink][p->x_ink + 2] == c || \
			p->tb_map[p->y_ink][p->x_ink + 1] == c)
			return (1);
	}
	if (p->y_ink == 0)
	{
		if (p->tb_map[p->y_ink + 2][p->x_ink] == c || \
			p->tb_map[p->y_ink + 1][p->x_ink] == c)
			return (1);
	}
	if (p->y_ink + 1 == p->y_map)
	{
		if (p->tb_map[p->y_ink - 2][p->x_ink] == c || \
			p->tb_map[p->y_ink - 1][p->x_ink] == c)
			return (1);
	}
	return (0);
}

int		ft_wall_check(t_filler *p, int a)
{
	int i;

	i = -1;
	if (a == 1)
	{
		while (++i < p->y_map - 1)
		{
			if (p->tb_map[i][0] == p->ply || \
				p->tb_map[i][p->x_map - 1] == p->ply)
				return (0);
		}
	}
	else
	{
		while (++i < p->x_map - 1)
		{
			if (p->tb_map[0][i] == p->ply || \
				p->tb_map[p->y_map - 1][i] == p->ply)
				return (0);
		}
	}
	return (1);
}
