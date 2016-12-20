/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 14:20:09 by dbourdon          #+#    #+#             */
/*   Updated: 2016/12/19 15:27:11 by dbourdon         ###   ########.fr       */
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
		ft_putstr("Fenètre trop petite !!! \n");
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
			ft_putstr("\033[4m");
		if ((*elem)->select == 1)
			ft_putstr("\033[7m");
		ft_putstr((*elem)->name);
		if ((*elem)->etat == 1 || (*elem)->select == 1)
			ft_putstr("\033[0m");
		while (j++ < (info->l_max - (*elem)->len))
			ft_putchar(' ');
		i++;
		j = 0;
		*elem = (*elem)->next;
	}
	else
	{
		ft_putchar('\n');
		i = 0;
	}
	return (i);
}
