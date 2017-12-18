/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:17:11 by lilam             #+#    #+#             */
/*   Updated: 2017/12/17 16:42:46 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# define FILE_VARS int ret; char buf[4096]; int tet[4]; int i = -1;
# define RESET_X_ADD_Y g_iters.count_x = 0; g_iters.count_y++;
# define ADD_X_ADD_I g_iters.count_x++; i++;

typedef	struct	s_counters
{
	int count_x;
	int count_y;
	int count_hash;
	int tet_count;
	int shapes_arr[26];
	int board_length;
}				t_counters;

extern			t_counters g_iters;
extern			char *g_board;

void			ft_putchar(char c);
void			ft_putstr(char *str);
int				**read_file(char *file_name, int **all_pieces);

int				line_shape(int *tet);
int				square_shape(int *tet);
int				z_shape(int *tet);
int				l_shape(int *tet);
int				t_shape(int *tet);

int				shape_check(int *tet);
int				is_offset(int *tet, int shape);
int				shift(int *arr, int temp);
int				analyze_shape(int **all_pieces, int *tet);
void			analyze_x(int *tet, int i);

char			*boardgen(char *board, char c);
int				check(int *tet, int pos, char *board, int tetnum);
void			removetet(int *tet, char *board, int pos);
int				backtrack(int **pieces, char *board, int tetnum);
void			fillit(int **arr);
#endif
