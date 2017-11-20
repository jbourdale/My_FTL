/*
** my_itoa.c for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Wed Nov  8 15:59:06 2017 BOURDALE Jules
** Last update Fri Nov 10 22:17:07 2017 BOURDALE Jules
*/

#include <stdlib.h>

void		reverse_str(char *str, int n)
{
  int		i;
  char		tmp;

  i = 0;
  while (i < n / 2)
    {
      tmp = str[i];
      str[i] = str[n - 1 - i];
      str[n - 1 - i] = tmp;
      i++;
    }
}

char*	my_itoa(int num, char* str, int base)
{
  int	i;
  int	is_negative;
  int	rem;

  i = 0;
  is_negative = 0;
  if (num == 0)
    {
      str[i++] = '0';
      str[i] = '\0';
      return str;
    }
  if (num < 0 && base == 10)
    {
      is_negative = 1;
      num = -num;
    }
  while (num != 0)
    {
      rem = num % base;
      str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
      num = num / base;
    }
  if (is_negative)
    str[i++] = '-';
  str[i] = '\0';
  reverse_str(str, i);
  return str;
}

char    **explode_save_file(char *content, int nb_lines, char separator)
{
  int   i;
  char  **lines;
  int   filled_lines;
  int   j;

  if ((lines = malloc(nb_lines * sizeof(char*))) == NULL)
    return NULL;
  i = 0;
  while (i < nb_lines)
    {
      if ((lines[i] = malloc(50 * sizeof(char))) == NULL)
        return NULL;
      i++;
    }
  filled_lines = 0;
  i = 0;
  j = 0;
  while (content[i] != '\0')
    {
      if (content[i] == separator)
        {
          lines[filled_lines][j + 1] = '\0';
          filled_lines++;
          j = -1;
        }
      else
        lines[filled_lines][j] = content[i];
      j++;
      i++;
    }
  i = 0;
  return lines;
}
