/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexia <alexia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 22:17:36 by alexia            #+#    #+#             */
/*   Updated: 2017/04/14 12:15:03 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	unsigned const char		*src_;
	unsigned char			*dst_;

	src_ = (unsigned const char *)src;
	dst_ = (unsigned char *)dst;
	while (*src_)
		*dst_++ = *src_++;
	*dst_ = '\0';
	return (dst);
}
