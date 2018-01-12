/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printVertices.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 00:04:03 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/11 16:42:25 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/toolbox.h"

void	printVertices(t_mesh *m)
{
	int		i;

	i = -1;
	while ( ++i < m->vertex_count)
		printf("x : %f, y : %f, z: %f, w: %f -- x : %f, y : %f, z: %f, w: %f\n", m->vertices[i].x,
			 m->vertices[i].y, m->vertices[i].z, m->vertices[i].w, m->transformed_vertices[i].x,
			 m->transformed_vertices[i].y, m->transformed_vertices[i].z, m->transformed_vertices[i].w);
}