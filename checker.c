/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oes-safi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 21:00:54 by oes-safi          #+#    #+#             */
/*   Updated: 2019/07/24 13:34:00 by oes-safi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		valid_hash(char *buff)
{
	int tab[4];

	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	while (tab[3] < 21)
	{
		if (buff[tab[3]] == '.')
			tab[0] += 1;
		if (buff[tab[3]] == '#')
		{
			tab[1] += 1;
			if (buff[tab[3] - 1] == '#')
				tab[2] += 1;
			if (buff[tab[3] + 1] == '#')
				tab[2] += 1;
			if (buff[tab[3] - 5] == '#')
				tab[2] += 1;
			if (buff[tab[3] + 5] == '#')
				tab[2] += 1;
		}
		tab[3] += 1;
	}
	return (tab[0] == 12 && tab[1] == 4 && (tab[2] == 6 || tab[2] == 8));
}

int		ft_checker(int fd)
{
	char	buff[22];
	int		i;
	int		n;

	i = 0;
	while ((n = read(fd, buff, 21)) > 0)
	{
		buff[n] = '\0';
		if (buff[4] != '\n' || buff[9] != '\n' || buff[14] != '\n' \
				|| buff[19] != '\n' || (buff[20] != '\n'\
					&& buff[20] != '\0'))
			return (-1);
		if (valid_hash(buff) == 0)
			return (-1);
		i++;
	}
	if (buff[20] != '\0')
		return (-1);
	return (i);
}
