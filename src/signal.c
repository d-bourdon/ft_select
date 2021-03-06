/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:07:06 by dbourdon          #+#    #+#             */
/*   Updated: 2016/12/29 15:21:33 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	c_signal(void)
{
	signal(SIGWINCH, &abc);
	signal(SIGKILL, &abc);
	signal(SIGINT, &abc);
	signal(SIGQUIT, &abc);
	signal(SIGTSTP, &stop);
	signal(SIGCONT, cont);
}

void	abc(int a)
{
	a = 0;
	ft_affichage(g_info, 1);
}

void	stop(int a)
{
	char	c;

	a = 0;
	if (tcsetattr(0, TCSADRAIN, &(g_info->b_term)) == -1)
		return ;
	ft_putstr_fd("\033[?1049l", g_info->fd);
	tcgetattr(0, &(g_info->term));
	c = g_info->term.c_cc[VSUSP];
	ioctl(0, TIOCSTI, &c);
	signal(SIGTSTP, SIG_DFL);
	tputs(tgetstr("ve", NULL), 1, my_outc);
}

void	cont(int a)
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
	ft_putstr_fd("\033[?1049h\033[H", g_info->fd);
	ft_affichage(g_info, 1);
}
