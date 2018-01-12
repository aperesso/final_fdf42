/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_mesh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 13:58:29 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/12 12:21:41 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_mesh	*process_height(t_mesh *m)
{
	t_vec4	*height;
	t_vec2	range;
	int		i;

	height = m->vertices;
	range = set_vector_2d(1000, -1000);
	i = -1;
	while (++i < m->vertex_count)
		range = set_vector_2d((height[i].y < range.x) ? height[i].y : range.x,
			(height[i].y > range.y) ? height[i].y : range.y);
	i = -1;
	while (++i < m->vertex_count)
	{
		m->transformed_vertices[i].y = map(height[i].y, range,
			set_vector_2d(0, 1));
		if (m->transformed_vertices[i].y < 0.01f)
			m->color[i] = 0x3232ff;
		else if (m->transformed_vertices[i].y < 0.5f)
			m->color[i] = 0x003300;
		else if (m->transformed_vertices[i].y < 0.7f)
			m->color[i] = 0x26120D;
		else
			m->color[i] = 0xeeeeee;
	}
	return (m);
}

t_mesh		*transform_mesh(t_camera *cam, t_mesh *mesh)
{
	t_matrix	model;
	t_matrix	view;
	t_matrix	proj;
	t_vec4		*tmp;
	int			i;

	model = create_transformation_matrix(mesh->position, mesh->r, mesh->scale);
	view = create_view_matrix(cam->position, cam->rx, cam->ry, cam->rz);
	proj = create_projection_matrix((float) WIDTH / HEIGHT, FOV, NEAR_PLANE, FAR_PLANE);
	i = -1;
	tmp = mesh->vertices;
	while (++i < mesh->vertex_count)
	{
		mesh->transformed_vertices[i] = mult_matrix_vector(model,
				mesh->vertices[i]);
		mesh->transformed_vertices[i] = mult_matrix_vector(view,
				mesh->transformed_vertices[i]);
		mesh->transformed_vertices[i] = mult_matrix_vector(proj,
				mesh->transformed_vertices[i]);
	}
	mesh->vertices = tmp;
	return (mesh);
}

t_mesh		*clip_mesh(t_mesh *m)
{
	t_mesh	*mesh;
	int		i;

	mesh = m;
	i = -1;
	while (++i < m->vertex_count)
		if (m->transformed_vertices[i].w)
		{
			mesh->transformed_vertices[i].x /= mesh->transformed_vertices[i].w;
			mesh->transformed_vertices[i].y /= mesh->transformed_vertices[i].w;
			mesh->transformed_vertices[i].z /= mesh->transformed_vertices[i].w;
			mesh->transformed_vertices[i].w /= mesh->transformed_vertices[i].w;
		}
	return (mesh);
}

static t_mlx	*display_mesh(t_mlx *mlx)
{
	t_vec4	*v;
	t_vec3	i;
	int		*visible;
	int		c;

	v = mlx->mesh->transformed_vertices;
	visible = mlx->mesh->is_visible;
	i = set_vector_3d(-1, -1, 0);
	c = mlx->mesh->col;
/* 	while (++i.x < mlx->mesh->row)
	{
		i.y = -1;
		while (++i.y < c - 1)
		{
			if (visible[(int)i.z] && visible[(int)i.z + 1])
				mlx->img = line(mlx->img, set_vector_2d(v[(int)i.z].x, v[(int)i.z].y),
					set_vector_2d(v[(int)i.z + 1].x, v[(int)i.z + 1].y),
					mlx->mesh->color[(int)i.z]);
			if (i.x < mlx->mesh->row -1 && visible[(int)i.z] && visible[(int)i.z + c])
				mlx->img = line(mlx->img, set_vector_2d(v[(int)i.z].x, v[(int)i.z].y),
					set_vector_2d(v[(int)i.z + c].x, v[(int)i.z + c].y),
					mlx->mesh->color[(int)i.z]);
			i.z++;
		}
		if (i.x < mlx->mesh->row -1 && visible[(int)i.z] && visible[(int)i.z + c])
			mlx->img = line(mlx->img, set_vector_2d(v[(int)i.z].x, v[(int)i.z].y),
				set_vector_2d(v[(int)i.z + c].x, v[(int)i.z + c].y),
				mlx->mesh->color[(int)i.z]);
		i.z++;
	} */
	while (++i.x < mlx->mesh->vertex_count)
	{
		if (visible[(int)i.x])
			mlx->img = fill_img_pixel(mlx->img, mlx->mesh->color[(int)i.x], v[(int)i.x].x, v[(int)i.x].y);
	}
	return (mlx);
}

t_mlx		*mesh_to_view(t_mlx *mlx)
{
	t_mesh		*mesh;
	t_vec4		*vertices;
	t_matrix	viewport;
	int			v;

	viewport = viewport_matrix(0, 0, WIDTH, HEIGHT);
	mesh = mlx->mesh;
	vertices = mesh->transformed_vertices;
	v = -1;
	while (++v < mesh->vertex_count)
	{
		mesh->is_visible[v] = 0;
		if (vertices[v].w == 1)
		{
			vertices[v] = mult_matrix_vector(viewport, vertices[v]);
			vertices[v].x = roundf(vertices[v].x);
			vertices[v].y = roundf(vertices[v].y);
			if (vertices[v].z < 1 && vertices[v].z > -1)
				mesh->is_visible[v] = 1;
		}
	}
	return (display_mesh(mlx));
}
