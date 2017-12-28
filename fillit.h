/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:17:11 by lilam             #+#    #+#             */
/*   Updated: 2017/12/27 17:37:17 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# define FILE_VARS char buf[4096]; int tet[4]; int i = -1;
# define READ_FILE int ret = read(fd, buf, 4096); buf[ret] = '\0'
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

void			ft_putstr(char *str);
int				read_file(int **all_pieces, int fd);
int				is_edge(int *tet);

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
