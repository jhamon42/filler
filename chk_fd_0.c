/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_fd_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:50:42 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/07 14:41:32 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"

int main(void)
{
	char *line;
	FILE *fd;

	fd = fopen("test.txt", "w");
	while(get_next_line(0, &line))
		fprintf(fd, "%s\n", line);
	free(line);
	return (0);
}