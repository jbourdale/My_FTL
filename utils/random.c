/*
** random.c for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Mon Nov  6 19:03:07 2017 BOURDALE Jules
** Last update Mon Nov  6 19:45:10 2017 BOURDALE Jules
*/
#include <stdlib.h>
#include <time.h>

int	random_by_percent(int percent)
{
  int	random;

  random = (rand() % 100);
  return random < percent;
}
