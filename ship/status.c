/*
** status.c for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Tue Nov  7 01:17:30 2017 BOURDALE Jules
** Last update Fri Nov 10 00:30:52 2017 BOURDALE Jules
*/
#include "ftl.h"
#include "utils/dial.h"
#include "utils/utils.h"

void	status(t_ship *ship)
{
  my_putstr(DISPLAY_SHIP);
  my_putstr(STATUS_HULL);
  my_put_nbr(ship->hull);
  my_putstr(STATUS_WEAPON);
  my_put_nbr(ship->weapon->damage);
  my_putstr(" (");
  my_putstr(ship->weapon->system_status);
  my_putstr(")");
  my_putstr(STATUS_DRIVE);
  my_put_nbr(ship->drive->energy);
  my_putstr(" (");
  my_putstr(ship->drive->system_status);
  my_putstr(")");
  my_putstr(STATUS_NAVIGATION_TOOLS);
  my_put_nbr(ship->navigation_tools->evade);
  my_putstr(" (");
  my_putstr(ship->navigation_tools->system_status);
  my_putstr(")");
  my_putstr(STATUS_CONTAINER);
  my_put_nbr(ship->container->nb_elem);
  my_putstr(STATUS_SECTOR);
  my_put_nbr(ship->navigation_tools->sector);
  my_putstr("\n");
}
