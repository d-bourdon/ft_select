/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:07:06 by dbourdon          #+#    #+#             */
/*   Updated: 2016/12/28 11:19:23 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int argc, char** argv)
{
	t_info	*info;
	int 	i;
	i = argc;
	info = ft_init_info();
	ft_putstr_fd("\033[?1049h\033[H", info->fd);
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
	ft_putstr_fd("\033[?1049l", info->fd);
	tputs(tgetstr("ve", NULL), 1, my_outc);
	return (1);
}

int		voir_touche(t_info *info)
{
	char	buffer[3];

	c_signal();
	while (1)
	{
	read(0, buffer, 3);
	if (buffer[0] == 27)
	{
		if (buffer[1] == 0 && buffer[2] == 0)
			return (0);
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
	ft_putchar_fd(c, tinfo->fd);
	return(0);
}
