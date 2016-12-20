/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erreur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 11:01:32 by dbourdon          #+#    #+#             */
/*   Updated: 2016/12/19 11:13:25 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void ft_erreur(char *str, int mode)
{
	if (mode == 1 && !str)
	{
		ft_putstr("\033[?1049l");
		exit(1);
	}
	if (mode == 2 && str)
	{
		ft_putstr("\033[?1049l");
		ft_putstr("ERREUR FATAL : ");
		ft_putstr(str);
		ft_putchar('\n');
		exit(1);
	}
}