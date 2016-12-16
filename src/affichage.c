/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 14:20:09 by dbourdon          #+#    #+#             */
/*   Updated: 2016/12/16 18:34:00 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_affichage(t_info *info)
{
	t_elem			*elem;
	int				i;
	struct winsize	w;

	i = 0;
	elem = info->elem;
	ioctl(0, TIOCGWINSZ, &w);
	info->l_win = w.ws_col;
	info->h_win = w.ws_row;
	while (elem)
	{
		i = ft_print(&elem, info, i);
	}
}

int		ft_print(t_elem **elem, t_info *info, int i)
{
	int		j;
	j = 0;

	if (i == 0 || i < (info->l_win / info->l_max))
	{
		ft_putstr((*elem)->name);
		while (j++ < (info->l_max - (*elem)->len) + 2)
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
