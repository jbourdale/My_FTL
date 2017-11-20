/*
** parse_args.c for  in /home/dev/C/chifumi/init
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Sat Oct 28 11:41:22 2017 BOURDALE Jules
** Last update Fri Nov 10 23:28:47 2017 BOURDALE Jules
*/
#include "core/core.h"
#include "utils/utils.h"

int 		parse_args(int argc, char **argv)
{
  int		i;

  i = 0;
  while (i < argc)
    {
      if (my_strcmp(argv[i], "--help") == 0 || my_strcmp(argv[i], "-h") == 0)
        {
          usage(argv);
          return 1;
        }
      else if (my_strcmp(argv[i], "--nogui") == 0 || my_strcmp(argv[i], "-n") == 0)
        get_options(1, "gui", 0);
      i++;
    }
  return 0;
}

void    usage(char **argv)
{
  my_putstr("Usage : ");
  my_putstr(argv[0]);
  my_putstr(" [OPTIONS]\n");
  my_putstr("\tOPTIONS :\n");
  my_putstr("\t\t--nogui | -n : Disabled graphique user interface\n");
  my_putstr("\t\t--help | -h : Display this page\n");
}
