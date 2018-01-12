/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexia <alexia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 22:29:25 by aperesso          #+#    #+#             */
/*   Updated: 2017/04/14 12:11:51 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char		*s1_;
	const unsigned char		*s2_;

	s1_ = (const unsigned char *)s1;
	s2_ = (const unsigned char *)s2;
	while (*s1_ == *s2_ && *s1_ != '\0' && *s2_ != '\0')
	{
		s1_++;
		s2_++;
	}
	return (*s1_ - *s2_);
}
