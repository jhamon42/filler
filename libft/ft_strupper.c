/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 20:44:06 by jhamon            #+#    #+#             */
/*   Updated: 2018/03/08 18:46:10 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strupper(char *tmp)
{
	int i;

	i = 0;
	while (tmp[i] != '\0')
	{
		if (!(tmp[i] < 97 || tmp[i] > 122))
			tmp[i] -= 32;
		i++;
	}
}