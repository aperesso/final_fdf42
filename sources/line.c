/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 13:46:54 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/13 15:46:24 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_img	*x_over_y(t_img *img, t_point *line_tools, int color)
{
	int		d_;
	t_point d;
	int		i;
	t_point	p;

	d_ = (line_tools[2].y << 1) - line_tools[2].x;
	d.x = (line_tools[2].y << 1);
	d.y = (line_tools[2].y - line_tools[2].x) << 1;
	img = fill_img_pixel(img, color, line_tools[0].x, line_tools[0].y);
	p.x = line_tools[0].x + line_tools[3].x;
	p.y = line_tools[0].y;
	i = 0;
	while (++i <= line_tools[2].x)
	{
		if (d_ > 0)
		{
			d_ += d.y;
			p.y += line_tools[3].y;
		}
		else
			d_ += d.x;
		img = fill_img_pixel(img, color, p.x, p.y);
		p.x += line_tools[3].x;
	}
	return (img);
}

static t_img	*y_over_x(t_img *img, t_point *line_tools, int color)
{
	int		d_;
	t_point	d;
	int		i;
	t_point p;

	d_ = (line_tools[2].x << 1) - line_tools[2].y;
	d.x = (line_tools[2].x) << 1;
	d.y = (line_tools[2].x - line_tools[2].y) << 1;
	img = fill_img_pixel(img, color, line_tools[0].x, line_tools[0].y);
	i = 0;
	p.x = line_tools[0].x;
	p.y = line_tools[0].y + line_tools[3].y;
	while (++i <= line_tools[2].y)
	{
		if (d_ > 0)
		{
			d_ += d.y;
			p.x += line_tools[3].x;
		}
		else
			d_ += d.x;
		img = fill_img_pixel(img, color, p.x, p.y);
		p.y += line_tools[3].y;
	}
	return (img);
}

/*
**	Implementation of bresenham algorithm generalized to the eight octant
**	It's not the prettiest one, but it works !
** 	line_tools[0] = a
** 	line_tools[1] = b
**	line_tools[2] = dist = abs(line_tools[1] - line_tools[0])
** 	line_tools[3] = comparision between a et b
*/

t_img			*line(t_img *img, t_vec2 a, t_vec2 b, int color)
{
	t_point	*line_tools;

	if (!(line_tools = ft_memalloc(sizeof(t_point) * 4)))
		return (NULL);
	line_tools[0].x = a.x;
	line_tools[0].y = a.y;
	line_tools[1].x = b.x;
	line_tools[1].y = b.y;
	line_tools[2].x = abs(line_tools[1].x - line_tools[0].x);
	line_tools[2].y = abs(line_tools[1].y - line_tools[0].y);
	line_tools[3].x = line_tools[1].x >= line_tools[0].x ? 1 : -1;
	line_tools[3].y = line_tools[1].y >= line_tools[0].y ? 1 : -1;
	if (line_tools[2].y <= line_tools[2].x)
		img = x_over_y(img, line_tools, color);
	else
		img = y_over_x(img, line_tools, color);
	return (img);
}
