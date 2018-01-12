/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 23:40:17 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/11 20:24:19 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/toolbox.h"

t_matrix	create_projection_matrix(float aspect, float fov, float far,
				float near)
{
	t_matrix	p;
	float		f;

	f = 1.0f / tan(DEGREESTORADIANS(fov / 2.0f));
	p = create_matrix();
	p.data[0][0] = f;
	p.data[1][1] = f / aspect;
	p.data[2][2] = -(far + near) / (far - near);
	p.data[2][3] = -(2 * far * near) / (far - near);
	p.data[3][2] = -1;
	return (p);
}
