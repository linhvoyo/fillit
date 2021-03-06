/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:12:14 by lilam             #+#    #+#             */
/*   Updated: 2017/12/17 22:10:37 by linh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


char	*boardgen(int size, char *board, char c)
{
	int		iter;
	int		line;
	char	*newboard;

	if (board)
		free(board);
	newboard = malloc(sizeof(newboard) * (size * size) + (size));
	iter = 0;
	line = 0;
	while (iter < (size * size) + size)
	{
		if (iter == size || iter == (line * size) + size + line)
		{
			line++;
			newboard[iter++] = '\n';
		}
		else
			newboard[iter++] = c;
	}
	iters.board_length = iter;
	newboard[iter] = '\0';
	return (newboard);
}

int		check(int *tet, int startpos, char *board, int tetnum, int size)
{
	int i;
	int	*temp;

	temp = malloc(sizeof(temp) * 4);
	for (int k = 0; k < 4; k++)
		temp[k] = tet[k];
	i = -1;
	//while (++i < (int)strlen(board))
	while (++i < (int)(iters.board_length))
	{
		if (board[i] == tetnum + 'A')
		{
			free(temp);
			return (0);
		}
	}
	i = -1;
	while (++i < 4)
	{
		if (temp[i] >= 4)
			temp[i] = temp[i] + (temp[i] / 4) * (size - 3);
	}
	i = 0;
	if (board[temp[0] + startpos] == '.' && board[temp[1] + startpos] == '.')
	{
		if (board[temp[2] + startpos] == '.' && board[temp[3] + startpos] == '.')
		{
			while (i < 4)
				board[temp[i++] + startpos] = tetnum + 'A';
			free(temp);
			return (1);
		}
		else
		{
			free(temp);
			return (0);
		}
	}
	free(temp);
	return (0);
}

void print_combo(int *num, int n)
{
	int i;

	i = 0;

	while (i < n)
		printf("%d ", num[i++]);
	printf("\n");
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






//int	generate_combo(int **arr, int num_pieces, int board_size)
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

	res = boardgen(board_size, NULL, 96);

	//print_board(str, board_size);

	i = -1;
	while (++i < num_pieces)
		num[i] = i;

	j = 1;
	while (j <= num_pieces)
	{
		i = 0;
		while (i < num_pieces - 1)
		{
			temp = num[i];
			num[i] = num[i + 1];
			num[i + 1] = temp;
			str = boardgen(board_size, NULL, '.');
			if (fill_board(str, arr, num_pieces, num, board_size))
			{
				//print_board(str, board_size);
				//printf("%dnum dots\n", num_dots(str));
				//if (num_dots(str) > num_dots(res) && ft_strcmp(str, res) < 0)
				//	res = str;
				if (ft_strcmp(str, res) < 0)
					res = str;
			//	pb(str, board_size);
//			  printf("%s\n", str);
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
//		printf("%s", res);
		//pb(res, board_size);
		return (1);
	}
	return (0);
}



int fill_board(char *str, int **arr, int num_pieces, int *num, int board_size)
{
	int i;
	int j;
	int count;

	print_combo(num, num_pieces);

	i = 0;
	count = 0;
//	printf("%d ", iters.shapes_arr[0]);
	while (i < num_pieces)
	{
			j = 0;
			while (j < str[i])
			{
				if (check(arr[num[i]], j, str, num[i], board_size))
					count++;
				j++;
			}
			i++;
	}
	printf("%s\n", str);
	if (count == num_pieces)
		return (1);
	else
		return (0);
}


void	removetet(int *tet, char *board, int pos, int size)
{
	int	i;

	int *temp;
	temp = malloc(sizeof(temp) * 4);
	for (int j = 0; j < 4; j++)
		temp[j] = tet[j];
	i = -1;
	while (++i < 4)
	{
		if (temp[i] >= 4)
			temp[i] = temp[i] + (temp[i] / 4) * (size - 3);
	}
	i = -1;
	while (++i < 4)
		board[pos + temp[i]] = '.';

}




int		backtrack(int **pieces, char *board, int tetnum, int size)
{
	//printf("%s", board);
	int pos;

	if (tetnum == iters.tet_count)
	{
		g_board = board;
		return (0);
	}
	pos = 0;
	while (board[pos] != '\0')
	{
		if (check(pieces[tetnum], pos, board, tetnum, size) != 0)
		{
			if (!backtrack(pieces, board, tetnum + 1, size))
				return (0);
			removetet(pieces[tetnum], board, pos, size);
		}
		pos++;
	}
	return (1);
}


void fillit(int **arr)
{
	int		size;
	char	*board;

	size = 2;
	board = malloc(sizeof(board) * 2);
	while (g_board == NULL)
	{
		board = boardgen(size, board, '.');
		backtrack(arr, board, 0, size);
		size++;
	}
//	printf("%s", g_board);
}


//	check(arr[0], 0, board, 0, board_size);
//	 printf("%s\n",  board);
//	int j = 0;
//	int count = 0;
//	while (j < iters.board_length)
//	{
//		if (check(arr[count], j, board, count, board_size))
//			count++;
//		j++;
//	}

	//check(arr[0], 0, board, iters.tet_count, board_size);
//	printf("%s\n",  board);


//	generate_combo(arr, num_pieces, board_size);
	//}
/*
	str = generate_board(board_size, '.');
	print_board(str, board_size);
	pb(str,board_size);
	fill_piece_shitty1(str, arr[0], 'A' + 0, board_size);
	fill_piece_shitty1(str, arr[1], 'A' + 1, board_size);
	fill_piece(str, arr[2], 'A' + 2, board_size);
//	fill_piece(str, arr[1], 'A' + 1);

	print_board(str, board_size);
	pb(str, board_size);
*/

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


//	generate_combo(pieces, num_pieces, 5);
	//  i = 4;
	//  while (i < 26)
	//  {
	//  	if(!(generate_combo(arr, iters.tet_count, i)))
	//  			i++;
	//  	else
	//  		break ;
	//  }
