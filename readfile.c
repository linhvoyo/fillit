/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:14:54 by lilam             #+#    #+#             */
/*   Updated: 2017/12/14 17:29:33 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int num_links(int *tet)
{
	int i;
	int count;

	count = 0;
	i = 0;

	while (tet[i] && i < 3)
	{
		if ((tet[i] == tet[i + 1] - 4 || tet[i] == tet[i + 1] - 1))
			count++;
		i++;
	}
	return (count);
}

int shape_check(int *tet)
{
	if (num_links(tet) < 2)
		return (0);
	if (line_shape(tet))
		return (1);
	if (square_shape(tet))
		return (2);
	if (z_shape(tet))
	{
		if (z_shape(tet) == 1)
			return (3);
		else
			return (4);
	}
	if (l_shape(tet))
	{
		if (l_shape(tet) == 1)
			return (5);
		else
			return (6);
	}
	if (t_shape(tet))
		return (7);
	return (0);
}


int analyze_shape(int **all_pieces, int *tet)
{
	if (!(iters.count_y == 4))
		return (0);
	iters.count_y = 0;
	if (iters.count_hash == 4)
	{
		iters.count_hash = 0;
		if (shape_check(tet) != 0)
			{
				all_pieces[iters.tet_count][0] = tet[0] - 1;
				all_pieces[iters.tet_count][1] = tet[1] - 1;
				all_pieces[iters.tet_count][2] = tet[2] - 1;
				all_pieces[iters.tet_count][3] = tet[3] - 1;
				iters.shapes_arr[iters.tet_count] = shape_check(tet);
			}
		else
			return (0);
	}
	else if (iters.count_hash != 4)
		return (0);
	iters.tet_count++;
	return (1);
}

void analyze_x(int *tet, int i)
{
	tet[iters.count_hash] = i - iters.tet_count - iters.count_y -  (20 * iters.tet_count) + 1;
	iters.count_hash++;
}

int	**read_file(char *file_name, int **all_pieces)
{
	FILE_VARS;
	if(!(ret = read(open(file_name, O_RDONLY), buf, 4096)))
		return ((int**)0);
	while(buf[++i])
	{
		if (!(buf[i] == '.' || buf[i] == '#' || buf[i] == '\n'))
			return ((int**)0);
		while (buf[i] == '.' || buf[i] == '#')
		{
			if (buf[i] == '#')
				analyze_x(tet, i);
			ADD_X_ADD_I;
		}
		if (iters.count_x == 4)
		{
			RESET_X_ADD_Y;
		}
		else if ((iters.count_x != 0))
			return ((int**)0);
		if (buf[i] == '\n' && (buf[i + 1] == '\n' || buf[i + 1] == '\0'))
			if(!(ret = analyze_shape(all_pieces, tet)))
				return ((int**)0);
	}
	close(open(file_name, O_RDONLY));
	return (all_pieces);
 }
