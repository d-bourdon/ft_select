/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:07:06 by dbourdon          #+#    #+#             */
/*   Updated: 2016/12/29 15:29:17 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int argc, char **argv)
{
	t_info	*info;
	int		i;

	i = argc;
	info = ft_init_info();
	g_info = info;
	ft_putstr_fd("\033[?1049h\033[H", info->fd);
	if (ft_init_term(info) != 0)
		ft_erreur(NULL, 1);
	if (ft_parssing_opt(argv, info) == 0)
		ft_erreur(NULL, 1);
	ft_stock(argv, info, argc);
	info->elem->etat = 1;
	ft_affichage(info, 0);
	voir_touche(info);
	tcsetattr(0, TCSADRAIN, &(info->b_term));
	ft_putstr_fd("\033[?1049l", info->fd);
	tputs(tgetstr("ve", NULL), 1, my_outc);
	kill(getppid(), SIGINT);
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
			if (ft_move(info, buffer) == 0)
				return (0);
		if (buffer[0] == 32 && buffer[1] == 0 && buffer[2] == 0)
			ft_selection(info);
		else if (buffer[0] == 127 && buffer[1] == 0 && buffer[2] == 0)
			ft_suppr(info);
		else if (buffer[0] == 126 && buffer[1] == 0 && buffer[2] == 0)
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
	ft_putchar_fd(c, g_info->fd);
	return (0);
}
