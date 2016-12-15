/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:07:06 by dbourdon          #+#    #+#             */
/*   Updated: 2016/12/15 19:00:52 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int argc, char** argv)
{
	t_info	*info;
	int 	i;
	i = 1;
	//ft_putstr("\033[?1049h\033[H");
	info = ft_init_info();
	if (ft_parssing_opt(argv, info) == 0)
	{
		printf("HELLO %d\n", info->opt);
		exit(0);
	}
	printf("OPT : %d\n", info->opt);
	if (argv[1][0] == '-')
		i++;
	while (argv[i] && i < argc)
	{
		printf("%s\n", argv[i]);
		i++;
	} 
	if (ft_init_term(info) != 0)
		return (1);

	voir_touche();
	//ft_putstr("\033[?1049l");
return (0);
}

int     voir_touche()
{
  char     buffer[3];
  //char    *res;
  int  blop;
  //char 	*area;
  struct winsize	w;
 
  while (1)
  {
    read(0, buffer, 3);
    if (buffer[0] == 27)
    {
	ioctl(0, TIOCGWINSZ, &w);
    	blop = tgetnum("co");
		//if ((res = tgetstr("co", NULL)) == NULL)
		  //  return (-1);
		printf("test %d - %d\n", w.ws_col, w.ws_row);
		//tputs(res, 1, my_outc);
    	//printf("C'est une fleche !\n");
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
