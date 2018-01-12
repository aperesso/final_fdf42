/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 23:47:56 by aperesso          #+#    #+#             */
/*   Updated: 2018/01/10 15:01:44 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** To be parsed, the datas need to be transformed into integers
** This is done by removing the ' ' with ft_strsplit
** counting the resulting tab and tronsform the characters stored in
** that array into intgers.
*/

static t_loader	*parse_data(char *line)
{
	t_loader	*new;
	char		**split;
	int			i;

	if (!(new = (t_loader *)malloc(sizeof(t_loader))))
		return (0);
	split = ft_strsplit(line, ' ');
	new->size = 0;
	while (split[new->size])
		new->size++;
	if (!(new->data = (float *)malloc(sizeof(float) * new->size)))
		return (0);
	i = -1;
	while (++i < new->size)
		new->data[i] = ft_atoi(split[i]);
	new->next = NULL;
	return(new);
}

/*
** The datas are then parsed into a linked list called 'loader'
*/

static int	process_data(t_loader **data, char *line)
{
	t_loader	*new;
	t_loader	*current;

	if (!(new = parse_data(line)))
		return (0);
	current = *data;
	if (!current)
		*data = new;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new;
	}
	return (1);
}

/*
** To get a georgous fdf, we need to store the height of the map
** For esthetical reasons I decided that if the input_file is not a rectangle
** I will add some points at height 0 to obtain a good looking one
*/

static t_mesh	*get_size(t_loader *data, t_mesh **map)
{
	t_loader	*current;
	t_vec2		size;
	t_mesh		*mesh;

	mesh = *map;
	current = data;
	size = set_vector_2d(0, 0);
	while (current)
	{
		size.x++;
		if (current->size > size.y)
			size.y = current->size;
			current = current->next;
	}
	mesh->row = size.x;
	mesh->col = size.y;
	return (mesh);
}

/*
**	Finally, the datas are transformed into a list of 4d vectors
**  given their position in the input_file. This is where the maths start !
**
**  1 2 3	->	(0,1,0,1) (1,2,0,1) (2,3,0,1)
**  4 5 6	->	(0,4,1,1) (1,5,1,1) (2,6,1,1)
*/

static t_vec4	*process_vertex(t_loader *data, int row, int col)
{
	t_vec4		*vertex;
	t_loader	*current;
	int			j;
	int			k;
	int			i;

	if (!(vertex = (t_vec4 *)malloc(sizeof(t_vec4) * col * row)))
		return (NULL);
	current = data;
	i = 0;
	k = 0;
	while (current)
	{
		j = -1;
		while (++j < col)
		{
			vertex[i] = set_vector_4d(j, 0, k, 1);
			if (j < current->size)
				vertex[i].y = current->data[j];
			i++;
		}
		k++;
		current = current->next;
	}
	return (vertex);
}

/*
**	Where all the magic of the loading appears !
*/

t_mesh			*load_map(int ac, char **av)
{
	int			fd;
	t_mesh		*map;
	t_loader	*data = NULL;
	int			i;
	char		*line;

	if (ac != 2)
		return ((t_mesh *)error("usage: ./fdf input_file\n"));
	fd = open(av[1], O_RDONLY);
	while ((i = get_next_line(fd, &line)) != 0)
		if (i == -1 || !(process_data(&data, line)))
			return ((t_mesh *)error("can not read file\n"));
	close(fd);
	if (!(map = (t_mesh *)malloc(sizeof(t_mesh))))
		return ((t_mesh *)error("an error occured\n"));
	map = get_size(data, &map);
	if (!(map->vertex_count = map->col * map->row))
		return ((t_mesh *)error("It looks like there is nothing to show :(\n"));
	if (!(map->vertices = process_vertex(data, map->col, map->row)))
		return ((t_mesh *)error("an error occured\n"));
	return (map);
}
