/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:53:08 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/20 01:16:52 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		s_filler_init(t_filler *p)
{
	p->y_map = 0;
	p->x_map = 0;
	p->y_ink = 0;
	p->x_ink = 0;
	p->rec = 0;
	p->prs = 0;
	p->ply = 0;
	p->y_ply = 0;
	p->x_ply = 0;
	p->y_pce = 0;
	p->x_pce = 0;
	p->finish = 0;
	p->vue_prs = 0;
	p->phase = 0;
	p->tb_map = NULL;
	p->tb_pce = NULL;
}

int				main(void)
{
	t_filler	filler;
	t_filler	*p;
	char		*line;

	p = &filler;
	s_filler_init(p);
	while (get_next_line(0, &line) > 0)
	{
		if (p->rec == 1 || p->rec == 2)
			ft_rec_tb(line, p);
		if (p->rec == 0)
			ft_parseur(line, p);
		if (p->rec == 3)
		{
			ft_rsv_flr(p);
			p->rec = 0;
		}
		free(line);
	}
	ft_free_tb(p->tb_map, p->y_map);
	ft_free_tb(p->tb_pce, p->y_pce);
	return (0);
}
