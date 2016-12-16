/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:07:06 by dbourdon          #+#    #+#             */
/*   Updated: 2016/12/16 19:06:43 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int argc, char** argv)
{
	t_info	*info;
	int 	i;
	i = argc;
	ft_putstr("\033[?1049h\033[H");
	info = ft_init_info();
	tinfo = info;
	if (ft_parssing_opt(argv, info) == 0)
		exit(0);// traitement erreur, affichage aide
	ft_stock(argv, info, argc);
	info->elem->etat = 1;
	ft_affichage(info);
	// while (info->elem)
	// {
	// 	printf("%s - %d - %d\n", info->elem->name, info->elem->len, info->elem->etat);
	// 	info->elem = info->elem->next;
	// } 
	if (ft_init_term(info) != 0)
		return (1);
	voir_touche();
	ft_putstr("\033[?1049l");
return (0);
}

void abc(int a)
{
	a = 0;
	char *res; 
	if ((res = tgetstr("cl", NULL)) == NULL)
 	    return;
 	tputs(res, 0, my_outc);
	ft_affichage(tinfo);
	//ft_putstr("TA modif la fenettre");
}

int     voir_touche()
{
  char     buffer[3];
  t_elem *tmp;
  tmp = tinfo->elem;
  char    *res;
 //int  blop;
  //char 	*area;
  //struct winsize	w;
 signal(SIGWINCH, &abc);
  while (1)
  {
    read(0, buffer, 3);
    if (buffer[0] == 27)
    {
		while (tmp)
		{
			if (tmp->etat != 0)
			{
				tmp->etat = 0;
				if (tmp->next)
					tmp->next->etat = 1;
				else
				{
					tinfo->elem->etat = 1;
					break;
				}
				tmp = tmp->next;
			}
			tmp = tmp->next;
		}
		tmp = tinfo->elem;
		if ((res = tgetstr("cl", NULL)) == NULL)
	 	    return (-1);
	 	tputs(res, 0, my_outc);
		ft_affichage(tinfo);
    }
    else if (buffer[0] == 4)
    {
      printf("Ctlr+d, on quitte !\n");
      return (0);
    }
  }
  return (0);
}

int		my_outc(int c)
{
	ft_putchar(c);
	return(0);
}
