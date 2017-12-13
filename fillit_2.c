/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:12:14 by lilam             #+#    #+#             */
/*   Updated: 2017/12/12 21:17:28 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char    *ft_strnew(size_t size)
{
	char    *str;
	size_t    i;

	str = (char*)malloc(size + 1);
	i = 0;
	if (str)
		while (i < size)
			str[i++] = '.';
	str[i] = '\0';
	return (str);
}

char	*generate_board(int num_tet)
{

	char *str;
	str = ft_strnew((num_tet * 4));
	return (str);
}

int		piece_fit(char *str, int *tet)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			if (str[i + (tet[1] - tet[0])] == '.')
				if (str[i + (tet[2] - tet[1]) + (tet[1] - tet[0])] == '.')
					if (str[i + (tet[3] - tet[2]) + (tet[2] - tet[1])
							+ (tet[1] - tet[0])] == '.')
						return (i + 1);
		i++;
	}
	return (0);
}


int	fill_piece(char *str, int *tet, char c)
{
	int i;

	if ((i = piece_fit(str, tet)))
	{
		str[i - 1] = c;
		str[i - 1 + (tet[1] - tet[0])] = c;
		str[i - 1 + (tet[2] - tet[1]) + (tet[1] - tet[0])] = c;
		str[i - 1 + (tet[3] - tet[2]) + (tet[2] - tet[1]) + (tet[1] - tet[0])] = c;
		return (1);
	}
	return (0);
}

void	print_board(char *str)
{
	printf("\n\n\n");
	int i = 0;
	while (i < 16)
		printf("%c", str[i++]);
	printf("\n");
}


void print_combo(int *num, int n)
{
	int i;

	i = 0;

	while (i < n)
		printf("%d ", num[i++]);
	printf("\n");
}

int	generate_combo(int **arr, int num_pieces)
{
	int num[26];
	int temp;
	int i;
	int j;
	char *str; 

	str = generate_board(num_pieces);
	i = -1;
	while (++i < num_pieces)
		num[i] = i;

	j = 0;
	while (j < num_pieces)
	{
		i = 0;
		while (i < num_pieces - 1)
		{
			temp = num[i];
			num[i] = num[i + 1];
			num[i + 1] = temp;
			if (fill_board(str, arr, num_pieces, num))
				print_board(str);
			i++;
		}
		j++;
	}
	return (0);
}

int fill_board(char *str, int **arr, int num_pieces, int *num)
{
	int i;
	int count;

	print_combo(num, num_pieces);

    i = 0;
	count = 0;
//	printf("%d\n", num_pieces);
	while (i < num_pieces)
	{
		if (fill_piece(str, arr[num[i]], 'A' + num[i]))
			count++;
		i++;
	}

//	print_board(str);
	if (count == num_pieces)
		return (1);
	else
	{
		i = 0;
		while (str[i])
			str[i++] = '.';
	}
	return (0);
}

void fillit(int **arr, int num_pieces)
{
	char *str;
	int i = 0;
	while (i < 4)
	{
		printf("%d %d %d %d \n", arr[i][0], arr[i][1], arr[i][2], arr[i][3]);
		i++;
	}

	puts(" ");
//	str = generate_board(num_pieces);

//	print_board(str);
	//if ((index = piece_fit(str, arr[0])))
//	fill_piece(str, arr[3], 'A' + 3);
	//if ((index = piece_fit(str, arr[1])))
//	fill_piece(str, arr[0], 'A' + 0);
	//if ((index = piece_fit(str, arr[2])))
//	fill_piece(str, arr[2], 'A' + 2);
//	fill_piece(str, arr[1], 'A' + 1);

//	print_board(str);

	str = generate_board(num_pieces);
	print_board(str);

//	int num[4];
//	num[0] = 3;
//	num[1] = 0;
//	num[2] = 2;
//	num[3] = 1;

//	fill_board(str, arr, num_pieces, num);
//	print_board(str);

	generate_combo(arr, num_pieces);
}

