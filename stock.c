/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 18:17:24 by oes-safi          #+#    #+#             */
/*   Updated: 2019/07/20 18:17:59 by oes-safi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_index_line(char **line)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (line[i][j] == '#')
				break ;
			j++;
		}
		if (line[i][j] == '#')
			break ;
		i++;
	}
	return (i);
}

int		ft_index_colone(char **line)
{
	int i;
	int j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (line[i][j] == '#')
				break ;
			i++;
		}
		if (j < 4 && i < 4 && line[i][j] == '#')
			break ;
		j++;
	}
	return (j);
}

t_index	*change_index_line(char **line, t_index *s, int k)
{
	int				i;
	int				j;
	struct s_change	index;

	index.i = ft_index_line(line);
	index.j = ft_index_colone(line);
	s[k].l = (int *)malloc(sizeof(int) * 4);
	s[k].c = (int *)malloc(sizeof(int) * 4);
	i = 0;
	index.m = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (line[i][j] == '#')
			{
				s[k].l[index.m] = i - index.i;
				s[k].c[index.m++] = j - index.j;
			}
			j++;
		}
		i++;
	}
	return (s);
}

t_index	*ft_stock(int fd, int k, int t)
{
	char		buff[22];
	char		**line;
	char		alpha1;
	int			n;
	t_index		*s;

	alpha1 = 'A';
	s = (t_index *)malloc(sizeof(t_index) * t);
	while ((n = read(fd, buff, 21)) > 0)
	{
		buff[n] = '\0';
		line = ft_strsplit(buff, '\n');
		s = change_index_line(line, s, k);
		ft_free(line);
		s[k].alpha = alpha1;
		k++;
		alpha1++;
	}
	return (s);
}
