/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile_9.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:14:54 by lilam             #+#    #+#             */
/*   Updated: 2017/12/16 17:21:51 by lilam            ###   ########.fr       */
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
	int i;

	i = 0;
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

int	**read_file(char *file_name, int **all_pieces)
{
	int		ret;
	char	buf[BUF_SIZE];
	int		tet[4];

	if(!(ret = read(open(file_name, O_RDONLY), buf, BUF_SIZE)))
		return ((int**)0);

	int i = 0;
	int count_x = 0;
	int count_y = 0;
	int count_hash = 0;
	int tet_count = 0;

	while(buf[i])
	{
		if (!(buf[i] == '.' || buf[i] == '#' || buf[i] == '\n'))
			return ((int**)0);
		while (buf[i] == '.' || buf[i] == '#')
		{
			if (buf[i] == '#')
			{
				tet[count_hash] = i - tet_count - count_y -  (20 * tet_count) + 1;
				count_hash++;
			}
			count_x++;
			i++;
		}
		if (count_x == 4)
		{
			count_x = 0;
			count_y++;
		}
		else if (count_x != 0)
			return ((int**)0);
		if (buf[i] == '\n' && (buf[i + 1] == '\n' || buf[i + 1] == '\0'))
		{
			if (!(count_y == 4))
				return ((int**)0);
			count_y = 0;
			if (count_hash == 4)
			{
				count_hash = 0;
				if (shape_check(tet) != 0)
					{
						all_pieces[tet_count][0] = tet[0];
						all_pieces[tet_count][1] = tet[1];
						all_pieces[tet_count][2] = tet[2];
						all_pieces[tet_count][3] = tet[3];
					}
				else
					return ((int**)0);
			}
			else if (count_hash != 4)
				return ((int**)0);
			tet_count++;
		}
		i++;
	}
	close(open(file_name, O_RDONLY));

	return (all_pieces);
 }


int num_tet(char *file_name)
{
	int		ret;
	char	buf[BUF_SIZE];
	int i;
	int tet_count;

	ret = read(open(file_name, O_RDONLY), buf, BUF_SIZE);
	i = 0;
	tet_count = 0;
	while(buf[i])
	{
		if (buf[i] == '\n' && (buf[i + 1] == '\n' || buf[i + 1] == '\0'))
			tet_count++;
		i++;
	}
	close(open(file_name, O_RDONLY));
	return (tet_count);
}
