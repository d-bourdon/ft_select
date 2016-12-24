/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:07:06 by dbourdon          #+#    #+#             */
/*   Updated: 2016/12/19 15:25:26 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int argc, char** argv)
{
	t_info	*info;
	int 	i;
	i = argc;
	ft_putstr("\033[?1049h\033[H");
	info = ft_init_info();
	tinfo = info;
	if (ft_parssing_opt(argv, info) == 0)
		ft_erreur(NULL, 1);
	ft_stock(argv, info, argc);
	info->elem->etat = 1;
	ft_affichage(info, 0);

	if (ft_init_term(info) != 0)
		ft_erreur(NULL, 1);
	voir_touche(info);
	tcsetattr(0, TCSADRAIN, &(tinfo->b_term));
	ft_putstr("\033[?1049l");
	tputs(tgetstr("ve", NULL), 1, my_outc);
	//ft_putstr("test un deux\n");
return (0);
}

void abc(int a)
{
	a = 0;
	ft_affichage(tinfo, 1);
}

void stop(int a)
{
	char	c;
	a = 0;
	if (tcsetattr(0, TCSADRAIN, &(tinfo->b_term)) == -1)
		return ;
	ft_putstr_fd("\033[?1049l", 2);
	tcgetattr(0, &(tinfo->term));
	c = tinfo->term.c_cc[VSUSP];
	ioctl(0, TIOCSTI, &c);
	signal(SIGTSTP, SIG_DFL);
	tputs(tgetstr("ve", NULL), 1, my_outc);
}

int     voir_touche(t_info *info)
{
  char     buffer[3];

 signal(SIGWINCH, &abc);
 signal(SIGKILL, &abc);
 signal(SIGTSTP, &stop);
 signal(SIGCONT, cont);
   while (1)
  {
    read(0, buffer, 3);
    if (buffer[0] == 27)
    {
    	if (buffer[2] == 67 || buffer[2] == 66)
			ft_move_next(info);
		if (buffer[2] == 68 || buffer[2] == 65)
			ft_move_prev(info);
    }
    else if (buffer[0] == 32 && buffer[1] == 0 && buffer[2] == 0)
    	ft_selection(info);
    else if (buffer[0] == 127 && buffer[1] == 0 && buffer[2] == 0)
    	ft_suppr(info);
    else if (buffer[0] == 10 && buffer[1] == 0 && buffer[2] == 0)
    	ft_return(info);
    ft_bzero(buffer, 3);
    ft_affichage(info, 1);
   }
  return (0);
}

int		my_outc(int c)
{
	ft_putchar(c);
	return(0);
}

void		cont(int a)
{
	char			*term_name;
	struct termios	term_actual;
	a = 0;
	signal(SIGTSTP, stop);
	if (!(term_name = getenv("TERM")))
		return ;
	if (!(tgetent(NULL, term_name)))
		return ;
	if (tcgetattr(0, &term_actual) == -1)
		return ;
	term_actual.c_lflag &= ~(ICANON);
	term_actual.c_lflag &= ~(ECHO);
	tputs(tgetstr("vi", NULL), 1, my_outc);
	if (tcsetattr(0, TCSADRAIN, &term_actual) == -1)
		return ;
	ft_putstr("\033[?1049h\033[H");
	ft_affichage(tinfo, 1);
}
