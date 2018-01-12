/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_mesh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 23:54:31 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/11 20:22:55 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/toolbox.h"

t_mesh		new_mesh(int vertexcount, t_vec4 *vertices)
{
	t_mesh	m;

	m.vertex_count = vertexcount;
	m.vertices = vertices;
	return (m);
}
