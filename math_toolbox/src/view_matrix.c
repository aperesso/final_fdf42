/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 23:30:59 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/11 20:30:21 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/toolbox.h"

t_matrix	create_view_matrix(t_vec3 position, float rx, float ry, float rz)
{
	t_matrix	mat;
	t_vec3		camera_pos;

	mat = set_identity();
	mat = mult_matrix(rotatex(rx), mat);
	mat = mult_matrix(rotatey(ry), mat);
	mat = mult_matrix(rotatez(rz), mat);
	camera_pos.x = -position.x;
	camera_pos.y = -position.y;
	camera_pos.z = -position.z;
	mat = mult_matrix(translate(camera_pos.x, camera_pos.y, camera_pos.z),
		mat);
	return (mat);
}
