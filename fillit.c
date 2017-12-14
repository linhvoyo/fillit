/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:12:14 by lilam             #+#    #+#             */
/*   Updated: 2017/12/13 23:41:00 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char    *ft_strnew(size_t size, char c)
{
	char    *str;
	size_t    i;

	str = (char*)malloc(size + 1);
	i = 0;
	if (str)
		while (i < size)
			str[i++] = c;
	str[i] = '\0';
	return (str);
}

char	*generate_board(int size, char c)
{

	char *str;
	str = ft_strnew((size * size), c);
	return (str);
}


// int		piece_fit_shitty1(char *str, int *tet, int board_size)
// {
// 	int i;
//
// 	i = 0;
// 	while (str[i])
// 	{
// 	//	if (str[i] == '.')
// 			if (str[i + 1] == '.')
// 				if (str[i + (tet[1] - tet[0]) + (board_size - 4) + 1] == '.')
// 					if (str[i + (tet[2] - tet[1]) + (tet[1] - tet[0]) + (board_size - 4) + 1] == '.')
// 						if (str[i + (tet[3] - tet[2]) + (tet[2] - tet[1])
// 								+ (tet[1] - tet[0]) + (board_size - 4) + 1] == '.')
// 							return (i + 1);
// 		i++;
// 	}
// 	return (0);
// }


int		piece_fit_shitty1(char *str, int *tet, int board_size)
{
	int i;

	i = 1;
	while (str[i])
	{
		if (str[i] == '.')
				if (str[i + (tet[1] - tet[0]) + (board_size - 4)] == '.')
					if (str[i + (tet[2] - tet[1]) + (tet[1] - tet[0]) + (board_size - 4)] == '.')
						if (str[i + (tet[3] - tet[2]) + (tet[2] - tet[1])
								+ (tet[1] - tet[0]) + (board_size - 4)] == '.')
							return (i);
		i++;
	}
	return (0);
}



int	fill_piece_shitty1(char *str, int *tet, char c, int board_size)
{
	int i;

	if ((i = piece_fit_shitty1(str, tet, board_size)))
	{
		str[i] = c;
		str[i + (tet[1] - tet[0]) + (board_size - 4)] = c;
		str[i + (tet[2] - tet[1]) + (tet[1] - tet[0]) + (board_size - 4)] = c;
		str[i + (tet[3] - tet[2]) + (tet[2] - tet[1]) + (tet[1] - tet[0]) + (board_size - 4)] = c;
		return (1);
	}
	return (0);
}


int		piece_fit(char *str, int *tet, int board_size)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			if (str[i + (tet[1] - tet[0]) + (board_size - 4)] == '.')
				if (str[i + (tet[2] - tet[1]) + (tet[1] - tet[0]) + (board_size - 4)] == '.')
					if (str[i + (tet[3] - tet[2]) + (tet[2] - tet[1])
							+ (tet[1] - tet[0]) + (board_size - 4)] == '.')
						return (i + 1);
		i++;
	}
	return (0);
}


int	fill_piece(char *str, int *tet, char c, int board_size)
{
	int i;

	if ((i = piece_fit(str, tet, board_size)))
	{
		str[i - 1] = c;
		str[i - 1 + (tet[1] - tet[0]) + (board_size - 4)] = c;
		str[i - 1 + (tet[2] - tet[1]) + (tet[1] - tet[0]) + (board_size - 4)] = c;
		str[i - 1 + (tet[3] - tet[2]) + (tet[2] - tet[1]) + (tet[1] - tet[0]) + (board_size - 4)] = c;
		return (1);
	}
	return (0);
}

void	print_board(char *str, int board_size)
{
	printf("\n\n\n");
	int i = 0;
	while (i < (board_size * board_size))
		printf("%c", str[i++]);
	printf("\n");
}

void pb(char *str, int board_size)
{
//	 printf("\n");
	 int i = 0;
	 while (i < (board_size * board_size))
	 {
		if (i % board_size == 0)
			printf("\n");
	 	printf("%c", str[i]);
		i++;
	 }
	printf("\n\n");
}

void print_combo(int *num, int n)
{
	int i;

	i = 0;

	while (i < n)
		printf("%d ", num[i++]);
	printf("\n");
}


int    num_dots(char *s1)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s1[i])
		i++;
	i = i - 1;
	while (i > 0)
	{
		if (s1[i] == '.')
		   count++;
		else
			break;
		i--;
	}
	return (count);
}

int    ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (((unsigned char*)s1)[i])
	{
		if (((unsigned char*)s1)[i] != ((unsigned char*)s2)[i])
			return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
		i++;
	}
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}



int	generate_combo(int **arr, int num_pieces, int board_size)
{
	int num[26];
	int temp;
	int i;
	int j;
	int k;

	k = 0;

	char *str;
	char *res;

	res = generate_board(board_size, 96);

	//print_board(str, board_size);

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
			str = generate_board(board_size, '.');
			if (fill_board(str, arr, num_pieces, num, board_size))
			{
				//print_board(str, board_size);
				//printf("%dnum dots\n", num_dots(str));
				//if (num_dots(str) > num_dots(res) && ft_strcmp(str, res) < 0)
				//	res = str;
				if (ft_strcmp(str, res) < 0)
					res = str;
				pb(str, board_size);
				k = 1;
			}
			i++;
		}
		j++;
	}
//	print_board(res, board_size);
//	pb(res, board_size);
	if (k == 1)
	{
		pb(res, board_size);
		return (1);
	}
	return (0);
}

int fill_board(char *str, int **arr, int num_pieces, int *num, int board_size)
{
	int i;
	int count;

	print_combo(num, num_pieces);

    i = 0;
	count = 0;
	while (i < num_pieces)
	{
		if (fill_piece(str, arr[num[i]], 'A' + num[i], board_size))
			count++;
		i++;
	}

//	print_board(str, 4);
	if (count == num_pieces)
		return (1);
	else
		return (0);
}

void fillit(int **arr, int num_pieces)
{
	char *str;
	int i = 0;
	while (i < num_pieces)
	{
		printf("%d %d %d %d \n", arr[i][0], arr[i][1], arr[i][2], arr[i][3]);
		i++;
	}

	str = generate_board(4, '.');
	print_board(str, 4);
	//if ((index = piece_fit(str, arr[0])))
	fill_piece_shitty1(str, arr[1], 'A' + 1, 4);
	//if ((index = piece_fit(str, arr[1])))
	fill_piece_shitty1(str, arr[2], 'A' + 2, 4);
	//if ((index = piece_fit(str, arr[2])))
//	fill_piece(str, arr[0], 'A' + 0);
//	fill_piece(str, arr[1], 'A' + 1);

	print_board(str, 4);
	pb(str, 4);


//	int board_size = 4;

//	str = generate_board(num_pieces);
//	print_board(str, board_size);
//	puts(" ");

//	int num[4];
//	num[0] = 3;
//	num[1] = 0;
//	num[2] = 2;
//	num[3] = 1;

//	fill_board(str, arr, num_pieces, num);
//	print_board(str);

//	generate_combo(arr, num_pieces, 5);
//	i = 4;
//	while (i < 26)
//	{
//		if(!(generate_combo(arr, num_pieces, i)))
//				i++;
//		else
//			break ;
//	}
}
