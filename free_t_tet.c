/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_t_tet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:08:18 by tamarant          #+#    #+#             */
/*   Updated: 2019/07/31 18:08:18 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		free_arr_points(int ***arr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		free(*(*arr + i));
		*(*arr + i) = NULL;
		i++;
	}
	free(*arr);
	*arr = NULL;
}

void		free_t_tet(t_tet **tmp)
{
	t_tet *prev_lst;

	while (*tmp)
	{
		prev_lst = (*tmp)->prev;
		free_arr_points(&(*tmp)->points_y_x);
		(*tmp)->y_min = 0;
		(*tmp)->x_min = 0;
		(*tmp)->prev = NULL;
		(*tmp)->next = NULL;
		free(*tmp);
		*tmp = prev_lst;
	}
}
