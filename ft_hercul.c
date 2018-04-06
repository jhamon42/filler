/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hercul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:07:41 by jhamon            #+#    #+#             */
/*   Updated: 2018/04/06 06:20:39 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_hercul(t_filler *p)
{
	if (p->phase == 1 || p->phase == -1)
	{
		p->y_ink = p->y_ini_me;
		p->x_ink = (p->x_ini_me < (p->x_map / 2)) ? p->x_map - 1 : 0;
	}
	else if (p->phase == 2 || p->phase == -2)
	{
		p->x_ink = p->x_ini_me;
		p->y_ink = (p->y_ini_me < (p->y_map / 2)) ? p->y_map - 1 : 0;
	}
	else if (p->phase == 3 || p->phase == -3)
		p->y_ink = (p->y_ini_me >= (p->y_map / 2)) ? p->y_map - 1 : 0;
	else if (p->phase == 4 || p->phase == -4)
		p->y_ink = (p->y_ini_me < (p->y_map / 2)) ? p->y_map - 1 : 0;
	else if (p->phase == 5 || p->phase == -5)
		p->x_ink = (p->x_ini_me < (p->x_map / 2)) ? p->x_map - 1 : 0;
	else if (p->phase == 6 || p->phase == -6)
		p->x_ink = (p->x_ini_me >= (p->x_map / 2)) ? p->x_map - 1: 0;
	else if (p->phase == 7)
	{
		p->y_ink = p->y_ini_en;
		p->x_ink = p->x_ini_en;
	}
}
