/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:12:14 by lilam             #+#    #+#             */
/*   Updated: 2017/12/17 16:15:12 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		g_size;

char	*boardgen(char *board, char c)
{
	int		iter;
	int		line;
	char	*newboard;

	if (board)
		free(board);
	newboard = malloc(sizeof(newboard) * (g_size * g_size) + (g_size));
	iter = 0;
	line = 0;
	while (iter < (g_size * g_size) + g_size)
	{
		if (iter == g_size || iter == (line * g_size) + g_size + line)
		{
			line++;
			newboard[iter++] = '\n';
		}
		else
			newboard[iter++] = c;
	}
	g_iters.board_length = iter;
	newboard[iter] = '\0';
	return (newboard);
}

int		check(int *tet, int pos, char *board, int tetnum)
{
	int i;
	int	*tmp;

	if (!(tmp = malloc(sizeof(tmp) * 4)))
		return (0);
	i = -1;
	while (++i < 4)
	{
		tmp[i] = tet[i];
		if (tmp[i] >= 4)
			tmp[i] = tmp[i] + (tmp[i] / 4) * (g_size - 3);
	}
	i = 0;
	if (board[tmp[0] + pos] == '.' && board[tmp[1] + pos] == '.')
	{
		if (board[tmp[2] + pos] == '.' && board[tmp[3] + pos] == '.')
		{
			while (i < 4)
				board[tmp[i++] + pos] = tetnum + 'A';
			free(tmp);
			return (1);
		}
	}
	free(tmp);
	return (0);
}

void	removetet(int *tet, char *board, int pos)
{
	int	i;
	int *tmp;

	i = -1;
	if (!(tmp = malloc(sizeof(tmp) * 4)))
		return ;
	while (++i < 4)
		tmp[i] = tet[i];
	i = -1;
	while (++i < 4)
	{
		if (tmp[i] >= 4)
			tmp[i] = tmp[i] + (tmp[i] / 4) * (g_size - 3);
	}
	i = -1;
	while (++i < 4)
		board[pos + tmp[i]] = '.';
}

int		backtrack(int **pieces, char *board, int tetnum)
{
	int pos;

	if (tetnum == g_iters.tet_count)
	{
		g_board = board;
		return (0);
	}
	pos = 0;
	while (board[pos] != '\0')
	{
		if (check(pieces[tetnum], pos, board, tetnum) != 0)
		{
			if (!backtrack(pieces, board, tetnum + 1))
				return (0);
			removetet(pieces[tetnum], board, pos);
		}
		pos++;
	}
	return (1);
}

void	fillit(int **arr)
{
	char	*board;
	int		i;

	i = 1;
	while (i * i < 4 * g_iters.tet_count)
		i++;
	g_size = i - 1;
	if (!(board = malloc(sizeof(board) * 2)))
		return ;
	while (g_board == NULL)
	{
		board = boardgen(board, '.');
		backtrack(arr, board, 0);
		g_size++;
	}
}
