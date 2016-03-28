/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:48:55 by svassal           #+#    #+#             */
/*   Updated: 2016/03/22 13:28:02 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void	ft_display(t_tetriminos *tab, int x_size, int y_size)
{
	char			c;
	int				x;
	int				y;

	y = -1;
	while (++y < y_size)
	{
		x = -1;
		while (++x < x_size)
		{
			c = ft_checklist(tab, x, y);
			if (c == ' ')
				write(1, "\033[31;1;5;1m.\033[0m", 16);
			else
			{
				if (c == '0')
					write(1, "\033[31;1;5;1m", 11);
				write(1, &c, 1);
				if (c == '0')
					write(1, "\033[0m", 4);
			}
		}
		write(1, "\n", 1);
	}
}

char	ft_checklist(t_tetriminos *tab, int x, int y)
{
	char		c;
	char		tmp;

	c = ' ';
	while (tab->pos >= 'A' && tab->pos <= 'Z')
	{
		tmp = ft_is_display(tab, x, y);
		if ((c == '.' || c == ' ') && (tmp >= 'A' && tmp <= 'Z'))
			c = tmp;
		else if (c == ' ' && tmp != ' ')
			c = tmp;
		else if ((c != '.') && (tmp >= 'A' && tmp <= 'Z'))
		{
			c = '0';
			break ;
		}
		tab++;
	}
	return (c);
}
