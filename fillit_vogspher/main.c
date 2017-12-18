/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 22:03:40 by lilam             #+#    #+#             */
/*   Updated: 2017/12/17 16:22:00 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_counters	g_iters = {0, 0, 0, 0, {0}, 0};
char		*g_board;

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int			**read_file(char *file_name, int **all_pieces)
{
	FILE_VARS;
	if (!(ret = read(open(file_name, O_RDONLY), buf, 4096)))
		return ((int**)0);
	while (buf[++i])
	{
		if (!(buf[i] == '.' || buf[i] == '#' || buf[i] == '\n'))
			return ((int**)0);
		while (buf[i] == '.' || buf[i] == '#')
		{
			if (buf[i] == '#')
				analyze_x(tet, i);
			ADD_X_ADD_I;
		}
		if (g_iters.count_x == 4)
		{
			RESET_X_ADD_Y;
		}
		else if ((g_iters.count_x != 0))
			return ((int**)0);
		if (buf[i] == '\n' && (buf[i + 1] == '\n' || buf[i + 1] == '\0'))
			if (!(ret = analyze_shape(all_pieces, tet)))
				return ((int**)0);
	}
	close(open(file_name, O_RDONLY));
	return (all_pieces);
}

int			main(int argc, char **argv)
{
	int **arr;
	int j;

	arr = malloc(sizeof(**arr) * 26);
	j = 0;
	while (j < 26)
		arr[j++] = malloc(sizeof(int) * 4);
	if (argc == 2)
	{
		if (!(open(argv[1], O_RDONLY)))
			return (0);
		arr = read_file(argv[1], arr);
		if (arr == 0)
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
