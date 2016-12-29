/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 18:20:46 by dbourdon          #+#    #+#             */
/*   Updated: 2016/12/29 15:21:02 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				ft_move(t_info *info, char *buff)
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

static t_elem	*ft_move_down2(t_info *info, int i, int j)
{
	t_elem	*tmp;

	if (info->n_elem % j != 0)
		i = i - (j - (info->n_elem % j));
	if (i < 0)
		i = j - 1;
	tmp = info->elem;
	while (tmp && i-- > 0)
		tmp = tmp->next;
	return (tmp);
}

void			ft_move_down(t_info *info)
{
	t_elem	*tmp;
	int		i;
	int		j;

	j = info->l_win / info->l_max;
	i = j;
	tmp = info->elem;
	while (tmp)
	{
		if (tmp->etat == 1)
		{
			tmp->etat = 0;
			while (tmp && i-- > 0)
				tmp = tmp->next;
			if (!tmp)
				tmp = ft_move_down2(info, i, j);
			tmp->etat = 1;
			return ;
		}
		tmp = tmp->next;
	}
}

void			ft_move_up(t_info *info)
{
	int		i;
	int		j;
	t_elem	*tmp;

	tmp = info->elem;
	j = info->l_win / info->l_max;
	i = 1;
	while (tmp && tmp->etat != 1)
	{
		tmp = tmp->next;
		i++;
	}
	if (i > j)
		i = j;
	else
		i = i - (i % j) + (info->n_elem % j);
	while (i-- > 0)
		ft_move_prev(info);
}
