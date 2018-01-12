/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 18:22:52 by aperesso          #+#    #+#             */
/*   Updated: 2017/04/17 18:48:40 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	size_t			k;

	i = 0;
	j = 0;
	k = ft_strlen(src);
	while (dst[i] && i < size)
		i++;
	if (size > 0)
		while (src[j] && i < size - 1)
			dst[i++] = src[j++];
	if (j > 0)
	{
		dst[i] = 0;
		return (k + i - j);
	}
	return (k + i);
}
