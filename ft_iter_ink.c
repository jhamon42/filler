/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iter_ink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 02:33:53 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/30 20:55:38 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_init_yxd(int *x, int *y, int *d, int tour)
{
	*x = 0;
	*y = tour;
	*d = tour - 1;
}

static void 	ft_iter_ttt(t_filler *p, int y, int x, int i)
{
	if (i == 4)
	{
		p->x_ply = p->x_ink + x; 
		p->y_ply = p->y_ink - y;
	}
	if (i == 5)
	{
		p->x_ply = p->x_ink + y; 
		p->y_ply = p->y_ink - x;
	}
	if (i == 6)
	{
		p->x_ply = p->x_ink - x; 
		p->y_ply = p->y_ink - y;
	}
	if (i == 7)
	{
		p->x_ply = p->x_ink - y; 
		p->y_ply = p->y_ink - x;
	}	
}

static void 	ft_iter_rrr(t_filler *p, int y, int x, int i)
{
	if (i >= 0 && i <= 3)
	{
		if (i == 0)
		{
			p->x_ply = p->x_ink + x; 
			p->y_ply = p->y_ink + y;
		}
		if (i == 1)
		{
			p->x_ply = p->x_ink + y; 
			p->y_ply = p->y_ink + x;
		}
		if (i == 2)
		{
			p->x_ply = p->x_ink - x; 
			p->y_ply = p->y_ink + y;
		}
		if (i == 3)
		{
			p->x_ply = p->x_ink - y; 
			p->y_ply = p->y_ink + x;
		}
	}
	else
		ft_iter_ttt(p, y, x, i);
}

static void 	ft_tjr_pls(int *d, int *y, int *x, int tour)
{
	if (*d >= (2 * *x))
	{
		*d -= ((2 * *x) - 1);
		*x += 1;
	}
	else if (*d < (2 * (tour - *y)))
	{
		*d += ((2 * *y) - 1);
		*y -= 1;
	}
	else
	{
		*d += (2 * (*y - *x - 1));
		*y -= 1;
		*x += 1;
	}
}

void 			ft_iter_ink(t_filler *p)
{
	static int x;
	static int y;
	static int d;

	if (p->tour == 0)
		ft_init_yxd(&x, &y, &d, p->tour);
	if (p->ink_i < 8)
	{
		ft_iter_rrr(p, y, x, p->ink_i++);
	}
	else
	{
		ft_tjr_pls(&d, &y, &x, p->tour);
		p->ink_i = 0;
		ft_iter_rrr(p, y, x, p->ink_i++);
	}
	if (!(y >= x) || p->tour == 0)
		ft_init_yxd(&x, &y, &d, ++p->tour);
}
