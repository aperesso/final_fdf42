/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 21:50:46 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/11 20:22:33 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/toolbox.h"

t_matrix	mult_matrix(t_matrix a, t_matrix b)
{
	t_matrix	c;
	int			i;
	int			j;
	int			k;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			c.data[i][j] = 0;
			while (++k < 4)
				c.data[i][j] += a.data[i][k] * b.data[k][j];
		}
	}
	return (c);
}

t_vec4		mult_matrix_vector(t_matrix a, t_vec4 v)
{
	t_vec4		m;

	m.x = a.data[0][0] * v.x + a.data[0][1] * v.y +
			a.data[0][2] * v.z + a.data[0][3] * v.w;
	m.y = a.data[1][0] * v.x + a.data[1][1] * v.y +
			a.data[1][2] * v.z + a.data[1][3] * v.w;
	m.z = a.data[2][0] * v.x + a.data[2][1] * v.y +
			a.data[2][2] * v.z + a.data[2][3] * v.w;
	m.w = a.data[3][0] * v.x + a.data[3][1] * v.y +
			a.data[3][2] * v.z + a.data[3][3] * v.w;
	return (m);
}
