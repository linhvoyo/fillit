/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:17:11 by lilam             #+#    #+#             */
/*   Updated: 2017/12/14 18:33:56 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

//delete this later
#include <stdio.h>


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define FILE_VARS int ret; char buf[4096]; int tet[4]; int i = -1;
#define RESET_X_ADD_Y iters.count_x = 0; iters.count_y++;
#define ADD_X_ADD_I iters.count_x++; i++;

typedef	struct	s_counters
{
	int count_x;
	int count_y;
	int count_hash;
	int tet_count;
	int shapes_arr[26];
	int board_length;
}				t_counters;

extern t_counters iters;


//main.c

//shape_validation.c
int line_shape(int *tet);
int square_shape(int *tet);
int z_shape(int *tet);
int l_shape(int *tet);
int t_shape(int *tet);

//readfile.c
int num_links(int *tet);
int shape_check(int *tet);
int **read_file(char *file_name, int **all_pieces);
int num_tet(char *file_name);

//fillit.c
//char    *ft_strnew(size_t size, char c);
//char    *generate_board(int num_tet, char c);
//int     piece_fit(char *str, int *tet, int board_size);
//int fill_piece(char *str, int *tet, char c, int board_size);
//void    print_board(char *str, int board_size);
//void	pb(char *str, int board_size);
//void	print_combo(int *num, int n);
//int    num_dots(char *s1);
//int		generate_combo(int **arr, int num_pieces, int board_size);
//int		fill_board(char *str, int **arr, int num_pieces, int *num, int board_size);
//void	fillit(int **arr, int num_pieces);

char    *boardgen(int size, char *board, char c);
int        check(int *tet, int startpos, char *board, int tetnum, int size);
void print_combo(int *num, int n);
int fill_board(char *str, int **arr, int num_pieces, int *num, int board_size);
int    generate_combo(int **arr, int num_pieces, int board_size);
void fillit(int **arr, int num_pieces);





#endif
