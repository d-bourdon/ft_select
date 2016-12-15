/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:17:01 by dbourdon          #+#    #+#             */
/*   Updated: 2016/12/15 20:58:31 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <termios.h>
# include <curses.h>
# include <unistd.h>
# include <term.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <signal.h>
# include "../libft/libft.h"

typedef struct		s_info
{
	struct termios	term;
	int				opt;
	int				l_win;
	int				h_win;
	int				l_max;
	int				n_elem;
	t_elem			*elem;

}					t_info;

typedef struct		s_elem
{
	char			*name;
	int				len;
	int				etat;
	t_elem			next;
}					t_elem;
/*
** main.c
*/
int					voir_touche(void);
int					my_outc(int c);
/*
** init_term.c
*/
int					ft_init_term(t_info *info);
t_info				*ft_init_info(void);
/*
** parssing.c
*/
int					ft_parssing_opt(char **tabt, t_info *info);


void abc(int a);
#endif
