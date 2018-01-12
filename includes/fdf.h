/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 16:58:00 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/11 18:03:50 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define _USE_MATH_DEFINES
# define FOV 60
# define WIDTH 1200
# define HEIGHT 800
# define FAR_PLANE 10.0f
# define NEAR_PLANE 10000
# define degreesToRadians(angleDegrees) (angleDegrees * M_PI / 180.0)

# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define Q 113
# define D 100
# define Y 121
# define U 117
# define Z 122
# define X 120
# define I 105
# define O 111
# define SCROLL_UP 5
# define SCROLL_DOWN 4

// # define ESC 53
// # define UP 126
// # define DOWN 125
// # define LEFT 123
// # define RIGHT 124
// # define A 0
// # define D 2
// # define Y 16
// # define U 32
// # define W 13
// # define X 7
// # define I 34
// # define O 31
// #define M_PI 3.14159265358979323846

# include "../libft/libft.h"
# include "../math_toolbox/includes/toolbox.h"
# include "get_next_line.h"
# include <mlx.h>
# include <math.h>

typedef struct		s_camera
{
	t_vec3			position;
	t_vec3			target;
	float			rx;
	float			ry;
	float			rz;
}					t_camera;
typedef struct		s_img
{
	void			*ptr;
	int				*data;
	int				bpp;
	int				sl;
	int				endian;
}					t_img;
typedef struct		s_mlx
{
	void			*win;
	void			*ptr;
	t_mesh			*mesh;
	struct s_camera	*camera;
	struct s_img	*img;
}					t_mlx;
typedef struct		s_loader
{
	float			*data;
	int				size;
	struct s_loader	*next;
}					t_loader;
typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;
void				*error(char *message);
t_mesh				*load_map(int ac, char **av);
t_mesh				*process_height(t_mesh *mesh);
t_mesh				*transform_mesh(t_camera *cam, t_mesh *mesh);
t_mesh				*clip_mesh(t_mesh *m);
t_mlx				*mesh_to_view(t_mlx *mlx);
t_img				*init_img(t_mlx *mlx);
void				clear_color(t_img *img, int color);
t_img				*fill_img_pixel(t_img *img, int color, int x, int y);
t_mlx				*init_all(int ac, char **av);
int					expose_hook(t_mlx *mlx);
int					key_hook(int keycode, t_mlx *mlx);
int					mouse_hook(int button, int x, int y, t_mlx *mlx);
t_img				*line(t_img *img, t_vec2 a, t_vec2 b, int color);
#endif
