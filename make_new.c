/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 17:48:40 by tamarant          #+#    #+#             */
/*   Updated: 2019/08/01 14:06:36 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		**new_arr_points(void)
{
	int		**new;
	int		i;

	i = 0;
	if (!(new = (int**)malloc(4 * sizeof(int*))))
		return (NULL);
	while (i < 4)
	{
		new[i] = (int*)malloc(2 * sizeof(int));
		i++;
	}
	return (new);
}

t_tet			*new_tet_points(char letter)
{
	t_tet *new;

	if (!(new = (t_tet*)malloc(sizeof(t_tet))))
		return (NULL);
	new->points_y_x = new_arr_points();
	new->map_y = 0;
	new->map_x = 0;
	new->y_min = -1;
	new->x_min = -1;
	new->next = NULL;
	new->prev = NULL;
	new->letter = letter;
	return (new);
}

char			**new_field(char **field, int size)
{
	int		x;
	int		y;

	y = 0;
	if (!(field = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	while (y < size)
	{
		if (!(field[y] = ft_memalloc(size + 1))) //(char *)malloc(sizeof(char) * size + 1)))
			return (NULL);
		x = 0;
		while (x < size)
			field[y][x++] = '.';
		field[y][x] = '\0';
		y++;
	}
	ft_bzero(&field[y], size + 1);
	return (field);
}
