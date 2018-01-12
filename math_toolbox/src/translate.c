/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 21:57:06 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/11 20:28:00 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/toolbox.h"

t_matrix	translate(float x, float y, float z)
{
	t_matrix	translate;

	translate = set_identity();
	translate.data[0][3] = x;
	translate.data[1][3] = y;
	translate.data[2][3] = z;
	return (translate);
}
