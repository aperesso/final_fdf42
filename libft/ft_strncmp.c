/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexia <alexia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 23:47:11 by aperesso          #+#    #+#             */
/*   Updated: 2017/04/14 12:19:09 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char		*s1_;
	const unsigned char		*s2_;

	s1_ = (const unsigned char *)s1;
	s2_ = (const unsigned char *)s2;
	while (n-- > 0)
	{
		if (*s1_ != *s2_)
			return (*s1_ - *s2_);
		else if (*s1_ == '\0')
			return (0);
		s1_++;
		s2_++;
	}
	return (0);
}
