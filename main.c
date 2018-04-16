/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:53:08 by jhamon            #+#    #+#             */
/*   Updated: 2018/04/06 07:13:45 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		print_t(t_filler *p, FILE *fd)
{
	int i = -1;
	int j = -1;
	fprintf(fd, "\n--tab map--\n\n");
	while (++i < p->y_map)
	{
		while (++j < p->x_map)
		{
			fprintf(fd, "%c", p->tb_map[i][j]);
		}
		fprintf(fd, "\n");
		j = -1;
	}
	i = -1;
	fprintf(fd, "\n--tab pce--\n\n");
	while (++i < p->y_pce)
	{
		while (++j < p->x_pce)
		{
			fprintf(fd, "%c", p->tb_pce[i][j]);
		}
		fprintf(fd, "\n");
		j = -1;
	}
	fprintf(fd, "\n------------------------\n");
}

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
	p->phase = 1;
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
	p->fd_vm = fopen("trace_vm.txt", "w");
	p->fd_trace = fopen("trace_moi.txt", "w");
	while (get_next_line(0, &line) > 0)
	{
		if (p->rec == 1 || p->rec == 2)
			ft_rec_tb(line, p);
		if (p->rec == 0)
			ft_parseur(line, p);
		if (p->rec == 3)
		{
			usleep(75000);
			fprintf(p->fd_trace, "\n------------------------\n------------------------\n");
			ft_rsv_flr(p);
			fprintf(p->fd_trace, "player : %c Tableau : %d %d\n", \
			p->ply, p->y_map, p->x_map);
			fprintf(p->fd_trace, "piece : %d %d\n", p->y_pce, p->x_pce);
			print_t(p, p->fd_trace);
			p->vue_prs = 0;
			p->rec = 0;
		}
		fputs(line, p->fd_vm);
		fputs("\n", p->fd_vm);
	}
	if (p->tb_map)
		ft_free_tb(p->tb_map);
	if (p->tb_pce)
		ft_free_tb(p->tb_pce);
	fclose(p->fd_trace);
	fclose(p->fd_vm);
	return 0;
}
