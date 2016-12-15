/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:07:06 by dbourdon          #+#    #+#             */
/*   Updated: 2016/12/15 13:25:40 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int argc, char** argv)
{
	t_info	*info;
	int d;
	d = argc;
	d = argv[0][0];
	info = ft_init_info();
	if (ft_init_term(info) != 0)
	{
		printf("HELLO\n");
 		return (1);
	}
	printf("OK\n");
 	voir_touche();
return (0);
}
 
int     voir_touche()
{
  char     buffer[3];
   char    *res;
 
  while (1)
  {
    read(0, buffer, 3);
    if (buffer[0] == 27)
    {
		if ((res = tgetstr("cl", NULL)) == NULL)
		    return (-1);
		tputs(res, 0, my_outc);
    	printf("C'est une fleche !\n");
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