/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 10:44:47 by lilam             #+#    #+#             */
/*   Updated: 2017/12/17 16:08:52 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	line_shape(int *tet)
{
	int i;

	i = 0;
	while (tet[i] && i < 3)
	{
		if (!((tet[i] == tet[i + 1] - (tet[2] - tet[1]))))
			return (0);
		i++;
	}
	return (1);
}

int	square_shape(int *tet)
{
	if (tet[1] - tet[0] == 1 && tet[3] - tet[2] == 1 && tet[2] - tet[1] == 3)
		return (1);
	return (0);
}

int	z_shape(int *tet)
{
	if ((tet[1] - tet[0] == tet[3] - tet[2]) && (tet[2] - tet[1] <= 4))
	{
		if ((tet[1] - tet[0] == 3 && tet[2] - tet[1] == 1)
				|| (tet[1] - tet[0] == 1 && tet[2] - tet[1] == 4))
			return (1);
		else
			return (2);
	}
	return (0);
}

int	l_shape(int *tet)
{
	if (tet[0] == 4 && tet[1] == 8 && tet[2] == 12 && tet[3] == 13)
		return (0);
	if (tet[1] - tet[0] == 1 && tet[2] - tet[1] == 1 && tet[3] - tet[2] == 2)
		return (1);
	if (tet[1] - tet[0] == 2 && tet[2] - tet[1] == 1 && tet[3] - tet[2] == 1)
		return (1);
	if (tet[1] - tet[0] == 1 && tet[2] - tet[1] == 4 && tet[3] - tet[2] == 4)
		return (1);
	if (tet[1] - tet[0] == 4 && tet[2] - tet[1] == 4 && tet[3] - tet[2] == 1)
		return (1);
	if (tet[1] - tet[0] == 4 && tet[2] - tet[1] == 3 && tet[3] - tet[2] == 1)
		return (2);
	if (tet[1] - tet[0] == 1 && tet[2] - tet[1] == 3 && tet[3] - tet[2] == 4)
		return (2);
	if (tet[1] - tet[0] == 1 && tet[2] - tet[1] == 1 && tet[3] - tet[2] == 4)
		return (2);
	if (tet[1] - tet[0] == 4 && tet[2] - tet[1] == 1 && tet[3] - tet[2] == 1)
		return (2);
	return (0);
}

int	t_shape(int *tet)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (tet[i] && i < 3)
	{
		if ((tet[i] == tet[i + 1] - 4 || tet[i] == tet[i + 1] - 1))
			count++;
		i++;
	}
	if (count >= 2 && (tet[1] == tet[3] - 4))
		return (1);
	if (count >= 2 && (tet[0] == tet[2] - 4))
		return (1);
	if (count >= 2 && (tet[1] == tet[2] - 1))
		return (1);
	if (count >= 2 && (tet[1] == tet[2] - 1))
		return (1);
	return (0);
}
