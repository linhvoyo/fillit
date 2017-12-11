/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:14:54 by lilam             #+#    #+#             */
/*   Updated: 2017/12/10 18:36:34 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>


int	line_shape(int *tet)
{
	int i;

	i = 0;
	while (tet[i] && i < 3)
	{
		if (!((tet[i] == tet[i + 1] - (tet[2] - tet[1]))))
			return (0);
		i++;
	}
	return (1);
}

int square_shape(int *tet)
{
	if ((tet[1] - tet[0] == 1) && (tet[3] - tet[2] == 1) && (tet[2] - tet[1] == 3))
		return (1);
	return (0);
}

int z_shape(int *tet)
{
	if ((tet[1] - tet[0] == tet[3] - tet[2]) && (tet[2] - tet[1] <= 4))
	{
		if ((tet[1] - tet[0] == 3 && tet[2] - tet[1] == 1)
				|| (tet[1] - tet[0] == 1 && tet[2] - tet[1] == 4))
			return (1);
		else 
			return (2);
	}
	return (0);
}

int l_shape(int *tet)
{
	if (tet[0] == 4 &&  tet[1] == 8 && tet[2] == 12 && tet[3] == 13)
		return (0);
	if ((tet[1] - tet[0] == 1) && (tet[2] - tet[1] == 1) && (tet[3] - tet[2] == 2))
		return (1);
	if ((tet[1] - tet[0] == 2) && (tet[2] - tet[1] == 1) && (tet[3] - tet[2] == 1))
		return (1);
	if ((tet[1] - tet[0] == 1) && (tet[2] - tet[1] == 4) && (tet[3] - tet[2] == 4))
		return (1);
	if ((tet[1] - tet[0] == 4) && (tet[2] - tet[1] == 4) && (tet[3] - tet[2] == 1))
		return (1);
	if ((tet[1] - tet[0] == 4) && (tet[2] - tet[1] == 3) && (tet[3] - tet[2] == 1))
		return (2);
	if ((tet[1] - tet[0] == 1) && (tet[2] - tet[1] == 3) && (tet[3] - tet[2] == 4))
		return (2);
	if ((tet[1] - tet[0] == 1) && (tet[2] - tet[1] == 1) && (tet[3] - tet[2] == 4))
		return (2);
	if ((tet[1] - tet[0] == 4) && (tet[2] - tet[1] == 1) && (tet[3] - tet[2] == 1))
		return (2);	
	return (0);
}

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

int t_shape(int *tet)
{
	if (num_links(tet) >= 2 && (tet[1] == tet[3] - 4))
		return (1);
	if (num_links(tet) >= 2 && (tet[0] == tet[2] - 4))
		return (1);
	if (num_links(tet) >= 2 && (tet[1] == tet[2] - 1))
		return (1);
	if (num_links(tet) >= 2 && (tet[1] == tet[2] - 1))
		return (1);

	return (0);
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



int *null()
{
	int *arr;
	arr = malloc(sizeof(int));
	arr[0] = 0;
	
	return (arr);
}

int	*read_file(char *file_name, int *all_pieces)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE];
	int		hash_coor[4];

	fd = open(file_name, O_RDONLY);
	ret = read(fd, buf, BUF_SIZE);
	//while ((ret = read(fd, buf, BUF_SIZE)))	
	//	write(1, buf, ret);

	int i = 0;
	int count_x = 0;
	int count_y = 0;
	int count_hash = 0;
	int tet_pieces = 0;

	while(buf[i])
	{
		if (!(buf[i] == '.' || buf[i] == '#' || buf[i] == '\n'))
			return (null());
		while (buf[i] == '.' || buf[i] == '#')
		{
			if (buf[i] == '#')
			{
				hash_coor[count_hash] = i - tet_pieces - count_y -  (20 * tet_pieces) + 1;
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
		{
			count_x = 0;
			count_y++;
			return (null());
		}	
		if (buf[i] == '\n' && (buf[i + 1] == '\n' || buf[i + 1] == '\0'))
		{
			write(1, &buf[i], 1);
			if (!(count_y == 4))
				return (null());
			count_y = 0;
			if (count_hash == 4)
			{
				count_hash = 0;
				all_pieces[tet_pieces] = shape_check(hash_coor);
				if (all_pieces[tet_pieces] == 0)
					return (null());

			}
			else if (count_hash != 0)
			{
				count_hash = 0;
				return (null());
			}
			tet_pieces++;
		}
		i++;
	}
//	all_pieces[i] = NULL;

//	printf("%d\n", tet_pieces);
//	int j = 0;
//	while (j < tet_pieces)
//	{
//		printf("%d,", all_pieces[j]);
//		j++;
//	}

close(fd);
//	
//	int *arr;
//	arr = malloc(sizeof(*arr) * (tet_pieces));
//	int j;
//
//	j = 0;
//	while (j < tet_pieces)
//	{
//		arr[j] = all_pieces[j];
//		j++;
//	}
//
//	return (all_pieces);
	
	return (all_pieces);
}


int main(int argc, char **argv)
{
	int *arr;
	arr = malloc(sizeof(arr) * 26);
	if (argc == 2)
	{	
		arr = read_file(argv[1], arr);
		if (arr[0] == 0)
			write(1, "Error\n", 6);
	//	arr = read_file(argv[1], arr);
		printf("%i\n", arr[0]);
		printf("%i\n", arr[1]);
		printf("%i\n", arr[2]);
		printf("%i\n", arr[3]);
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
