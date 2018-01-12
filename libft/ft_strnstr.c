/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexia <alexia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 18:09:52 by aperesso          #+#    #+#             */
/*   Updated: 2017/04/18 21:55:31 by alexia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *beggin, const char *little, size_t len)
{
	if (*beggin == '\0' && *little)
		return (NULL);
	if (!(*little))
		return ((char *)beggin);
	while (*beggin)
	{
		if (!len || ft_strlen(little) > len)
			return (NULL);
		if (ft_strncmp(beggin, little, ft_strlen(little)) == 0)
			return ((char *)beggin);
		beggin++;
		len--;
	}
	return(NULL);
}
