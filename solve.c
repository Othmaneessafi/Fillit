/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oes-safi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:53:36 by oes-safi          #+#    #+#             */
/*   Updated: 2019/07/20 20:56:30 by oes-safi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_and_put(char **map, t_index *s, t_back index, int k)
{
	if (map[s[k].l[0] + index.i] == NULL || \
			map[s[k].l[1] + index.i] == NULL || \
			map[s[k].l[2] + index.i] == NULL || \
			map[s[k].l[3] + index.i] == NULL)
		return (0);
	if (map[s[k].l[0] + index.i][s[k].c[0] + index.j] == '.' && \
			map[s[k].l[1] + index.i][s[k].c[1] + index.j] == '.' && \
			map[s[k].l[2] + index.i][s[k].c[2] + index.j] == '.' && \
			map[s[k].l[3] + index.i][s[k].c[3] + index.j] == '.')
	{
		map[s[k].l[0] + index.i][s[k].c[0] + index.j] = s[k].alpha;
		map[s[k].l[1] + index.i][s[k].c[1] + index.j] = s[k].alpha;
		map[s[k].l[2] + index.i][s[k].c[2] + index.j] = s[k].alpha;
		map[s[k].l[3] + index.i][s[k].c[3] + index.j] = s[k].alpha;
		return (1);
	}
	return (0);
}

void	ft_remove(char **map, t_index *s, t_back index, int k)
{
	map[s[k].l[0] + index.i][s[k].c[0] + index.j] = '.';
	map[s[k].l[1] + index.i][s[k].c[1] + index.j] = '.';
	map[s[k].l[2] + index.i][s[k].c[2] + index.j] = '.';
	map[s[k].l[3] + index.i][s[k].c[3] + index.j] = '.';
}

void	ft_print_map(char **map, int r)
{
	int i;

	i = 0;
	while (i < r)
		ft_putendl(map[i++]);
}

int		ft_back_tracking(char **map, t_index *s, t_back index, int k)
{
	++k;
	if (k == index.tet)
		return (1);
	index.i = 0;
	while (index.i < index.r)
	{
		index.j = 0;
		while (index.j < index.r)
		{
			if (ft_check_and_put(map, s, index, k) == 1)
			{
				if (ft_back_tracking(map, s, index, k) == 1)
					return (1);
				ft_remove(map, s, index, k);
			}
			index.j++;
		}
		index.i++;
	}
	return (0);
}
