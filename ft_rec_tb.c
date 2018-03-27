/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rec_tb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:30:03 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/27 16:52:04 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 #include "filler.h"

void			ft_rec_tb(char *line, t_filler *p, int la)
{
	static int vue;

	if (vue == 0)
	{
		if (ft_strnequ("Plateau", line, 7))
		{
			p->y_map = ft_atoi(line + 8);
			p->x_map = ft_atoi(ft_strchr(line + 8, ' '));
			if (p->x_map <= 0 || p->y_map <= 0)
				exit(ERROR_M);
			//ft_pars_tab(p);
			vue++;
		}
		else if (ft_strnequ("$$$ exec p1", line, 11))
			p->ply = 'O';
		else if (ft_strnequ("$$$ exec p2", line, 11))
			p->ply = 'X';
	}
	else
	{
		if (ft_strnequ("Plateau", line, 7))
			p->rec = 1;
		if (la)
			;
	}
}
