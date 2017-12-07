/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:14:54 by lilam             #+#    #+#             */
/*   Updated: 2017/12/07 14:20:00 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	read_file(char *file_name)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE];

	fd = open(file_name, O_RDONLY);
	ret = read(fd, buf, BUF_SIZE);
	//while ((ret = read(fd, buf, BUF_SIZE)))	
	//	write(1, buf, ret);

	int i = 0;
	int count_x = 0;
	int count_y = 0;
	while(buf[i])
	{
		if (!(buf[i] == '.' || buf[i] == '#' || buf[i] == '\n'))
			write(1, "Error_char\n", 11);
		while (buf[i] == '.' || buf[i] == '#')
		{
			count_x++;
			i++;
		}
		if (count_x == 4)
		{
			write(1, &buf[i - 4], 1);
			write(1, &buf[i - 3], 1);
			write(1, &buf[i - 2], 1);
			write(1, &buf[i - 1], 1);
			write(1, "\n", 1);
			count_x = 0;
			count_y++;
		}
		else if (count_x != 0)
		{
			count_x = 0;
			count_y++;
			write(1, "Error_x\n", 8);
		}
		if (buf[i] == '\n' && (buf[i + 1] == '\n' || buf[i + 1] == '\0'))
		{
			write(1, &buf[i], 1);
			if (!(count_y == 4))
				write(1, "Error_y\n", 8);
			count_y = 0;
		}
		i++;
	}
//	printf("%d\n", count_y);
//	printf("%d\n", i);
//	printf("%d\n", count);
	close(fd);
}


int main(int argc, char **argv)
{
	if (argc == 2)
		read_file(argv[1]);
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
