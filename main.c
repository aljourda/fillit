/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljourda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:48:18 by aljourda          #+#    #+#             */
/*   Updated: 2015/12/09 15:57:20 by aljourda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int		main(int argc, char **argv)
{
	t_tetriminos	*tab;
	int				x_size;
	int				y_size;

	if (argc == 2)
	{
		tab = ft_parse(argc, argv);
		if (tab != 0)
		{
			if (ft_is_tab_valid(tab))
			{
				ft_solver(tab, &x_size, &y_size);
				ft_display(tab, x_size, y_size);
			}
			else
				write(1, "error\n", 6);
		}
		else
			write(1, "error\n", 6);
	}
	else
		write(1, "usage: fillit file\n", 19);
	return (0);
}
