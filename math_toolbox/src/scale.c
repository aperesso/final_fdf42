/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 22:29:29 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/11 20:25:18 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/toolbox.h"

t_matrix	scale(float sx, float sy, float sz)
{
	t_matrix	s;

	s = set_identity();
	s.data[0][0] = sx;
	s.data[1][1] = sy;
	s.data[2][2] = sz;
	return (s);
}
