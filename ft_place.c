/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 13:34:11 by svassal           #+#    #+#             */
/*   Updated: 2016/03/22 15:05:29 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

static void	ft_place_fct(unsigned char utils[4], t_tetriminos *tab,
	unsigned char pos, int fct)
{
	if (fct == 1)
	{
		utils[0] = tab[pos].x;
		utils[1] = tab[pos].y;
		utils[2] = 1;
	}
	else if (fct == 2)
	{
		tab[pos].x = utils[0];
		tab[pos].y = utils[1];
	}
}

int			ft_place(t_tetriminos *tab, t_position *best,
	unsigned char pos, unsigned char line)
{
	unsigned char	utils[4];

	if (pos > 25 || tab[pos].pos == 0)
		return (ft_record_best(tab, best));
	ft_place_fct(utils, tab, pos, 1);
	while (line < best[26].y)
	{
		utils[3] = -1;
		while (++utils[3] < best[26].x)
		{
			tab[pos].x = utils[3];
			tab[pos].y = line;
			while (ft_is_collision(tab, &tab[pos]) != -1)
				tab[pos].x++;
			utils[3] = tab[pos].x;
			if (ft_place(tab, best, pos + utils[2], 0) == 1)
				return (1);
		}
		line++;
		ft_place_fct(utils, tab, pos, 2);
	}
	return (0);
}

void		ft_init_place(t_tetriminos *tab)
{
	int		i;

	i = 0;
	while (tab[i].pos >= 'A' && tab[i].pos <= 'Z')
	{
		tab[i].x = (i + 1) * -4;
		i++;
	}
}

void		ft_calc_size(t_tetriminos *tab, int *x_size, int *y_size)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (tab[i].pos >= 'A' && tab[i].pos <= 'Z')
	{
		x = (tab[i].x + tab[i].x_size);
		y = (tab[i].y + tab[i].y_size);
		if (*x_size < x)
			*x_size = x;
		if (*y_size < y)
			*y_size = y;
		i++;
	}
}

int			ft_sqrt(int val)
{
	int	i;

	i = 1;
	while (i * i < val)
		i++;
	return (i);
}
