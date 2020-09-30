/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oes-safi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 15:24:42 by oes-safi          #+#    #+#             */
/*   Updated: 2019/07/26 20:17:19 by oes-safi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include "libft/libft.h"

typedef struct	s_index
{
	int		*l;
	int		*c;
	char	alpha;
}				t_index;

typedef	struct	s_back
{
	int	i;
	int	j;
	int	tet;
	int	r;
}				t_back;

typedef struct	s_change
{
	int	m;
	int	i;
	int	j;
}				t_change;

void			frees(t_index *s, int t);
int				ft_checker(int fd);
void			ft_free(char **map);
t_index			*change_index_line(char **line, t_index *s, int k);
int				ft_index_line(char **line);
int				ft_index_colone(char **line);
t_index			*ft_stock(int fd, int k, int t);
int				ft_all(int t, int fd);
int				ft_back_tracking(char **map, t_index *s, t_back index, int k);
void			ft_print_map(char **map, int r);
void			ft_print_map(char **map, int r);
void			ft_remove(char **map, t_index *s, t_back index, int k);
char			**ft_map(int r);
int				ft_check_and_put(char **map, t_index *s, t_back index, int k);
int				ft_sqrt(int nbr);

#endif
