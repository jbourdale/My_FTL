/*
** air_shed.c for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Mon Nov  6 10:16:32 2017 BOURDALE Jules
** Last update Fri Nov 10 11:21:44 2017 BOURDALE Jules
*/
#include "ship.h"
#include "utils/utils.h"
#include "utils/dial.h"
#include "core/core.h"

t_ship		*create_ship()
{
  t_ship	*ship;

  if (! get_options(0, "gui"))
      my_putstr(SHIP_CONSTRUCTION);
  if ((ship = malloc(sizeof(t_ship))) == NULL)
    {
      if (! get_options(0, "gui"))
        my_putstr(SHIP_CONSTRUCTION_FAILED);
      return NULL;
    }
  ship->hull = 50;
  if (! get_options(0, "gui"))
    my_putstr(SHIP_CONSTRUCTION_OVER);
  ship->weapon = NULL;
  add_weapon_to_ship(ship);
  ship->drive = NULL;
  add_ftl_drive_to_ship(ship);
  ship->navigation_tools = NULL;
  add_navigation_tools_to_ship(ship);
  ship->container = NULL;
  add_container_to_ship(ship);
  return ship;
}

int		add_weapon_to_ship(t_ship *ship)
{
  t_weapon	*weapon;

  if (! get_options(0, "gui"))
    my_putstr(WEAPON_ADD);
  weapon = malloc(sizeof(t_weapon));
  if (weapon != NULL)
    {
      weapon->damage = 10;
      weapon->system_status = my_strdup(ONLINE_STATUS);
      ship->weapon = weapon;
      if (! get_options(0, "gui"))
	my_putstr(WEAPON_ADD_SUCCESS);
      return 1;
    }
  if (! get_options(0, "gui"))
    my_putstr(WEAPON_ADD_FAILED);
  return 0;
}

int		add_ftl_drive_to_ship(t_ship *ship)
{
  t_ftl_drive	*drive;

  if (! get_options(0, "gui"))
    my_putstr(FTL_DRIVE_ADD);
  drive = malloc(sizeof(t_ftl_drive));
  if (drive != NULL)
    {
      drive->energy = 10;
      drive->system_status = my_strdup(ONLINE_STATUS);
      ship->drive = drive;
      if (! get_options(0, "gui"))
	my_putstr(FTL_DRIVE_ADD_SUCCESS);
      return 1;
    }
  if (! get_options(0, "gui"))
    my_putstr(FTL_DRIVE_ADD_FAILED);
  return 0;
}

int			add_navigation_tools_to_ship(t_ship *ship)
{
  t_navigation_tools	*navigation_tools;

  navigation_tools = malloc(sizeof(t_navigation_tools));
  if (! get_options(0, "gui"))
    my_putstr(NAVIGATION_TOOLS_ADD);
  if (navigation_tools != NULL)
    {
      navigation_tools->sector = 0;
      navigation_tools->evade = 25;
      navigation_tools->system_status = my_strdup(ONLINE_STATUS);
      ship->navigation_tools = navigation_tools;
      if (! get_options(0, "gui"))
	my_putstr(NAVIGATION_TOOLS_ADD_SUCCESS);
      return 1;
    }
  if (! get_options(0, "gui"))
    my_putstr(NAVIGATION_TOOLS_ADD_FAILED);
  return 0;
}

void			free_ship(t_ship *ship)
{
  t_freight		*current;
  t_freight		*prev;

  prev = NULL;
  current = ship->container->first;
  while (current != NULL)
    {
      if (prev != NULL)
	del_freight_from_container(ship, prev);
      prev = current;
      current = current->next;
    }
  del_freight_from_container(ship, prev);
  free(ship->container);
  free(ship->weapon->system_status);
  free(ship->weapon);
  free(ship->drive->system_status);
  free(ship->drive);
  free(ship->navigation_tools->system_status);
  free(ship->navigation_tools);
  free(ship);
}
