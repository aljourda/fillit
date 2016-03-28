/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:41:47 by aljourda          #+#    #+#             */
/*   Updated: 2016/03/22 15:16:40 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int			ft_is_collision(t_tetriminos *tab, t_tetriminos *current)
{
	int				pos;
	int				x;
	int				y;

	pos = 0;
	while (tab[pos].pos >= 'A' && tab[pos].pos <= 'Z')
	{
		if (tab[pos].pos != current->pos)
		{
			y = tab[pos].y - 1;
			while (++y < (tab[pos].y + 4))
			{
				x = tab[pos].x - 1;
				while (++x < (tab[pos].x + 4))
				{
					if (ft_is_display(&(tab[pos]), x, y) != '.'
							&& ft_is_display(current, x, y) != '.')
						return (pos);
				}
			}
		}
		pos++;
	}
	return (-1);
}

int			ft_record_best(t_tetriminos *tab, t_position *best)
{
	int		i;
	int		x;
	int		y;

	x = 0;
	y = 0;
	ft_calc_size(tab, &x, &y);
	if (x <= best[26].x && y <= best[26].y)
	{
		i = 0;
		while (i < 26)
		{
			best[i].x = tab[i].x;
			best[i].y = tab[i].y;
			i++;
		}
		return (1);
	}
	return (0);
}

static void	ft_solver_fct(t_tetriminos *tab, t_position *bst, int i)
{
	tab[i].x = bst[i].x;
	tab[i].y = bst[i].y;
}

void		ft_solver(t_tetriminos *tab, int *x_size, int *y_size)
{
	t_position	*best;
	int			i;

	*x_size = 0;
	*y_size = 0;
	ft_init_place(tab);
	if ((best = malloc(sizeof(t_position) * 27)) == 0)
		return ;
	i = -1;
	best[26].x = 0;
	while (tab[++i].pos >= 'A' && tab[i].pos <= 'Z')
		best[26].x += 4;
	best[26].x = ft_sqrt(best[26].x);
	best[26].y = best[26].x;
	while (ft_place(tab, best, 0, 0) == 0)
	{
		best[26].x++;
		best[26].y++;
	}
	i = -1;
	while (++i < 26)
		ft_solver_fct(tab, best, i);
	*x_size = best[26].x;
	*y_size = best[26].y;
	free(best);
}
