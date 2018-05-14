/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prsr_v.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:27:33 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/13 17:08:17 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_filler.h"

void			ft_free_tb_v(char **tb)
{
	int i;

	i = 0;
	while (tb[i])
		ft_memdel((void *)&tb[i++]);
	ft_memdel((void *)&tb[i]);
}

static void		ft_pars_map(t_visu *p)
{
	int i;

	i = p->y_map;
	if (!(p->tb_map = (char**)malloc(sizeof(char*) * (p->y_map + 1))))
		exit(ERROR_P);
	p->tb_map[i] = NULL;
	while (--i != 0)
	{
		if (!(p->tb_map[i] = (char*)malloc(sizeof(char) * (p->x_map + 1))))
			exit(ERROR_P);
		p->tb_map[i][p->x_map] = '\0';
	}
	if (!(p->tb_map[i] = (char*)malloc(sizeof(char) * (p->x_map + 1))))
		exit(ERROR_P);
	p->tb_map[i][p->x_map] = '\0';
}

void		val_tab(t_visu *p)
{
	char *line;
	int ok;

	ok = 0;
	while (get_next_line(0, &line) && ok == 0)
	{
		if (ft_strnequ("Plateau ", line, 8))
		{
			p->y_map = ft_atoi(line + 8);
			p->x_map = ft_atoi(ft_strchr(line + 8, ' '));
			ok = 1;
			if (p->x_map <= 0 || p->y_map <= 0)
				exit(ERROR_M);
			ft_pars_map(p);
		}
	}
}
