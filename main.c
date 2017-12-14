/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 22:03:40 by lilam             #+#    #+#             */
/*   Updated: 2017/12/13 19:53:15 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_counters    iters = {0, 0, 0, 0, {0}};

int main(int argc, char **argv)
{
	int **arr;
	arr = malloc(sizeof(**arr) * 26);
//	int shapes_arr[26];
	int j;

	j = 0;
	while (j < 26)
		arr[j++] = malloc(sizeof(int) * 4);
	if (argc == 2)
	{
		int k = 0;
		arr = read_file(argv[1], arr);
		for(k=0; k < iters.tet_count; k = k + 1)
			printf("%dshapes ", iters.shapes_arr[k]);
		if (arr == 0)
		{
			write(1, "error\n", 6);
			return(0);
		}
//		fillit(arr, num_tet(argv[1]));
		fillit(arr, iters.tet_count);
	}
	else
	{
		int i;
		i = 0;
		char usage[] = "usage: ./fillit file.fillit\n";
		while (usage[i])
			i++;
		write(1, &usage, i);
	}
	return (0);
}
