/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 14:25:41 by svassal           #+#    #+#             */
/*   Updated: 2016/03/22 15:17:31 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_tetriminos
{
	unsigned short	data;
	unsigned char	x;
	unsigned char	y;
	unsigned char	x_size;
	unsigned char	y_size;
	char			pos;
}				t_tetriminos;

typedef struct	s_position
{
	unsigned char	x;
	unsigned char	y;
}				t_position;

int				ft_istetravalid(char *tmp, int len);
unsigned short	ft_bindtetra(char *tmp);
int				ft_ismapvalid(t_tetriminos *tab, int fd, char *tmp);
t_tetriminos	*ft_parse(int argc, char **argv);
char			ft_is_display(t_tetriminos *current, int cur_x, int cur_y);
int				ft_is_tab_valid(t_tetriminos *current);
void			ft_tetri_normalize(t_tetriminos *tab);
void			ft_tetri_size(t_tetriminos *current);
char			ft_checklist(t_tetriminos *tab, int x, int y);
void			ft_display(t_tetriminos	*tab, int x_size, int y_size);
void			ft_init_place(t_tetriminos *tab);
int				ft_is_collision(t_tetriminos	*tab, t_tetriminos *current);
void			ft_calc_size(t_tetriminos *tab, int *x_size, int *y_size);
int				ft_record_best(t_tetriminos *tab, t_position *best);
void			ft_solver(t_tetriminos	*tab, int *x_size, int *y_size);
int				ft_sqrt(int val);
int				ft_place(t_tetriminos *tab, t_position *best, unsigned char pos,
	unsigned char line);
#endif
