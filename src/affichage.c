/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 14:20:09 by dbourdon          #+#    #+#             */
/*   Updated: 2016/12/28 11:16:17 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_affichage(t_info *info, int mode)
{
	t_elem			*elem;
	int				i;
	struct winsize	w;
	char			*res;

	i = 0;
	if (mode == 1)
	{
		if ((res = tgetstr("cl", NULL)) == NULL)
			return ;
		tputs(res, 0, my_outc);
	}
	elem = info->elem;
	ioctl(0, TIOCGWINSZ, &w);
	info->l_win = w.ws_col;
	info->h_win = w.ws_row;
	if ((float)info->h_win < (float)(info->n_elem + 1) / (float)(info->l_win / info->l_max))
	{
		ft_putstr_fd("Fenètre trop petite !!! \n", info->fd);
		//printf("%f\n", (info->n_elem + 1) / (float)(info->l_win / info->l_max));
		return ;
	}
	while (elem)
		i = ft_print(&elem, info, i);
}

int		ft_print(t_elem **elem, t_info *info, int i)
{
	int		j;

	j = 0;
	if (i == 0 || i < (info->l_win / info->l_max))
	{
		if ((*elem)->etat == 1 )
			ft_putstr_fd("\033[4m", info->fd);
		if ((*elem)->select == 1)
			ft_putstr_fd("\033[7m", info->fd);
		ft_putstr_fd((*elem)->name, info->fd);
		if ((*elem)->etat == 1 || (*elem)->select == 1)
			ft_putstr_fd("\033[0m", info->fd);
		while (j++ < (info->l_max - (*elem)->len))
			ft_putchar_fd(' ', info->fd);
		i++;
		j = 0;
		*elem = (*elem)->next;
	}
	else
	{
		ft_putchar_fd('\n', info->fd);
		i = 0;
	}
	return (i);
}
