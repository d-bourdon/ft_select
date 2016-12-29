/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:29:44 by dbourdon          #+#    #+#             */
/*   Updated: 2016/12/29 15:32:21 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	nothin(int a)
{
	a = 0;
}

void		ft_wait_enter(void)
{
	char	buff[3];

	signal(SIGKILL, &nothin);
	signal(SIGINT, &nothin);
	signal(SIGQUIT, &nothin);
	while (1)
	{
		read(0, buff, 3);
		if (buff[0] == 10 && buff[1] == 0 && buff[2] == 0)
			break ;
		ft_bzero(buff, 3);
	}
}

void		ft_help(void)
{
	ft_putstr_fd("\033[1;34m**********************************************"
	"****\n*    ______ _      _____      _           _      *\n"
	"*   |  ____| |    / ____|    | |         | |     *\n"
	"*   | |__  | |_  | (___   ___| | ___  ___| |_    *\n"
	"*   |  __| | __|  \\___ \\ / _ \\ |/ _ \\/ __| __|   *\n"
	"*   | |    | |_   ____) |  __/ |  __/ (__| |_    *\n"
	"*   |_|     \\__| |_____/ \\___|_|\\___|\\___|\\__|   *\n"
	"*                                                *\n"
	"**************************************************\033[00m\n\n"
	"\033[01m------------------ Utilisation -------------------\n"
	"\033[0;30;43m-h\033[37;1;40m : Utilisation\n\n"
	"\033[0;30;43m-n\033[37;1;40m : Retrait du \\n en fin de retour\n\n"
	"\033[0;30;43m-s \"expr\"\033[37;1;40m : Remplace les espaces entre les va"
	"leurs\n    de retour par \"expr\". \"\%\" représente la valeur de\n"
	"    retour.\n"
	"    EX: -s \"\\\'\%\\\' \" *  -> \'exemple1\' \'exemple2\' \n\n"
	"\033[0;30;43m-ns / -sn\033[37;1;40m : compile les deux options\n\n"
	"\033[0;30;43m-[*]\033[37;1;40m : Toute autre options est prise comme "
	"choix\n\n\033[0;30;43mesc\033[37;1;40m : Exit et annule la commade si "
	"présente dans\n    des backquotes\n"
	"--------------------------------------------------\033[00m\n"
	"dbourdon                                  v. 1.0.0\n"
	"Appuyez sur enter pour quitter (annule backquotes).", g_info->fd);
	ft_wait_enter();
}

int			ft_parssing_opt(char **tabt, t_info *info)
{
	if (!tabt[1] || ft_strcmp(tabt[1], "-h") == 0)
	{
		ft_help();
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
	return (1);
}
