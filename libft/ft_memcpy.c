/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 20:23:45 by tamarant          #+#    #+#             */
/*   Updated: 2019/07/19 00:56:33 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s1;
	char	*s2;
	int		i;

	s1 = (char*)dst;
	s2 = (char*)src;
	i = 0;
	while (n--)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dst);
}
