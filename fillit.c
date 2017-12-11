/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:12:14 by lilam             #+#    #+#             */
/*   Updated: 2017/12/11 13:46:15 by lilam            ###   ########.fr       */
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


void	fill_piece(char *str, int *tet, char c)
{
	int i;

	if ((i = piece_fit(str, tet)))
	{
		str[i - 1] = c;
		str[i - 1 + (tet[1] - tet[0])] = c;
		str[i - 1 + (tet[2] - tet[1]) + (tet[1] - tet[0])] = c;
		str[i - 1 + (tet[3] - tet[2]) + (tet[2] - tet[1]) + (tet[1] - tet[0])] = c;
	}
}

void	print_board(char *str)
{
	printf("\n\n\n");
	int i = 0;
	while (i < 16)
		printf("%c", str[i++]);
	printf("\n");
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

	str = generate_board(num_pieces);
	
	print_board(str);

	//if ((index = piece_fit(str, arr[0])))
	fill_piece(str, arr[0], 'A');
	//if ((index = piece_fit(str, arr[1])))
	fill_piece(str, arr[1], 'A' + 1);
	//if ((index = piece_fit(str, arr[2])))
	fill_piece(str, arr[2], 'A' + 2);
	fill_piece(str, arr[3], 'A' + 3);
//	int index;
//	i = 0;
//	while ((index = piece_fit(str, arr[0])))
//	{
//		fill_piece(str, arr[i], 'A' + i, index);
//		i++;
//	}	

	print_board(str);	
}

