/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:54:00 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/13 15:56:34 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLBOX_H
# define TOOLBOX_H
# define DEGREESTORADIANS(angleDegrees) (angleDegrees * M_PI / 180.0)
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_matrix
{
	float			data[4][4];
}					t_matrix;
typedef struct		s_vec2
{
	float			x;
	float			y;
}					t_vec2;
typedef struct		s_vec3
{
	float			x;
	float			y;
	float			z;
}					t_vec3;
typedef struct		s_vec4
{
	float			x;
	float			y;
	float			z;
	float			w;
}					t_vec4;
typedef struct		s_mesh
{
	t_vec3			position;
	t_vec3			scale;
	t_vec3			r;
	int				vertex_count;
	struct s_vec4	*vertices;
	struct s_vec4	*transformed_vertices;
	int				*color;
	int				*is_visible;
	int				row;
	int				col;
}					t_mesh;
t_matrix			create_matrix(void);
void				display_matrix(t_matrix	matrix);
t_matrix			set_identity(void);
t_matrix			mult_matrix(t_matrix a, t_matrix b);
t_matrix			translate(float x, float y, float z);
t_matrix			rotatex(float t);
t_matrix			rotatey(float t);
t_matrix			rotatez(float t);
t_matrix			scale(float sx, float sy, float sz);
t_vec4				mult_matrix_vector(t_matrix a, t_vec4	v);
t_matrix			create_transformation_matrix(t_vec3 translation,
						t_vec3 rotate, t_vec3 scale);
t_matrix			create_view_matrix(t_vec3 position, float rx, float ry,
						float rz);
t_matrix			create_projection_matrix(float aspect, float fov,
						float far, float near);
t_mesh				new_mesh(int vertexcount, t_vec4 *vertices);
t_matrix			viewport_matrix(float x, float y, float width,
						float height);
t_vec4				set_vector_4d(float x, float y, float z, float w);
t_vec3				set_vector_3d(float x, float y, float z);
t_vec2				set_vector_2d(float x, float y);
float				map(float x, t_vec2 from, t_vec2 to);
#endif
