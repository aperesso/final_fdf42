/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 13:46:54 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/10 14:47:28 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
**	load file into map and prepare the mesh to be projected by setting
**	it's position, size and rotation
*/

static t_mesh	*init_map(int ac, char **av)
{
	t_mesh	*map;
	int		i;

	if (!(map = load_map(ac, av)))
		return (NULL);
	if (!(map->color = ft_memalloc(sizeof(int) * map->vertex_count)))
		return (NULL);
	map->position = set_vector_3d(-map->vertices[map->vertex_count - 1].x / 2,
		0, -map->vertices[map->vertex_count - 1].z / 2);
	map->scale = set_vector_3d(2, 0.001f, 2);
	map->r = set_vector_3d(0, 0, 0);
	if (!(map->transformed_vertices =
			ft_memalloc(sizeof(t_vec4) * map->vertex_count)))
		return (NULL);
	i = -1;
	while (++i < map->vertex_count)
		map->transformed_vertices[i] = map->vertices[i];
	return (map);
}

/*
**	Initialisation of camera struct given it's position and rotation
*/

static t_camera	*init_camera(t_vec3 pos, t_vec3 rot)
{
	t_camera	*cam;

	if (!(cam = (t_camera *)malloc(sizeof(t_camera))))
		return (NULL);
	cam->position = pos;
	cam->rx = rot.x;
	cam->ry = rot.y;
	cam->rz = rot.z;
	return (cam);
}

/*
**	Initialisation of the minilibx
*/

static t_mlx	*init_mlx(t_camera *camera, t_mesh *mesh)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx))))
		return (NULL);
	mlx->mesh = mesh;
	mlx->camera = camera;
	if (!(mlx->ptr = mlx_init()))
		return (NULL);
	if (!(mlx->img = init_img(mlx)))
		return (NULL);
	if (!(mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "FDF")))
		return (NULL);
	return (mlx);
}

/*
**	Before we can cast a 2d drawing of a 3d mesh we need three matrices :
**  	-> Model			given by the mesh
**		-> View				given by the camera
**		-> Position			given how we want do display our mesh
*/

t_mlx			*init_all(int ac, char **av)
{
	t_mesh		*map;
	t_mlx		*mlx;
	t_camera	*camera;

	if (!(camera = init_camera(set_vector_3d(0, 40, 60),
		set_vector_3d(0, 0, 0))) || !(map = init_map(ac, av)))
		return (NULL);
	map = process_height(map);
	map = transform_mesh(camera, map);
	map = clip_mesh(map);
	if (!(mlx = init_mlx(camera, map)))
		return (NULL);
	clear_color(mlx->img, 0x111111);
	if (!(mlx->mesh->is_visible =
		malloc(sizeof(int) * mlx->mesh->vertex_count)))
	 	return (NULL);
	mlx = mesh_to_view(mlx);
	return (mlx);
}
