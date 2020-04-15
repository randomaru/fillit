/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:49:22 by tamarant          #+#    #+#             */
/*   Updated: 2019/07/19 00:56:33 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (fd >= 0 && fd <= 3)
	{
		if (n > -2147483648 && n <= 2147483647)
		{
			if (n < 0)
			{
				ft_putchar_fd('-', fd);
				ft_putnbr_fd(n * -1, fd);
			}
			else if (n > 9)
			{
				ft_putnbr_fd(n / 10, fd);
				ft_putnbr_fd(n % 10, fd);
			}
			else
				ft_putchar_fd(n + 48, fd);
		}
		if (n == -2147483648)
		{
			ft_putstr_fd("-2147483648", fd);
			return ;
		}
	}
}
