/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:17:01 by dbourdon          #+#    #+#             */
/*   Updated: 2016/12/19 14:37:37 by dbourdon         ###   ########.fr       */
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
	struct s_elem	*elem;

}					t_info;

typedef struct		s_elem
{
	char			*name;
	int				len;
	int				etat;
	int				select;
	struct s_elem	*next;
}					t_elem;

t_info				*tinfo;
/*
** main.c
*/
int					voir_touche(t_info *info);
int					my_outc(int c);
void				abc(int a);

/*
** init_term.c
*/
int					ft_init_term(t_info *info);
t_elem				*ft_init_elem(void);
t_info				*ft_init_info(void);

/*
** parssing.c
*/
int					ft_parssing_opt(char **tabt, t_info *info);

/*
** ft_lstaddend.c
*/
void				ft_lstaddend(t_elem **liste, t_elem *ajout);

/*
** stock.c
*/
void				ft_stock(char **argv, t_info *info, int argc);

/*
** affichage.c
*/
void				ft_affichage(t_info *info, int mode);
int					ft_print(t_elem **elem, t_info *info, int i);
/*
** erreur.c
*/
void				ft_erreur(char *str, int mode);

/*
** mouv.c
*/
void				ft_move_next(t_info *info);
void				ft_move_prev(t_info *info);
void				ft_selection(t_info *info);
void				ft_suppr(t_info *info);
void				ft_return(t_info *info);

#endif