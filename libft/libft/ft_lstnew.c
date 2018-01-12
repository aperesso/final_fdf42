/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 00:49:19 by alexia            #+#    #+#             */
/*   Updated: 2017/04/17 17:55:15 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_content;

	if (!(new_content = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		new_content->content = NULL;
		new_content->content_size = 0;
	}
	else
	{
		if (!(new_content->content = ft_memalloc(content_size)))
			return (NULL);
		ft_memcpy(new_content->content, content, content_size);
		new_content->content_size = content_size;
	}
	new_content->next = NULL;
	return (new_content);
}
