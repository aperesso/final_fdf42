/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 13:46:54 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/10 14:47:28 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_img	*iterate_line(t_img *img, t_vec4 a_ls, t_vec4 d, int color)
{
	t_vec2 	d1;
	t_vec2	d2;
	int		numerator;
	int		i;

	d1 = set_vector_2d(d.x, d.y);
	d2 = set_vector_2d(d.z, d.w);
	numerator = ceil(a_ls.z / 2);
	i = 0;
	while (i < a_ls.z)
    {
        img = fill_img_pixel(img, color, a_ls.x, a_ls.y);
        numerator += a_ls.w;
        if (!(numerator < a_ls.z))
        {
        	numerator -= a_ls.z;
            a_ls.x += d1.x;
            a_ls.y += d1.y;
        }
        else
        {
            a_ls.x += d2.x;
            a_ls.y += d2.y;
        }
        i++;
    }
  	return (img);
}

t_img		*line(t_img *img, t_vec2 a, t_vec2 b, int color)
{
	t_vec2	w_h;
	t_vec2	d1;
	t_vec2	d2;
	t_vec2	l_s;

	w_h = set_vector_2d(b.x - a.x, b.y - a.y);
	d1 = set_vector_2d(0, 0);
	d2 = set_vector_2d(0, 0);
	d1.x = (w_h.x < 0) ? -1 : 1;
	d1.y = (w_h.y < 0) ? -1 : 1;
	d2.x = (w_h.x < 0) ? -1 : 1;;
	l_s = set_vector_2d(fabsf(w_h.x), fabs(w_h.y));
	if (!(l_s.x > l_s.y))
	{
		l_s = set_vector_2d(fabsf(w_h.x), fabsf(w_h.y));
		d2 = set_vector_2d(0, (w_h.y < 0) ? -1 : 1);
	}
	img = iterate_line(img, set_vector_4d(a.x, a.y, l_s.x, l_s.y),
		set_vector_4d(d1.x, d1.y, d2.x, d2.y), color);
	return (img);
}
