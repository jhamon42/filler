/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prsr_v.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:27:33 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/20 02:44:04 by jhamon           ###   ########.fr       */
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

static int		vrf_head(char *line, int nok)
{
	if (nok > 4)
		return (0);
	else if (ft_strnequ("# -------------- VM  version 1.1 ------------- #",\
	line, 48) && nok == 0)
		return (0);
	else if (ft_strnequ("#                                              #",\
	line, 48) && nok == 1)
		return (0);
	else if (ft_strnequ("# 42 / filler VM Developped by: Hcao - Abanlin #",\
	line, 48) && nok == 2)
		return (0);
	else if (ft_strnequ("#                                              #",\
	line, 48) && nok == 3)
		return (0);
	else if (ft_strnequ("# -------------------------------------------- #",\
	line, 48) && nok == 4)
		return (0);
	return (1);
}

void			val_tab(t_visu *p)
{
	char	*line;
	int		ok;
	int		nok;

	ok = 0;
	nok = -1;
	while (ok == 0 && get_next_line(0, &line))
	{
		if (vrf_head(line, ++nok))
			exit(ERROR_V);
		if (ft_strnequ("Plateau ", line, 8))
		{
			p->y_map = ft_atoi(line + 8);
			p->x_map = ft_atoi(ft_strchr(line + 8, ' '));
			ok = 1;
			if (p->x_map <= 14 || p->y_map <= 14 || \
				p->x_map > 480 || p->y_map > 270)
				exit(ERROR_M);
			ft_pars_map(p);
		}
		free(line);
	}
}
