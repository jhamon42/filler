/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:15:43 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/18 19:27:47 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int		main(void)
{
	FILE *fd;
	char *line;

	fd = fopen("trace_parti.txt", "w");
	while (get_next_line(0, &line))
	{
		fprintf(fd, "%s\n", line);
		free(line);
	}
	free(line);
	fclose(fd);
	return (0);
}
