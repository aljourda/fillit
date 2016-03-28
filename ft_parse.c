/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 11:56:59 by svassal           #+#    #+#             */
/*   Updated: 2016/03/24 14:37:08 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int				ft_istetravalid(char *tmp, int len)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (tmp[4] != '\n' || tmp[9] != '\n' || tmp[14] != '\n' || tmp[19] != '\n')
		return (0);
	if (len == 21 && tmp[20] != '\n')
		return (0);
	while (i < len && count <= 4)
	{
		if (i == 4 || i == 9 || i == 14 || i == 14 || i == 19)
			i += 1;
		if (i == (len - 1) || i == len)
			return (len);
		if (tmp[i] != '.' && tmp[i] != '#')
			return (0);
		if (tmp[i] == '#')
			count += 1;
		i += 1;
	}
	return (0);
}

unsigned short	ft_bindtetra(char *tmp)
{
	int				i;
	int				j;
	unsigned short	ret;

	i = 0;
	j = 0;
	ret = 0;
	while (i < 21)
	{
		if (tmp[i] == '#')
			ret |= 1 << j;
		if (tmp[i] != '\n')
			j++;
		i++;
	}
	return (ret);
}

int				ft_ismapvalid(t_tetriminos *tab, int fd, char *tmp)
{
	int		len;
	int		valid;
	int		i;

	i = 0;
	len = 0;
	valid = 0;
	while (((len = read(fd, tmp, 21)) >= 20))
	{
		if ((valid = ft_istetravalid(tmp, len)) > 0)
		{
			tab->data = ft_bindtetra(tmp);
			tab->pos = i + 'A';
		}
		else
			break;
		i += 1;
		tab += 1;
	}
	if (valid == 0 || valid > 20)
		return (0);
	if (len > 0)
		return (0);
	return (1);
}

t_tetriminos	*ft_parse(int argc, char **argv)
{
	int				fd;
	t_tetriminos	*tab;
	t_tetriminos	*mem;
	char			*tmp;

	if (argc != 2)
		return (0);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (0);
	if ((tab = malloc(sizeof(t_tetriminos) * 26)) == 0)
		return (0);
	if ((tmp = malloc(sizeof(char) * 21)) == 0)
		return (0);
	mem = tab;
	if (ft_ismapvalid(tab, fd, tmp) == 0)
	{
		close(fd);
		free(tmp);
		return (0);
	}
	close(fd);
	free(tmp);
	return (mem);
}
