/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:53:08 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/27 17:39:38 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		s_filler_init(t_filler *p)
{
	p->y_map = 0;
	p->x_map = 0;
	p->rec = 0;
	p->prs = 0;

	p->ply = 0;
	p->y_ply = 3;
	p->x_ply = 3;
	p->y_pce = 0;
	p->x_pce = 0;
	p->finish = 0;
}

int				main(void)
{
	t_filler	filler;
	t_filler	*p;
	FILE		*fd_trace;
	FILE		*fd_vm;
	char		*line;
	int			a;

	p = &filler;
	s_filler_init(p);
	fd_vm = fopen("trace_vm.txt", "w");
	fd_trace = fopen("trace_moi.txt", "w");
	a = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (p->rec >= 1)
			ft_rec_tb(line, p, a);
		else
			ft_parseur(line, p);
		if (p->rec == 2)
		{
			p->finish = 1;
			fprintf(fd_trace, "player : %c Tableau : %d %d\n", p->ply, p->y_map, p->x_map);
			fprintf(fd_trace, "piece : %d %d ligne : %d\n", p->y_pce, p->x_pce, a);
		}
		fputs(line, fd_vm);
		fputs("\n", fd_vm);
		if (p->finish)
			ft_printf("%d %d\n", p->y_ply, p->x_ply);
		if (a == 26)
			p->rec = 0;
		a++;
	}
	fclose(fd_trace);
	fclose(fd_vm);
	return 0;
}
