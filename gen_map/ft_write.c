/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 22:26:14 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/20 02:46:48 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gen_map.h"

static void		boucle_uno(t_gen *p)
{
	int j;
	int i;

	j = -1;
	while (++j <= p->y_map)
	{
		i = -1;
		while (++i <= p->x_map)
		{
			if (p->x_p1 == i && p->y_p1 == j)
				fprintf(p->fd, "O");
			else if (p->x_p2 == i && p->y_p2 == j)
				fprintf(p->fd, "X");
			else
				fprintf(p->fd, ".");
		}
		fprintf(p->fd, "\n");
	}
}

void			write_map(t_gen *p)
{
	if (p->p2 == 0)
	{
		p->x_p2 = p->x_map - 3;
		p->y_p2 = p->y_map - 3;
	}
	if (p->x_map < 15 || p->y_map < 15 || p->y_map > 271 || p->x_map > 481)
		exit(ERR_M);
	if (p->x_p1 < 0 || p->x_p2 < 0 || p->y_p2 < 0 || p->y_p1 < 0 || p->x_p1 >\
	p->x_map || p->x_p2 > p->x_map || p->y_p2 > p->y_map || p->y_p1 > p->y_map)
		exit(ERR_P);
	if (p->x_p2 == p->x_p1 && p->y_p2 == p->y_p1)
		exit(ERR_P);
	boucle_uno(p);
}
