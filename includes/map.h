/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/20 18:03:51 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 19:14:11 by fdumas      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "square.h"

typedef struct	s_map
{
	int			size;
	char		empty;
	char		full;
	char		obstacle;
	int			**cells;
	t_square	**squares;
	int			biggest_index;
}				t_map;

int				ft_fill_map(char *map_buffer, t_map *map);

int				ft_display_map(char *map_buffer, t_map *map);
#endif
