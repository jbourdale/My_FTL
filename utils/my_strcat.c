/*
** my_strcat.c for  in /home/dev/C/Jour04/bourda_j/my_strcat
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Thu Oct 19 18:07:07 2017 BOURDALE Jules
** Last update Wed Nov  8 15:34:58 2017 BOURDALE Jules
*/
#include "utils.h"

char	*my_strcat(char *dest, char *src)
{
  int	len_dest;
  int	len_src;
  int	i;

  len_dest = my_strlen(dest);
  len_src = my_strlen(src);
  i = 0;
  while (i < len_src)
    {
      dest[len_dest + i] = src[i];
      ++i;
    }
  return (dest);
}
