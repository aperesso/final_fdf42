/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:08:57 by fel-mazo          #+#    #+#             */
/*   Updated: 2018/01/16 13:20:19 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memchri(const void *s, int c, size_t n)
{
	unsigned char	*ret;
	int				i;
	int				in;
	unsigned char	cc;

	cc = (unsigned char)c;
	ret = (unsigned char*)s;
	i = 0;
	in = (int)n;
	while (i++ < in)
	{
		if (*(ret) == cc)
			return (i);
		ret++;
	}
	return (-1);
}