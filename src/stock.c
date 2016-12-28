/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 12:36:32 by dbourdon          #+#    #+#             */
/*   Updated: 2016/12/28 19:51:40 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_stock(char **argv, t_info *info, int argc)
{
	int		i;
	t_elem	*elem;

	i = 1;
	if (info->opt != 1)
		i++;
	if (info->opt >= 3)
		i++;
	if (i >= 2)
		argc = argc - (i - 1);
	while (argv[i])
	{
		elem = ft_init_elem();
		elem->name = ft_strdup(argv[i]);
		elem->len = ft_strlen(argv[i]);
		if (elem->len + 1 > info->l_max)
			info->l_max = elem->len + 1;
		ft_lstaddend(&(info)->elem, elem);
		i++;
	}
	info->n_elem = argc - 1;
}
