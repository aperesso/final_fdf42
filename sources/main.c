/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:00:37 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/16 12:10:23 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			main(int ac, char **av)
{
	t_mlx		*mlx;

	if (!(mlx = init_all(ac, av)))
		return (EXIT_FAILURE);
	mlx_hook(mlx->win, 2, 3, key_hook, mlx);
	mlx_hook(mlx->win, 4, (1L << 2), mouse_hook, mlx);
	mlx_expose_hook(mlx->win, expose_hook, mlx);
	mlx_loop(mlx->ptr);
	return (EXIT_SUCCESS);
}
