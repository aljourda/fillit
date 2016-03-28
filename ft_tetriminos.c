/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetriminos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:55:03 by aljourda          #+#    #+#             */
/*   Updated: 2015/12/10 14:36:23 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

char	ft_is_display(t_tetriminos *current, int cur_x, int cur_y)
{
	if (current != 0)
	{
		cur_x -= current->x;
		cur_y -= current->y;
		if (cur_x >= 0 && cur_x < 4 && cur_y >= 0 && cur_y < 4)
		{
			if (current->data & (1 << (cur_x + cur_y * 4)))
				return (current->pos);
			else
				return ('.');
		}
	}
	return ('.');
}

void	ft_tetri_size(t_tetriminos *current)
{
	int		i;
	int		j;

	current->x_size = 0;
	current->y_size = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (current->data & (1 << (j + i * 4)))
			{
				if (current->x_size < j)
					current->x_size = j;
				if (current->y_size < i)
					current->y_size = i;
			}
			j++;
		}
		i++;
	}
	current->x_size++;
	current->y_size++;
}

int		ft_is_tab_valid(t_tetriminos *tab)
{
	unsigned short t;

	while (tab->pos >= 'A' && tab->pos <= 'Z')
	{
		ft_tetri_normalize(tab);
		ft_tetri_size(tab);
		t = tab->data;
		if (t != 4369 && t != 15 && t != 23 && t != 547 && t != 116 && t != 785
			&& t != 71 && t != 802 && t != 113 && t != 275 && t != 39
			&& t != 305 && t != 114 && t != 562 && t != 99 && t != 306
			&& t != 54 && t != 561 && t != 51)
			return (0);
		tab++;
	}
	return (1);
}

void	ft_tetri_normalize(t_tetriminos *current)
{
	int		i;
	int		j;
	int		x;
	int		y;

	x = 4;
	y = 4;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (current->data & (1 << (j + i * 4)))
			{
				if (x > j)
					x = j;
				if (y > i)
					y = i;
			}
			j++;
		}
		i++;
	}
	current->data >>= (x + y * 4);
}
