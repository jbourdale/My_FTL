/*
** sector.c for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Fri Nov 10 15:42:12 2017 BOURDALE Jules
** Last update Fri Nov 10 22:01:52 2017 BOURDALE Jules
*/

#include <unistd.h>
#include "ftl.h"
#include "save.h"
#include "utils/utils.h"
#include "sector/sector.h"

int             save_sectors(int fd, t_sector **sectors)
{
  t_sector     **sector;

  if ((sector = malloc(sizeof(t_sector *))) == NULL)
    return 1;
  *sector = *sectors;
  while ((*sector)->prev != NULL)
    *sector = (*sector)->prev;
  while ((*sector)->next != NULL)
    {
      if (save_sector(fd, *sector))
        return 1;
      *sector = (*sector)->next;
    }
  return 0;
}

int             save_int(int fd, int val)
{
  char          *value;

  if ((value = malloc(2 * sizeof(char))) == NULL)
    return 1;
  my_itoa(val, value, 10);
  write(fd, value, my_strlen(value));
  free(value);
  return 0;
}

int     save_sector(int fd, t_sector *sector)
{
  if (sector->ennemi != NULL)
    {
      if (save_int(fd, sector->ennemi->damage))
        return 1;
      write(fd, "\n", 1);
      if (save_int(fd, sector->ennemi->hp))
        return 1;
      write(fd, "\n", 1);
    }
  else
    {
      write(fd, "\n", 1);
      write(fd, "\n", 1);
    }
  save_int(fd, sector->detection_done);
  write(fd, "\n", 1);
  return 0;
}

int             load_sectors(char **lines, t_sector **sectors, int offset)
{
  int           i;
  t_sector      **first;

  *sectors = create_sectors(10);
  first = malloc(sizeof(t_sector*));
  *first = *sectors;
  i = offset;
  while ((*sectors)->next != NULL)
    {
      load_sector(*sectors, lines[i], lines[i + 1], lines[i + 2]);
      *sectors = (*sectors)->next;
      i += 3;
    }
  *sectors = *first;
  return i;
}

int             load_sector(t_sector *sector,
                            char *dmg, char *hp, char *detect)
{
  if (dmg[0] && hp[0])
    {
      if (sector->ennemi == NULL)
        sector->ennemi = malloc(sizeof(t_ennemi));
      sector->ennemi->damage = my_getnbr(dmg);
      sector->ennemi->hp = my_getnbr(hp);
    }
  else if (sector->ennemi != NULL)
    {
      free(sector->ennemi);
      sector->ennemi = NULL;
    }
  sector->detection_done = my_getnbr(detect);
  return 0;
}

