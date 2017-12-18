/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:14:54 by lilam             #+#    #+#             */
/*   Updated: 2017/12/08 17:46:41 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>


int	line_shape(int *tet, int n)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (tet[i] && i < 4)
	{
		if (((tet[0] + i == tet[i]) || (tet[0] + (i * 4) == tet[i])))
			count++;
		i++;
	}
	return (count == n);	
}

int square_shape(int *tet)
{
	if (!(tet[0] + 1 == tet[1]))
		return (0);
	if (!(tet[0] + 4 == tet[2]))
		return (0);
	if (!(tet[0] + 5 == tet[3]))
		return (0);
	return (1);
}

//int t_shape(int *tst)
//{
//	if (line_shape(tet,3))
//	{
//		return (1);
//	}
//}

int shape_check(int *tet)
{
	int i;

	i = 0;
	if (line_shape(tet, 4))
	{
		printf("line\n");
		return (1);
	}
	if (square_shape(tet))
	{
		printf("square\n");
		return (2);
	}
	else
   		printf("wrongshape\n");
	return (0);
}

void	read_file(char *file_name)
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
	int all_pieces[26];

	while(buf[i])
	{
		if (!(buf[i] == '.' || buf[i] == '#' || buf[i] == '\n'))
			write(1, "Error_char\n", 11);
		while (buf[i] == '.' || buf[i] == '#')
		{
			if (buf[i] == '#')
			{
				//printf("%d\n", i);
				//printf("%d\n", tet_pieces);
				//printf("%d\n", count_y);;
				hash_coor[count_hash] = i - tet_pieces - count_y -  (20 * tet_pieces) + 1;
				count_hash++;
			}
			count_x++;
			i++;
		}
		if (count_x == 4)
		{
//			write(1, &buf[i - 4], 1);
//			write(1, &buf[i - 3], 1);
//			write(1, &buf[i - 2], 1);
//			write(1, &buf[i - 1], 1);
//			write(1, "\n", 1);
			count_x = 0;
			count_y++;
		}
		else if (count_x != 0)
		{
			count_x = 0;
			count_y++;
			write(1, "Error_x\n", 8);
		}	
		if (buf[i] == '\n' && (buf[i + 1] == '\n' || buf[i + 1] == '\0'))
		{
			write(1, &buf[i], 1);
			if (!(count_y == 4))
				write(1, "Error_y\n", 8);
			count_y = 0;
			if (count_hash == 4)
			{
				count_hash = 0;
				printf("%d,", hash_coor[0]);
				printf("%d,", hash_coor[1]);
				printf("%d,",  hash_coor[2]);
				printf("%d\n",  hash_coor[3]);
				all_pieces[tet_pieces] = shape_check(hash_coor);
			}
			else if (count_hash != 0)
			{
				count_hash = 0;
				write(1, "Error_h\n", 8);
			}
			tet_pieces++;
		}
		i++;
	}
	close(fd);
}


int main(int argc, char **argv)
{
	if (argc == 2)
		read_file(argv[1]);
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
