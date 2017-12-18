/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:14:54 by lilam             #+#    #+#             */
/*   Updated: 2017/12/17 16:28:37 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		shape_check(int *tet)
{
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

int		is_offset(int *tet, int shape)
{
	if (shape == 7 && tet[0] == tet[1] - 3 && tet[1] == tet[2] - 1
			&& (tet[2] == tet[3] - 4 || tet[2] == tet[3] - 1))
		return (1);
	if (tet[0] == tet[1] - 1 && tet[1] == tet[2] - 2 &&
			tet[2] == tet[3] - 1 && shape == 4)
		return (1);
	if (shape == 3 && tet[0] == tet[1] - 3 && tet[1] == tet[2] - 1
			&& tet[2] == tet[3] - 3)
		return (1);
	if (shape == 6 && tet[0] == tet[1] - 4 && tet[1] == tet[2] - 3
			&& tet[2] == tet[3] - 1)
		return (1);
	if (shape == 6 && tet[0] == tet[1] - 4 && tet[1] == tet[2] - 3
			&& tet[2] == tet[3] - 1)
		return (1);
	if (shape == 5 && tet[0] == tet[1] - 2 && tet[1] == tet[2] - 1
			&& tet[2] == tet[3] - 1)
		return (2);
	return (0);
}

int		shift(int *arr, int temp)
{
	int offset;

	offset = is_offset(arr, shape_check(arr));
	if (offset == 0)
	{
		if (arr[0] == 1)
			temp = 0;
		else
			temp = arr[0] - 1;
	}
	else if (offset == 1)
	{
		if (arr[0] == 2)
			temp = 0;
		else
			temp = arr[0] - 2;
	}
	else if (offset == 2)
	{
		if (arr[0] == 3)
			temp = 0;
		else
			temp = arr[0] - 3;
	}
	return (temp);
}

int		analyze_shape(int **all_pieces, int *tet)
{
	if (!(g_iters.count_y == 4))
		return (0);
	g_iters.count_y = 0;
	if (g_iters.count_hash == 4)
	{
		g_iters.count_hash = 0;
		if (shape_check(tet) != 0)
		{
			g_iters.shapes_arr[g_iters.tet_count] = shape_check(tet);
			all_pieces[g_iters.tet_count][0] = tet[0] - shift(tet, 0) - 1;
			all_pieces[g_iters.tet_count][1] = tet[1] - shift(tet, 0) - 1;
			all_pieces[g_iters.tet_count][2] = tet[2] - shift(tet, 0) - 1;
			all_pieces[g_iters.tet_count][3] = tet[3] - shift(tet, 0) - 1;
		}
		else
			return (0);
	}
	else if (g_iters.count_hash != 4)
		return (0);
	g_iters.tet_count++;
	return (1);
}

void	analyze_x(int *tet, int i)
{
	int	ch;
	int	cy;
	int	tc;

	ch = g_iters.count_hash;
	cy = g_iters.count_y;
	tc = g_iters.tet_count;
	tet[ch] = i - tc - cy - (20 * tc) + 1;
	g_iters.count_hash++;
}
