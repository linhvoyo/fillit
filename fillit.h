/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:17:11 by lilam             #+#    #+#             */
/*   Updated: 2017/12/11 11:50:48 by lilam            ###   ########.fr       */
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

int line_shape(int *tet);
int square_shape(int *tet);
int z_shape(int *tet);
int l_shape(int *tet);
int num_links(int *tet);
int t_shape(int *tet);
int shape_check(int *tet);
int num_tet(char *file_name);
char    *ft_strnew(size_t size);
char    *generate_board(int num_tet);
void fillit(int **arr, int num_pieces);




#endif
