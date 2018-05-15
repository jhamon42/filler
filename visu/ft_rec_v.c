/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rec_v.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:12:30 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/15 18:12:11 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_filler.h"

static void		ft_map_rec(char *line, t_visu *p, int i_map)
{
	int i;
	int j;
	int tmp;

	j = 0;
	i = ft_strchr_int(line, ' ');
	tmp = p->x_map + (i + 1);
	while (++i < tmp)
	{
		if (line[i])
			p->tb_map[i_map][j++] = line[i];
	}
}

void			ft_rec_v(t_visu *p)
{
	static int	i_map;
	char		*line;

	while (get_next_line(0, &line))
	{
		if (p->ok == 1)
		{
			if (p->y_map - 1 == i_map)
			{
				ft_map_rec(line, p, i_map);
				i_map = 0;
				p->ok = 0;
				break ;
			}
			else
				ft_map_rec(line, p, i_map++);
		}
		else if (ft_strnequ("    ", line, 4))
			p->ok = 1;
	}
}
