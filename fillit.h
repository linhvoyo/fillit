/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:17:11 by lilam             #+#    #+#             */
/*   Updated: 2017/12/12 22:12:40 by lilam            ###   ########.fr       */
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
#define BUF_SIZE 4096

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
char    *ft_strnew(size_t size);
char    *generate_board(int num_tet);
int     piece_fit(char *str, int *tet);
int		fill_board(char *str, int **arr, int num_pieces, int *num);
void    print_board(char *str, int board_size);
void pb(char *str, int board_size);
void print_combo(int *num, int n);
int generate_combo(int **arr, int num_pieces, int board_size);
int fill_board(char *str, int **arr, int num_pieces, int *num);
void fillit(int **arr, int num_pieces);



#endif
