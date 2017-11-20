/*
** my_strcpy.c for  in /home/dev/C/Jour04/bourda_j/my_strcpy
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Thu Oct 19 15:36:12 2017 BOURDALE Jules
** Last update Fri Oct 20 21:56:05 2017 BOURDALE Jules
*/
int	my_strlen(char *str);

char	*my_strcpy(char *dest, char *src)
{
  int	len;
  int	i;

  len = my_strlen(src);
  i = 0;
  while (i < len)
    {
      dest[i] = src[i];
      ++i;
    }
  dest[i] = '\0';
  return (dest);
}
