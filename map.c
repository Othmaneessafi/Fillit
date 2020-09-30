/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oes-safi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 18:16:30 by oes-safi          #+#    #+#             */
/*   Updated: 2019/07/20 20:59:08 by oes-safi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_map(int r)
{
	char	**p;
	int		i;
	int		j;

	p = (char **)malloc(sizeof(char *) * (r + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (i < r)
	{
		p[i] = (char *)malloc(sizeof(char) * (r + 1));
		j = 0;
		while (j < r)
		{
			p[i][j] = '.';
			j++;
		}
		p[i][j] = '\0';
		i++;
	}
	p[i] = NULL;
	return (p);
}
