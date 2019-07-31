/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:05:37 by tamarant          #+#    #+#             */
/*   Updated: 2019/07/25 19:51:31 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zconf.h>
#include "fillit.h"

static int		map_min_size(int sum_tet, int *size)
{
	int		min_size;

	*size = 2;
	min_size = sum_tet * 4;
	while (min_size > *size * *size)
		*size += 1;
	return (*size);
}

static char 	**new_field(size)
{
	char	**field;
	int		i;
	int j = 0;

	i = 0;
	if (!(field = (char**)malloc(sizeof(char*) * (size + 1)))) ///написать ф-ю для выделения памяти под двумерный массив в либу
		return (NULL);
	while (i < size)
	{
		if (!(field[i] = ft_memalloc(size + 1)))
			return (NULL);
		while (j < size)
		{
			field[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	field[i] = NULL;
	return (field);
}

static void		free_field(char ***field, int size)
{
	int i = 0, j = 0;
	while (i < size)
	{
		free(*(*field + i));
		*(*field + i) = NULL;
		i++;
	}
	free(*field);
	*field = NULL;
}

static int		min_x(char **field, t_tet *tmp, int size) //проверяем влезает ли на поле min_x
{
	int i = 0;
	int x = 0;
	int y = 0;

	while (i < 4 && x < size) // если фигура с отрицательным иксом
	{

			if (((tmp)->points_y_x[i][1] + x) < 0)
			{
				x++;
				i = 0;
			}
			i++;
	}
	return (x);
}

/*void			write_tet_on_field(char ***field, t_tet *tmp, int x, int y, char letter)
{
	int i;
	i = 0;
	while (i < 4)
	{
		*(field[(tmp)->points_y_x[i][0] + y][(tmp)->points_y_x[i][1] + x]) = letter;
		i++;
	}
}*/ //черновик записи фигуры на поле

/*static int		is_tet_fit(char **field, t_tet *tmp, int size, int *x, int *y)
{
	int i = 0;

	while (i < 4)
	{
		if (((tmp)->points_y_x[i][0] + *y) < size || ((tmp)->points_y_x[i][1] + *x) < size)
		{
			if (field[(tmp)->points_y_x[i][0] + *y][(tmp)->points_y_x[i][1] + *x] == '.')
				i++;
			else
				if (((tmp)->points_y_x[i][1] + *x) < size)
				{
					while (i--)
						field[(tmp)->points_y_x[i][0] + *y][(tmp)->points_y_x[i][1] + *x] = '.';
					*x += 1;
					i = 0;
				}
				else if (((tmp)->points_y_x[i][0] + *y) < size)
				{
					*x = 0;
					i = 0;
					*y += 1;
				}
		}
		else
			return (0);
	}
	return (1);
}*/

static int		is_tet_fit(char **field, t_tet *tmp, int size, int *x, int *y)
{
	int i = 0;

	while (i < 4)
	{
		if (((tmp)->points_y_x[i][0] + *y) < size && ((tmp)->points_y_x[i][1] + *x) < size)
		{
			if (field[(tmp)->points_y_x[i][0] + *y][(tmp)->points_y_x[i][1] + *x] == '.')
				i++;
			else
				if ((tmp)->points_y_x[i][1] + *x + 1 < size - 1)
				{
					*x += 1;
					i = 0;
				}
				else if (((tmp)->points_y_x[i][0] + *y + 1) < size)
				{
					*y += 1;
					*x = min_x(field, tmp, size);
					i = 0;
				}
				else
					return (0);

		}
		else
			return (0);
	}
	return (1);
}

static int		place_tetrimino(t_tet *tmp, int size, char letter, char ***field) //записываем тетримин на поле
{
	int x = 0, y = 0;
	int i = 0;

	x = min_x(*field, tmp, size);
	if (is_tet_fit(*field, tmp, size, &x, &y))
	{
		while (i < 4)
		{
			*(*(*field + tmp->points_y_x[i][0] + y) + (tmp->points_y_x[i][1] + x)) = letter;
			i++;
		}
	}
	else
		return (0);
	return (1);
}

static int		move_tet(char **field, t_tet tmp, int size)
{

}

static void		next_tet(t_tet *head, int sum_tet) //переходим к следущему элементу и ставим его
{
	t_tet *tmp = head;
	char letter = 'A';
	int size = 0;
	int j = 0;
	char 	**field = new_field(map_min_size(sum_tet, &size));
	while (tmp->next)
	{
		if (place_tetrimino(tmp, size, letter, &field))
		{
			while (j < size)
			{
				printf("%s\n", field[j]); //выводим поле
				j++;
			}
			printf("\n");
			j = 0;
			letter++;
			tmp = tmp->next;
		}
	 	//if (!(place_tetrimino(tmp, size, letter, &field))) //is_tet_fit
		else
	 	{
	 		free_field(&field, size);
	 		size++;
	 		field = new_field(size);
	 		tmp = head;
	 		letter = 'A';
		}
	}
}


void 	fillit(t_tet *head, int sum_tet)
{
	int size;
	int y = 0, x = 0;
	//char 	**field = new_field(map_min_size(sum_tet, &size));

	next_tet(head, sum_tet);

}