/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hercul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:07:41 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/09 14:48:11 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_hydre(t_filler *p)
{
	if (p->phase == 14 || p->phase == -14)
	{
		p->x_ink = p->x_avp;
		p->y_ink = p->y_avp;
	}
	else if (p->phase == 15 || p->phase == -15)
	{
		p->x_ink = (p->x_ini_me > (p->x_map / 2)) ? 0 : p->x_map - 1;
		p->y_ink = (p->y_ini_me > (p->y_map / 2)) ? p->y_map - 1 : 0;
	}
	else if (p->phase == 16 || p->phase == -16)
	{
		p->x_ink = (p->x_ini_me > (p->x_map / 2)) ? p->x_map - 1 : 0;
		p->y_ink = (p->y_ini_me > (p->y_map / 2)) ? 0 : p->y_map - 1;
	}
	else
	{
		p->x_ink = p->x_ini_en;
		p->y_ink = p->y_ini_en;
	}
}

void		ft_hercul(t_filler *p)
{
	if (p->phase == 0)
	{
		p->x_avp = (((p->x_ini_me - p->x_ini_en) / 4) * 3) + p->x_ini_en;
		p->y_avp = (((p->y_ini_me - p->y_ini_en) / 4) * 3) + p->y_ini_en;
		p->phase = 14;
	}
	if (p->phase == 1 || p->phase == -1)
	{
		p->x_ink = p->x_avp;
		p->y_ink = (p->y_ini_me > (p->y_map / 2)) ? p->y_map - 1 : 0;
	}
	else if (p->phase == 2 || p->phase == -2)
	{
		p->y_ink = p->y_avp;
		p->x_ink = (p->x_ini_me > (p->x_map / 2)) ? p->x_map - 1 : 0;
	}
	else if (p->phase == 3)
	{
		p->y_ink = (p->y_map / 4);
		p->x_ink = p->x_ini_me;
	}
	else
		ft_hydre(p);
}
