/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hercul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:07:41 by jhamon            #+#    #+#             */
/*   Updated: 2018/04/16 19:44:06 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_medusa(t_filler *p)
{
	p->phase = 1;
}

static void	ft_hydra(t_filler *p)
{
	{
		p->x_ink = p->x_ini_en;
		p->y_ink = p->y_ini_en;
	}
}

void	ft_hercul(t_filler *p)
{
	if (p->phase == 0)
		ft_medusa(p);
	else if (p->phase == 1 || p->phase == -1)
	{
		p->x_ink = p->x_ini_me;
		p->y_ink = (p->y_ini_me > (p->y_map / 2)) ? p->y_map - 1 : 0;
	}
	else if (p->phase == 2 || p->phase == -2)
	{
		p->y_ink = p->y_ini_me;
		p->x_ink = (p->x_ini_me > (p->x_map / 2)) ? p->x_map - 1 : 0;
	}
	else if (p->phase == 3 || p->phase == -3)
	{
		p->x_ink = p->x_map / 2;
		p->y_ink = (p->y_ini_me > (p->y_map / 2)) ? p->y_map - 1 : 0;
	}
	else if (p->phase == 4 || p->phase == -4)
	{
		p->x_ink = (p->x_ini_me > (p->x_map / 2)) ? p->x_map - 1 : 0;
		p->y_ink = p->y_map / 2;
	}
	else if (p->phase == 5 || p->phase == -5)
	{
		p->y_ink = (p->y_ini_en < (p->y_map / 2)) ? p->y_map - 1 : 0;
		p->x_ink = p->x_ini_en;
	}
	else if (p->phase == 6 || p->phase == -6)
	{
		p->x_ink = (p->x_ini_en < (p->x_map / 2)) ? p->x_map - 1 : 0;
		p->y_ink = p->y_ini_en;
	}
	else if (p->phase == 7 || p->phase == -7)
	{
		p->x_ink = p->x_ini_me;
		p->y_ink = (p->y_ini_me > (p->y_map / 2)) ? 0 : p->y_map - 1;
	}
	else if (p->phase == 8 || p->phase == -8)
	{
		p->y_ink = p->y_ini_me;
		p->x_ink = (p->x_ini_me > (p->x_map / 2)) ? 0 : p->x_map - 1;
	}
	else if (p->phase == 9 || p->phase == -9)
	{
		p->x_ink = p->x_map / 2;
		p->y_ink = (p->y_ini_me > (p->y_map / 2)) ? 0 : p->y_map - 1;
	}
	else if (p->phase == 10 || p->phase == -10)
	{
		p->x_ink = (p->x_ini_me > (p->x_map / 2)) ? 0 : p->x_map - 1;
		p->y_ink = p->y_map / 2;
	}
	else if (p->phase == 11 || p->phase == -11)
	{
		p->y_ink = (p->y_ini_en > (p->y_map / 2)) ? p->y_map - 1 : 0;
		p->x_ink = p->x_ini_en;
	}
	else if (p->phase == 12 || p->phase == -12)
	{
		p->x_ink = (p->x_ini_en > (p->x_map / 2)) ? p->x_map - 1 : 0;
		p->y_ink = p->y_ini_en;
	}
	else
		ft_hydra(p);
}
