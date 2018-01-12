/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 13:46:54 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/12 11:45:33 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_img	*init_img(t_mlx *mlx)
{
	t_img	*image;

	if (!(image = (t_img *)ft_memalloc(sizeof(t_img))))
		return (NULL);
	image->ptr = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	image->data = (int *)mlx_get_data_addr(image->ptr, &(image->bpp),
		&(image->sl), &(image->endian));
	return (image);
}

void		clear_color(t_img *img, int color)
{
	int i;

	i = -1;
	while(i++ < HEIGHT * WIDTH)
		img->data[i] = color;
}

t_img		*fill_img_pixel(t_img *img, int color, int x, int y)
{
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
		img->data[y * WIDTH + x] = color; 
	return (img);
}
