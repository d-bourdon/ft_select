/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 14:25:23 by dbourdon          #+#    #+#             */
/*   Updated: 2016/12/28 11:59:10 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_move_next(t_info *info)
{
	t_elem *tmp;

	tmp = info->elem;
	while (tmp)
	{
		if (tmp->etat != 0)
		{
			tmp->etat = 0;
			if (tmp->next)
				tmp->next->etat = 1;
			else
			{
				info->elem->etat = 1;
				break ;
			}
			tmp = tmp->next;
		}
		tmp = tmp->next;
	}
}

void	ft_move_prev(t_info *info)
{
	t_elem *tmp;
	int		i;

	i = 0;
	tmp = info->elem;
	while (tmp && tmp->next)
	{
		if (tmp->next->etat == 1)
		{
			tmp->next->etat = 0;
			tmp->etat = 1;
			i = 1; 
		}
		tmp = tmp->next;
	}
	if (info->elem->etat == 1 && i != 1)
	{
		info->elem->etat = 0;
		tmp->etat = 1;
	}
}

void	ft_selection(t_info *info)
{
	t_elem *tmp;

	tmp = info->elem;
	while (tmp && tmp->etat != 1)
		tmp = tmp->next;
	if (tmp && tmp->etat == 1)
	{
		if (tmp->select == 1)
			tmp->select = 0;
		else if (tmp->select == 0)
			tmp->select = 1;
		ft_move_next(info);
	}
	else
		ft_erreur("Problème lors de la séléction", 2);
	ft_affichage(info, 1);
}

void	ft_suppr(t_info *info)
{
	t_elem	*tmp;
	t_elem	*tmp2;

	tmp = info->elem;
	if (ft_supprone(info, tmp) == 1)
		return ;
	while (tmp->next && tmp->next->etat != 1)
		tmp = tmp->next;
	if (tmp->next && tmp->next->etat == 1)
	{
		ft_move_next(info);
		tmp2 = tmp->next;
		free(tmp2->name);
		if (tmp->next->next != NULL)
			tmp->next = tmp->next->next;
		else
			tmp->next = NULL;
		free(tmp2);
		ft_affichage(info, 1);
	}
}

void	ft_return(t_info *info)
{
	t_elem	*tmp;

	tmp = info->elem;
	tcsetattr(0, TCSADRAIN, &(tinfo->b_term));
	ft_putstr_fd("\033[?1049l", info->fd);
	tputs(tgetstr("ve", NULL), 1, my_outc);
	while (tmp)
	{
		if (tmp->select == 1)
		{
			ft_putstr(tmp->name);
			ft_putchar(' ');
		}
		free(tmp->name);
		tmp = tmp->next;
	}
	ft_putchar('\n');
	exit(0);
}
