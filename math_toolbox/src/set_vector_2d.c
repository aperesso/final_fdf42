/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vector_2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 22:15:50 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/11 20:25:49 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/toolbox.h"

t_vec2	set_vector_2d(float x, float y)
{
	t_vec2	vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}
