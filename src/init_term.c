/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 12:32:49 by dbourdon          #+#    #+#             */
/*   Updated: 2016/12/28 20:07:19 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_info	*ft_init_info(void)
{
	t_info	*info;
	
	info = (t_info*)malloc(sizeof(t_info));
	info->opt = 0;
	info->opts = NULL;
	info->l_win = 0;
	info->h_win = 0;
	info->l_max = 0;
	info->n_elem = 0;
	info->elem = NULL;
	info->fd = open("/dev/tty", O_RDWR);
	if (info->fd == -1)
		ft_erreur("fail ouverture /dev/tty", 2);
	return (info);
}

t_elem	*ft_init_elem(void)
{
	t_elem *elem;

	elem = (t_elem*)malloc(sizeof(t_elem));
	elem->name = NULL;
	elem->len = 0;
	elem->etat = 0;
	elem->next = NULL;
	elem->select = 0;
	return (elem);
}

int		ft_init_term(t_info *info)
{
	char	*name_term;

	if ((name_term = getenv("TERM")) == NULL)
		name_term = ft_strdup("vt100");
	if (tgetent(NULL, name_term) == -1)
		return (-1);
	if (tcgetattr(0, &(info->term)) == -1)
		return (-1);
	if (tcgetattr(0, &(info->b_term)) == -1)
		return (-1);
	info->term.c_lflag &= ~(ICANON);
	info->term.c_lflag &= ~(ECHO);
	info->term.c_cc[VMIN] = 1;
	info->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &(info->term)) == -1)
		return (-1);
	tputs(tgetstr("vi", NULL), 1, my_outc);
	return (0);
}
