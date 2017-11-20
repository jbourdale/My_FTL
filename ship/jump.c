/*
** jump.c for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Tue Nov  7 00:47:29 2017 BOURDALE Jules
** Last update Fri Nov 10 23:06:12 2017 BOURDALE Jules
*/
#include "ftl.h"
#include "ship.h"
#include "core/core.h"
#include "output/output.h"

void	jump(t_ship *ship, t_sector **sector)
{
  if (((*sector)->ennemi == NULL || (*sector)->ennemi->hp <= 0) &&
      my_strcmp(ship->drive->system_status, ONLINE_STATUS) == 0)
    {
      ship->navigation_tools->sector++;
      ship->drive->energy--;
      (*sector) = (*sector)->next;
      if (get_options(0, "gui"))
	enter_sector_gui(sector);
      else
	my_putstr(JUMP_COMMAND_SUCCESS);
    }
  else
    my_putstr(JUMP_COMMAND_NOT_AVAILIBLE);
}

int	can_jump(t_ship *ship, t_sector **sector)
{
  if (((*sector)->ennemi == NULL || (*sector)->ennemi->hp <= 0) &&
      my_strcmp(ship->drive->system_status, ONLINE_STATUS) == 0)
    return 1;
  return 0;
}
