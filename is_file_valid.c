/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:47:26 by tamarant          #+#    #+#             */
/*   Updated: 2019/07/31 18:11:18 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		valid_sum(char *buffer, int *valid_num) ///26 строк
{
	int x;
	int y;
	int i;

	x = 0;
	i = 0;
	y = 0;
	while (y < 4)
	{
		while (*(buffer + i) != '\n')
		{
			if (*(buffer + i) == '#')
			{
				*valid_num += 1;
				if (x < 3 && *(buffer + i + 1) == '#')
					*valid_num += 1;
				if (y < 3 && *(buffer + i + 5) == '#')
					*valid_num += 1;
			}
			i++;
			x++;
		}
		i++;
		x = 0;
		y++;
	}
}

static int		is_figure_valid(char *buffer)
{
	int i;
	int valid_num;
	int fig_num;

	i = 0;
	valid_num = -1;
	fig_num = 0;
	while (buffer[i] != '\0')
	{
		valid_sum((buffer + i), &valid_num);
		if (valid_num < 6 || valid_num > 7)
			return (ERROR);
		valid_num = -1;
		i += 21;
		fig_num++;
	}
	return (1);
}

static int		is_sum_chrs(char *buffer)
{
	int sum_sharps;
	int sum_n;
	int sum_dots;
	int i;

	sum_sharps = 0;
	sum_n = 0;
	sum_dots = 0;
	i = 0;
	while (i < 20)
	{
		if (*(buffer + i) == '.')
			sum_dots++;
		if (*(buffer + i) == '#')
			sum_sharps++;
		if (*(buffer + i) == '\n')
			sum_n++;
		i++;
	}
	if (sum_sharps == 4 && sum_n == 4 && sum_dots == 12)
		return (1);
	return (0);
}

int				is_file_valid(char *buffer, int read_chrs, int *sum_tetriminos)
{
	int i;

	i = 0;
	while (*(buffer + i) != '\0')
	{
		if (is_sum_chrs(buffer + i))
		{
			*sum_tetriminos += 1;
			if ((*(buffer + *sum_tetriminos * 20 +
				(*sum_tetriminos - 1)) == '\n' ||
				(*(buffer + *sum_tetriminos * 20 +
				(*sum_tetriminos - 1)) == '\0')))
				i += 21;
			else
				return (ERROR);
		}
		else
			return (ERROR);
	}
	if (read_chrs == *sum_tetriminos * 20 + (*sum_tetriminos - 1)
		&& is_figure_valid(buffer) == 1)
		return (1);
	return (ERROR);
}
