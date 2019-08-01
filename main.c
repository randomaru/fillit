/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:20:28 by tamarant          #+#    #+#             */
/*   Updated: 2019/08/01 18:58:14 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void print_field(char **field, int size)
{
	int		i;

	i = 0;
	if (field == NULL)
	{
		ft_putendl("ERROR");
		return ;
	}
	i = 0;
	while (i < size)
	{
		ft_putendl(field[i]);
		i++;
	}
}

static int		read_tetriminos(char *argv, char **buffer)
{
	int		fd;
	int		read_chrs;

	if (!(*(buffer) = ft_memalloc(BUFF_SIZE)))
		return (ERROR);
	if (!(fd = open(argv, O_RDONLY)))
		return (ERROR);
	if (!(read_chrs = read(fd, *buffer, BUFF_SIZE)))
		return (ERROR);
	if (read_chrs == BUFF_SIZE || read_chrs < 20)
		return (ERROR);
	close(fd);
	return (read_chrs);
}

int				main(int argc, char **argv)
{
	char	*buffer;
	int		read_chrs;
	int		sum_tet;
	t_tet	*head;

	head = NULL;
	sum_tet = 0;
	if (argc > 2)
		ft_putstr("usage: fillit target_file\n");
	else if ((read_chrs = read_tetriminos(argv[1], &buffer)) == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	else
	{
		if (is_file_valid(buffer, read_chrs, &sum_tet) == 1)
		{
			if (!(save_x_y(buffer, sum_tet, &head)))
			{
				ft_putstr("error\n");
				free(buffer);
				buffer = NULL;
				return (0);
			}
			if (!(map(head, sum_tet)))
			{
				ft_putstr("error\n");
				free_t_tet_head(&head);
				free(buffer);
				buffer = NULL;
				return (0);
			}
		}
		else
		{
			ft_putstr("error\n");
			return (0);
		}
	}
	free_t_tet_head(&head);
	///FREEEEEEEEEEEEEEEEEEEE
	free(buffer);
	buffer = NULL;

	return (1);
}
