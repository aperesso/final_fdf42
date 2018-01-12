/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:47:05 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/11 20:29:45 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/toolbox.h"

t_matrix	viewport_matrix(float x, float y, float width, float height)
{
	t_matrix	vp;
	float		f;
	float		n;

	n = 0;
	f = 1;
	vp = create_matrix();
	vp.data[0][0] = (width - x) / 2.0f;
	vp.data[0][3] = (width + x) / 2.0f;
	vp.data[1][1] = (y - height) / 2.0f;
	vp.data[1][3] = (y + height) / 2.0f;
	vp.data[2][2] = (f - n) / 2.0f;
	vp.data[2][3] = (f + n) / 2.0f;
	vp.data[3][3] = 1;
	return (vp);
}
