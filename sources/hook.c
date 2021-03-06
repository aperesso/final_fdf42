/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 23:47:56 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/16 11:52:34 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		update_mesh(t_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->img->ptr);
	free(mlx->img);
	mlx->img = init_img(mlx);
	clear_color(mlx->img, mlx->background);
	mlx->mesh = transform_mesh(mlx->camera, mlx->mesh);
	mlx->mesh = clip_mesh(mlx->mesh);
	mlx = mesh_to_view(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img->ptr, 0, 0);
	return (0);
}

int				expose_hook(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img->ptr, 0, 0);
	return (1);
}

int				mouse_hook(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (button == SCROLL_UP)
		mlx->camera->rx += 5;
	if (button == SCROLL_DOWN)
		mlx->camera->rx -= 5;
	update_mesh(mlx);
	return (1);
}

static t_mlx	*change_background(t_mlx *mlx)
{
	if (mlx->background == DARK)
		mlx->background = LIGHT;
	else
		mlx->background = DARK;
	return (mlx);
}

int				key_hook(int keycode, t_mlx *mlx)
{
	ft_putnbr(keycode);
	ft_putendl("");
	if (keycode == ESC)
		exit(0);
	if (keycode == LEFT)
		mlx->camera->position.x -= 1;
	if (keycode == RIGHT)
		mlx->camera->position.x += 1;
	if (keycode == UP)
		mlx->camera->position.z -= 1;
	if (keycode == DOWN)
		mlx->camera->position.z += 1;

	// if (keycode == A)
	// 	mlx->camera->ry += 10;
	// if (keycode == D)
	// 	mlx->camera->ry -= 10;
	// if (keycode == W)
	// 	mlx->camera->position.y += 10;
	// if (keycode == X)
	// 	mlx->camera->position.y -= 10;
	// if (keycode == I)
	// 	mlx->mesh->scale.y += 0.05;
	// if (keycode == O)
	// 	mlx->mesh->scale.y -= 0.05;
	// if (keycode == 49)
	// 	mlx = change_background(mlx);
	if (keycode == Q)
		mlx->camera->ry += 10;
	if (keycode == D)
		mlx->camera->ry -= 10;
	if (keycode == Z)
		mlx->camera->position.y += 10;
	if (keycode == X)
		mlx->camera->position.y -= 10;
	if (keycode == I)
		mlx->mesh->scale.y += 0.05;
	if (keycode == O)
		mlx->mesh->scale.y -= 0.05;
	if (keycode == 32)
		mlx = change_background(mlx);
	return (update_mesh(mlx));
}
