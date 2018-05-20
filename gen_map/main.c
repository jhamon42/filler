/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:48:40 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/20 01:49:54 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gen_map.h"

static void		mini_verif(int *y, int *x, char *str)
{
	if (ft_strlen(str) > 2)
	{
		*y = ft_atoi(str);
		if (ft_strchr(str, ' '))
			*x = ft_atoi(ft_strchr(str, ' '));
		else
			exit(ERR_U);
	}
	else
		exit(ERR_U);
}

static int		verif_coord(int n, t_gen *p, ...)
{
	va_list	ap;
	char	*str;
	int		v;

	v = n;
	va_start(ap, p);
	str = va_arg(ap, char*);
	mini_verif(&p->y_map, &p->x_map, str);
	while (--n)
	{
		str = va_arg(ap, char*);
		if (p->p1 == 1 && n == 1)
			mini_verif(&p->y_p1, &p->x_p1, str);
		if (p->p1 == 2 && n == 2)
			mini_verif(&p->y_p1, &p->x_p1, str);
		if (p->p2 == 1 && n == 1)
			mini_verif(&p->y_p2, &p->x_p2, str);
		if (p->p2 == 2 && n == 2)
			mini_verif(&p->y_p2, &p->x_p2, str);
	}
	va_end(ap);
	return (1);
}

static int		verif_option(int n, t_gen *p, ...)
{
	va_list	ap;
	char	*str;

	va_start(ap, p);
	while (n--)
	{
		str = va_arg(ap, char*);
		if (ft_strequ(str, "-p2"))
			p->p2 = n + 1;
		else if (ft_strequ(str, "-p1"))
			p->p1 = n + 1;
		else
			exit(ERR_U);
	}
	va_end(ap);
	return (1);
}

static void		init_t_gen(t_gen *p)
{
	p->fd = fopen("map_custom", "w");
	p->x_map = 0;
	p->y_map = 0;
	p->x_p1 = 3;
	p->y_p1 = 3;
	p->x_p2 = 0;
	p->y_p2 = 0;
	p->p1 = 0;
	p->p2 = 0;
}

int				main(int ac, char **av)
{
	t_gen strct;
	t_gen *p;

	p = &strct;
	init_t_gen(p);
	if (ac < 2 || ac > 6 || ac % 2 == 1)
		exit(ERR_U);
	else if (ac == 2)
	{
		if (verif_coord(1, p, av[1]))
			write_map(p);
	}
	else if (ac == 4)
	{
		if (verif_option(1, p, av[2]) && verif_coord(2, p, av[1], av[3]))
			write_map(p);
	}
	else
	{
		if (verif_option(2, p, av[2], av[4]) && \
		verif_coord(3, p, av[1], av[3], av[5]))
			write_map(p);
	}
	return (0);
}
