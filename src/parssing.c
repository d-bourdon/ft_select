/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:29:44 by dbourdon          #+#    #+#             */
/*   Updated: 2016/12/15 16:34:36 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_parssing_opt(char **tabt, t_info *info)
{
	if (!tabt[1] || ft_strcmp(tabt[1], "-h") == 0)
	{
		info->opt = 0;
		return (0);
	}
	else if (tabt[2] && tabt[1] && tabt[1][0] == '-')
	{
		if (tabt[1][1] == '1')
			info->opt = 1;
		else if (tabt[1][1] == '2')
			info->opt = 2;
		else if (tabt[1][1] == '3')
			info->opt = 3;
		else
			return (0);
		return (1);
	}
	else if (tabt[1][0] == '-' && !tabt[2])
		info->opt = 0;
	else
		info->opt = 1;
	return (info->opt);
}
