/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hercul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:07:41 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/31 18:35:18 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_hercul(t_filler *p)
{
	if (p->phase == 0)
	{
		p->y_ink = p->y_ini_me;
		if (p->x_ini_me < (p->x_map / 2))
			p->x_ink = p->x_map;
		else
			p->x_ink = -5;
	}
	else if (p->phase == 1)
	{
		p->x_ink = p->x_ini_me;
		if (p->y_ini_me < (p->y_map / 2))
			p->y_ink = p->y_map;
		else
			p->y_ink = -5;
	}
	else if (p->phase == 2)
	{
		p->y_ink = p->y_ini_en;
		p->x_ink = p->x_ini_en;
	}
}
