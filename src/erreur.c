/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erreur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 11:01:32 by dbourdon          #+#    #+#             */
/*   Updated: 2016/12/27 08:29:48 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void ft_erreur(char *str, int mode)
{
	if (mode == 1 && !str)
	{
		tcsetattr(0, TCSADRAIN, &(tinfo->b_term));
		ft_putstr("\033[?1049l");
		tputs(tgetstr("ve", NULL), 1, my_outc);
		exit(1);
	}
	if (mode == 2 && str)
	{
		tcsetattr(0, TCSADRAIN, &(tinfo->b_term));
		ft_putstr("\033[?1049l");
		tputs(tgetstr("ve", NULL), 1, my_outc);
		ft_putstr("ERREUR FATAL : ");
		ft_putstr(str);
		ft_putchar('\n');
		exit(1);
	}
}

int		ft_supprone(t_info *info, t_elem *tmp)
{
	if (tmp->etat == 1 && tmp->next == NULL)
	{
		free(tmp->name);
		free(tmp);
		ft_erreur(NULL, 1);
	}
	if (tmp->etat == 1 && tmp->next)
	{
		ft_move_next(info);
		free(tmp->name);
		info->elem = info->elem->next;
		free(tmp);
		ft_affichage(info, 1);
		return (1);
	}
	return (0);
}
