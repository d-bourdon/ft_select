/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 13:20:00 by dbourdon          #+#    #+#             */
/*   Updated: 2016/12/28 15:56:54 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_move(t_info *info, char *buff)
{
		if (buff[1] == 0 && buff[2] == 0)
			return (0);
		if (buff[2] == 67)
			ft_move_next(info);
		if (buff[2] == 66)
			ft_move_down(info);
		if (buff[2] == 68)
			ft_move_prev(info);
		if (buff[2] == 65)
			ft_move_up(info);
		return (1);
}

void	ft_move_down(t_info *info)
{
	t_elem	*tmp;
	int		i;

	tmp = info->elem;
	while (tmp)
	{
		if (tmp->etat == 1)
		{
			i = info->l_win / info->l_max;
			if (i == 1)
				return(ft_move_next(info));
			tmp->etat = 0;
			while (tmp && i > 0)
			{
				tmp = tmp->next;
				i--;
			}
			if (!tmp)
			{
				tmp = info->elem;
				while(tmp && i > 0)
				{
					tmp = tmp->next;
					i--;
				}
			}
			tmp->etat = 1;
			return ;
		}
		tmp = tmp->next;
	}
}


void	ft_move_up(t_info *info)
{
	t_elem	*tmp;

	tmp = info->elem;
	while (tmp)
	{
		tmp = tmp->next;
	}
}