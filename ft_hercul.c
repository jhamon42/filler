/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hercul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:07:41 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/30 22:34:38 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_hercul(t_filler *p, int y, int x)
{
	static int i;

	if (i++ == 0)
	{
		p->y_ini = y;
		p->x_ini = x;
	}
	if (p->phase == 0)
	{
		p->y_ink = p->y_ini;
		if (x < (p->x_map / 2))
			p->x_ink = p->x_map + 5;
		else
			p->x_ink = -5;
	}
	else if (p->phase == 1)
	{
		p->x_ink = p->x_ini;
		if (y < (p->y_map / 2))
			p->y_ink = p->y_map + 5;
		else
			p->y_ink = -5;
	}
	else if (p->phase == 2)
		;
	else if (p->phase == 3)
		;
	else
		;
}
