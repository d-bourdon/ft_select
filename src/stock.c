/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 12:36:32 by dbourdon          #+#    #+#             */
/*   Updated: 2016/12/16 14:37:28 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_stock(char **argv, t_info *info, int argc)
{
	int		i;
	t_elem	*elem;

	i = 1;
	if (argv[1][0] == '-')
		i++;
	if (i == 2)
		argc--;
	while (argv[i])
	{
		elem = ft_init_elem();
		elem->name = ft_strdup(argv[i]);
		elem->len = ft_strlen(argv[i]);
		if (elem->len > info->l_max)
			info->l_max = elem->len;
		ft_lstaddend(&(info)->elem, elem);
		i++;
	}
	info->n_elem = argc - 1;
}