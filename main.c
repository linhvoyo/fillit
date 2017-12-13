/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 22:03:40 by lilam             #+#    #+#             */
/*   Updated: 2017/12/12 22:05:48 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char **argv)
{
	int **arr;
	arr = malloc(sizeof(**arr) * 26);
	int j;

	j = 0;
	while (j < 26)
		arr[j++] = malloc(sizeof(int) * 4);
	if (argc == 2)
	{
		arr = read_file(argv[1], arr);
		if (arr == 0)
		{
			write(1, "Error\n", 6);
			return(0);
		}
		fillit(arr, num_tet(argv[1]));
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
