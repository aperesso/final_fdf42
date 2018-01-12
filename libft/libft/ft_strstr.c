/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexia <alexia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 17:46:08 by aperesso          #+#    #+#             */
/*   Updated: 2017/04/18 21:56:27 by alexia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	if (ft_strlen(to_find) == 0)
		return ((char *)str);
	if (ft_strlen(str) != 0)
	{
		while (*str)
		{
			if (ft_strncmp(str, to_find, ft_strlen(to_find)) == 0)
				return ((char *)str);
			str++;
		}
	}
	return (NULL);
}
