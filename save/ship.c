/*
** ship.c for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Fri Nov 10 19:02:11 2017 BOURDALE Jules
** Last update Fri Nov 10 22:00:50 2017 BOURDALE Jules
*/

#include <unistd.h>
#include "ftl.h"
#include "save.h"
#include "utils/utils.h"
#include "ship/ship.h"

int     save_ship(int fd, t_ship *ship)
{
  if (save_int(fd, ship->hull))
    return 1;
  write(fd, "\n", 1);
  if (save_int(fd, ship->weapon->damage))
    return 1;
  write(fd, "\n", 1);
  write(fd, ship->weapon->system_status,
        my_strlen(ship->weapon->system_status));
  write(fd, "\n", 1);
  if (save_int(fd, ship->drive->energy))
    return 1;
  write(fd, "\n", 1);
  write(fd, ship->drive->system_status,
        my_strlen(ship->drive->system_status));
  write(fd, "\n", 1);
  if (save_int(fd, ship->navigation_tools->sector))
    return 1;
  write(fd, "\n", 1);
  if (save_int(fd, ship->navigation_tools->evade))
    return 1;
  write(fd, "\n", 1);
  write(fd, ship->navigation_tools->system_status,
        my_strlen(ship->navigation_tools->system_status));
  write(fd, "\n", 1);
  if (save_freight(fd, ship))
    return 1;
  return 0;
}

int             save_freight(int fd, t_ship *ship)
{
  t_freight     **first;

  if ((first = malloc(sizeof(t_freight *))) == NULL)
    return 1;
  *first = ship->container->first;
  while (*first != NULL)
    {
      write(fd, (*first)->item, my_strlen((*first)->item));
      write(fd, "\n", 1);
      (*first) = (*first)->next;
    }
  free(first);
  return 0;
}

int     load_ship(char **lines, t_ship **ship, int nb_lines, int offset)
{
  int   i;

  i = offset;
  *ship = create_ship();
  (*ship)->hull = my_getnbr(lines[i++]);
  (*ship)->weapon->damage = my_getnbr(lines[i++]);
  (*ship)->weapon->system_status = my_strdup(lines[i++]);
  (*ship)->drive->energy = my_getnbr(lines[i++]);
  (*ship)->drive->system_status = my_strdup(lines[i++]);
  (*ship)->navigation_tools->sector = my_getnbr(lines[i++]);
  (*ship)->navigation_tools->evade = my_getnbr(lines[i++]);
  (*ship)->navigation_tools->system_status = my_strdup(lines[i++]);
  load_freight(lines, ship, nb_lines);
  return 1;
}

int             load_freight(char **lines, t_ship **ship, int nb_lines)
{
  int           i;
  t_freight     *freight;

  i = 73;
  while (i < nb_lines)
    {
      freight = gen_freight();
      free(freight->item);
      freight->item = my_strdup(lines[i]);
      add_freight_to_container(*ship, freight);
      i++;
    }
  return 0;
}
