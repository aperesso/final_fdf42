/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexia <alexia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 20:29:50 by alexia            #+#    #+#             */
/*   Updated: 2017/04/14 12:06:25 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char		*str;
	char			c_;
	size_t			i;

	str = s;
	c_ = c;
	i = 0;
	while (n--)
	{
		if (str[i] == c_)
			return ((void*)(s + i));
		i++;
	}
	return (NULL);
}
