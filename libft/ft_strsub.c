/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:53:02 by tamarant          #+#    #+#             */
/*   Updated: 2019/07/19 00:56:33 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(sub = (char*)malloc(sizeof(*sub) * (len + 1))))
		return (NULL);
	while (i < len)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
