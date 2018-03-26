/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:53:08 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/26 17:02:52 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int main(int ac, char const *av[])
{
	int fd;
	int i = 0;
	char *line;
	if (ac || av)
		;
	while (get_next_line(1, &line))
	{
		i++;
		if (ft_strequ("quit", line))
			break;
	}
	printf("%d\n", i);
	return 0;
}
