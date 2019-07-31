/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:25:42 by tamarant          #+#    #+#             */
/*   Updated: 2019/07/31 17:59:48 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**remove_tetri(char **t_field, t_tet *tmp)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if ((t_field[(tmp)->points_y_x[i][0] + tmp->map_y]
					[(tmp)->points_y_x[i][1] + tmp->map_x]) != '.')
			t_field[(tmp)->points_y_x[i][0] + tmp->map_y]
					[(tmp)->points_y_x[i][1] + tmp->map_x] = '.';
		i++;
	}
	return (t_field);
}
