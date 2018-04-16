/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hercul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:07:41 by jhamon            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/04/16 17:13:57 by jhamon           ###   ########.fr       */
=======
/*   Updated: 2018/04/10 22:04:53 by jhamon           ###   ########.fr       */
>>>>>>> 500803856512f863eef42a3c0279a1511c4d2281
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_medusa(t_filler *p)
{
	if (p->y_ini_en > p->y_ini_me)
		;
}

static void	ft_hydra(t_filler *p)
{
	if (p->phase == 4 || p->phase == -4)
	{
		p->x_ink = p->x_map / 2;
		p->y_ink = (p->y_ini_me < (p->y_map / 2)) ? p->y_map - 1 : 0;
	}
	else if (p->phase == 5 || p->phase == -5)
	{
		p->y_ink = p->y_map / 2;
		p->x_ink = (p->x_ini_me < (p->x_map / 2)) ? p->x_map - 1 : 0;
	}
	else if (p->phase == 6 || p->phase == -6)
	{
		p->y_ink = (p->y_ini_me > (p->y_map / 2)) ? p->y_map / 3 : (p->y_map - (p->y_map / 3));
		p->x_ink = (p->x_ini_me >= (p->x_map / 2)) ? p->x_map - 1: 0;
	}
	else if (p->phase == 9)
	{
		p->y_ink = p->y_ini_en;
		p->x_ink = p->x_ini_en;
	}
}

void	ft_hercul(t_filler *p)
{
	if (p->phase == 0)
		ft_medusa(p);
	else if (p->phase == 1 || p->phase == -1)
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
	{
		p->x_ink = (p->x_ini_me > (p->x_map / 2)) ? p->x_map / 3 : (p->x_map - (p->x_map / 3));
		p->y_ink = (p->y_ini_me >= (p->y_map / 2)) ? p->y_map - 1 : 0;
	}
	else if (p->phase == 7 || p->phase == -7)
	{
		p->x_ink = p->x_ini_me;
		p->y_ink = (p->y_ini_me >= (p->y_map / 2)) ? p->y_map - 1 : 0;
	}
	else if (p->phase == 8 || p->phase == -8)
	{
		p->y_ink = p->y_ini_me;
		p->x_ink = (p->x_ini_me >= (p->x_map / 2)) ? p->x_map - 1 : 0;
	}
	else
		ft_hydra(p);
}
