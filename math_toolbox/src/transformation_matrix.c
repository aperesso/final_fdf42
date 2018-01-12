/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_matrix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 23:12:00 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/11 20:27:34 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/toolbox.h"

t_matrix	create_transformation_matrix(t_vec3 translation, t_vec3 rotate,
				t_vec3 s)
{
	t_matrix	mat;

	mat = scale(s.x, s.y, s.z);
	mat = mult_matrix(rotatex(rotate.x), mat);
	mat = mult_matrix(rotatey(rotate.y), mat);
	mat = mult_matrix(rotatez(rotate.z), mat);
	mat = mult_matrix(translate(translation.x, translation.y, translation.z),
		mat);
	return (mat);
}
