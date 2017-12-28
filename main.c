/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 22:03:40 by lilam             #+#    #+#             */
/*   Updated: 2017/12/27 17:34:20 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_counters	g_iters = {0, 0, 0, 0, {0}, 0};
char		*g_board;

void		ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int			is_edge(int *tet)
{
	if (tet[1] - tet[0] == 1 && tet[0] % 4 == 0)
		return (1);
	if (tet[2] - tet[1] == 1 && tet[1] % 4 == 0)
		return (1);
	if (tet[3] - tet[2] == 1 && tet[2] % 4 == 0)
		return (1);
	return (0);
}

int			read_file(int **all_pieces, int fd)
{
	FILE_VARS;
	READ_FILE;
	if (!ret)
		return (0);
	while (++i < ret)
	{
		if (!(buf[i] == '.' || buf[i] == '#' || buf[i] == '\n'))
			return (0);
		while (i < ret && (buf[i] == '.' || buf[i] == '#'))
		{
			if (buf[i] == '#')
				analyze_x(tet, i);
			ADD_X_ADD_I;
		}
		if (g_iters.count_x == 4 && !(g_iters.count_x = 0) &&
				(g_iters.count_y++))
			;
		else if ((g_iters.count_x != 0))
			return (0);
		if (buf[i] == '\n' && (buf[i + 1] == '\n' || buf[i + 1] == '\0'))
			if (!(analyze_shape(all_pieces, tet)))
				return (0);
	}
	close(fd);
	return (1);
}

int			main(int argc, char **argv)
{
	int **arr;
	int j;
	int fd;

	arr = malloc(sizeof(**arr) * 26);
	j = 0;
	while (j < 26)
		arr[j++] = malloc(sizeof(int) * 4);
	if (argc == 2)
	{
		if (!(fd = open(argv[1], O_RDONLY)))
			return (0);
		if (!(read_file(arr, fd)))
		{
			write(1, "error\n", 6);
			return (0);
		}
		fillit(arr);
		ft_putstr(g_board);
	}
	else
		write(1, "usage: ./fillit file\n", 21);
	return (0);
}
