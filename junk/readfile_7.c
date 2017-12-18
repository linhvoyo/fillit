/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:14:54 by lilam             #+#    #+#             */
/*   Updated: 2017/12/11 10:59:10 by lilam            ###   ########.fr       */
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
	int		fd;
	int		ret;
	char	buf[BUF_SIZE];
	int		tet[4];

	fd = open(file_name, O_RDONLY);
	ret = read(fd, buf, BUF_SIZE);

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
			else if (count_hash != 0)
				return ((int**)0);
			tet_count++;
		}
		i++;
	}
	close(fd);

	return (all_pieces);
 }


int main(int argc, char **argv)
{
	int **arr;
	arr = malloc(sizeof(**arr) * 26);
	int j;

	j = 0;
	while (j < 26)
		arr[j++] = malloc(sizeof(int) * 4);
	if (argc == 2)
	{
		arr = read_file(argv[1], arr);
		if (arr == 0)
			write(1, "Error\n", 6);
		int i = 0;
		while (i < 4)
		{
			printf("%d %d %d %d \n", arr[i][0], arr[i][1], arr[i][2], arr[i][3]);
			i++;
		}
	//	arr = read_file(argv[1], arr);
	//	printf("%i\n", arr[0]);
	//	printf("%i\n", arr[1]);
	//	printf("%i\n", arr[2]);
	//	printf("%i\n", arr[3]);
//		printf("%d\n", read_file(argv[1])[1]);
	//	read_file(argv[1]);
		//int j = 0;
	//	while (i[j])
	//		printf("%d,", i[j++]);
	}
	else
	{
		int i;
		i = 0;
		char usage[] = "usage: ./fillit file.fillit\n";
		while (usage[i])
			i++;
		write(1, &usage, i);
	}
	return (0);
}
