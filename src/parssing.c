/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:29:44 by dbourdon          #+#    #+#             */
/*   Updated: 2016/12/28 20:00:13 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_parssing_opt(char **tabt, t_info *info)
{
	if (!tabt[1] || ft_strcmp(tabt[1], "-h") == 0)
	{
		return (0);
	}
	if (tabt[1] && tabt[2] && tabt[1][0] == '-')
	{
		if (tabt[1][1] == 'n' && !tabt[1][2])
			info->opt = 2;
		if (tabt[1][1] == 's' && !tabt[1][2])
		{
			info->opt = 3;
			info->opts = ft_strsplit(tabt[2], '%');
		}
		if ((tabt[1][1] == 'n' && tabt[1][2] == 's' && !tabt[1][3]) ||
			(tabt[1][1] == 's' && tabt[1][2] == 'n' && !tabt[1][3]))
		{
			info->opt = 4;
			info->opts = ft_strsplit(tabt[2], '%');
		}
		return (1);
	}
	else
		info->opt = 1;
	return (info->opt);
}
