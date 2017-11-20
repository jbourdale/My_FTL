/*
** my_put_nbr.c for  in /home/dev/C/chifumi/output
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Sat Oct 28 11:42:19 2017 BOURDALE Jules
** Last update Tue Nov  7 10:48:28 2017 BOURDALE Jules
*/
#include "utils.h"

void	my_put_nbr(int n)
{
  if (n == -2147483648)
    {
      my_putstr("-2147483648");
    }
  if (n < 0)
    {
      my_putchar('-');
      my_put_nbr(-n);
    }
  else if (n > 9)
    {
      my_put_nbr(n / 10);
      my_putchar((n % 10) + 48);
    }
  else
    {
      my_putchar((n % 10) + 48);
    }
}
