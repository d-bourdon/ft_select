/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 14:38:34 by dbourdon          #+#    #+#             */
/*   Updated: 2016/12/16 12:35:39 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_lstaddend(t_elem **liste, t_elem *ajout)
{
	t_elem	*tmp;

	tmp = *liste;
	if (*liste == NULL)
	{
		*liste = ajout;
		return ;
	}
	else
	{
		while (tmp && tmp->next)
			tmp = tmp->next;
		if (ajout != NULL)
			tmp->next = ajout;
	}
}
