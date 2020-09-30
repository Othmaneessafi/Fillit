/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oes-safi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:19:01 by oes-safi          #+#    #+#             */
/*   Updated: 2019/07/20 21:18:47 by oes-safi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int nbr)
{
	int i;

	i = 2;
	while (i * i <= 4 * nbr)
		i++;
	return (i - 1);
}

void	ft_free(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	frees(t_index *s, int t)
{
	int i;

	i = 0;
	while (i < t)
	{
		free(s[i].l);
		free(s[i].c);
		i++;
	}
	free(s);
}

int		ft_all(int t, int fd)
{
	char		**map;
	t_back		index;
	t_index		*s;
	int			k;

	index.r = ft_sqrt(t);
	k = 0;
	s = ft_stock(fd, k, t);
	map = ft_map(index.r);
	index.tet = t;
	index.i = 0;
	index.j = 0;
	k = -1;
	while (ft_back_tracking(map, s, index, k) == 0)
	{
		ft_free(map);
		index.r++;
		map = ft_map(index.r);
	}
	ft_print_map(map, index.r);
	ft_free(map);
	frees(s, t);
	return (1);
}

int		main(int c, char **v)
{
	int t;
	int fd;

	if (c != 2)
	{
		ft_putendl("Usage: ./fillit [file_name]");
		exit(0);
	}
	fd = open(v[1], O_RDONLY);
	if (fd < 0 || (t = ft_checker(fd)) <= 0)
	{
		ft_putendl("error");
		exit(-1);
	}
	close(fd);
	if ((fd = open(v[1], O_RDONLY)) < 0)
	{
		ft_putendl("error");
		exit(-1);
	}
	ft_all(t, fd);
	exit(1);
}
