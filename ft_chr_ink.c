/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_ink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:27:22 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/31 18:45:03 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_chr_ink(t_filler *p)
{
	static int i;
	int tmp;
	int tmpi;

	tmp = ((p->x_map / 2) + (p->x_map / 4));
	tmpi = p->y_map;
	i++;
	if (i > tmp)
		p->phase = 1;
	if (i > tmp + tmpi)
		p->phase = 2;
}
