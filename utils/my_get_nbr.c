/*
** my_get_nbr.c for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Fri Nov 10 14:57:22 2017 BOURDALE Jules
** Last update Fri Nov 10 15:00:05 2017 BOURDALE Jules
*/

int     my_getnbr(char *str)
{
  int   nb;
  int   i;
  int   negativ;

  nb = 0;
  i = 0;
  negativ = 1;
  while (str[i] > 57 || str[i] < 48)
    {
      i++;
    }
  while (str[i] <= 57 && str[i] >= 48)
    {
      nb = nb * 10 + str[i] - 48;
      if (str[i-1] == 45)
        {
          negativ = -1;
        }
      i++;
    }
  return (nb * negativ);
}
