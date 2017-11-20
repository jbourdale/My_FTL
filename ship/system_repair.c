/*
** system_repair.c for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Mon Nov  6 14:47:29 2017 BOURDALE Jules
** Last update Fri Nov 10 23:09:04 2017 BOURDALE Jules
*/
#include "ship/ship.h"
#include "core/core.h"

static const t_repair_command	repair_commands[] =
  {
    {DRIVE_REPAIR_COMMAND, ftl_drive_system_repair},
    {NAVIGATION_TOOLS_REPAIR_COMMAND, ftl_navigation_tools_system_repair},
    {WEAPON_REPAIR_COMMAND, ftl_weapon_system_repair},
    {NULL, NULL}
  };

void		ftl_drive_system_repair(t_ship *ship)
{
  if (get_options(0, "gui") == 0)
    my_putstr(DRIVE_REPAIR_BEGIN);
  free(ship->drive->system_status);
  if (ship->drive->system_status == NULL)
    {
      if (get_options(0, "gui") == 0)
        my_putstr(DRIVE_REPAIR_FAILED);
      return ;
    }
  ship->drive->system_status = my_strdup(ONLINE_STATUS);
  if (get_options(0, "gui") == 0)
    my_putstr(DRIVE_REPAIR_SUCCESS);
}

void		ftl_navigation_tools_system_repair(t_ship *ship)
{
  if (get_options(0, "gui") == 0)
    my_putstr(NAVIGATION_TOOLS_REPAIR_BEGIN);
  free(ship->navigation_tools->system_status);
  ship->navigation_tools->system_status = malloc(6 * sizeof(char));
  if (ship->navigation_tools->system_status == NULL)
    {
      if (get_options(0, "gui") == 0)
        my_putstr(NAVIGATION_TOOLS_REPAIR_FAILED);
      return ;
    }
  ship->navigation_tools->system_status = my_strdup(ONLINE_STATUS);
  if (get_options(0, "gui") == 0)
    my_putstr(NAVIGATION_TOOLS_REPAIR_SUCCESS);
}

void		 ftl_weapon_system_repair(t_ship *ship)
{
  if (get_options(0, "gui") == 0)
    my_putstr(WEAPON_REPAIR_BEGIN);
  free(ship->weapon->system_status);
  ship->weapon->system_status = malloc(6 * sizeof(char));
  if (ship->weapon->system_status == NULL)
    {
      if (get_options(0, "gui") == 0)
        my_putstr(WEAPON_REPAIR_FAILED);
      return ;
    }
  ship->weapon->system_status = my_strdup(ONLINE_STATUS);
  if (get_options(0, "gui") == 0)
    my_putstr(WEAPON_REPAIR_SUCCESS);
}

void			system_repair(t_ship *ship)
{
  char			*command;
  int			i;
  int			valid_command;

  my_putstr(PROMPT_REPAIR_SYSTEM);
  command = readLine();
  i = 0;
  valid_command = 0;
  while (repair_commands[i].name != NULL)
    {
      if (my_strcmp(repair_commands[i].name, command) == 0)
	{
	  valid_command = 1;
	  repair_commands[i].command(ship);
	}
      i++;
    }
  if (! valid_command && get_options(0, "gui") == 0)
    my_putstr(PROMPT_REPAIR_SYSTEM_BAD_CALL);
  else
    ship->drive->energy--;
  free(command);
}
