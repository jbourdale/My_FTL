/*
** system_control.c for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Mon Nov  6 14:30:18 2017 BOURDALE Jules
** Last update Thu Nov  9 23:25:20 2017 BOURDALE Jules
*/

#include "ftl.h"
#include "ship.h"
#include "utils/dial.h"

void		ftl_drive_system_check(t_ship *ship)
{
  my_putstr(DRIVE_SYSTEM_CHECK_BEGIN);
  if (my_strcmp(ship->drive->system_status, ONLINE_STATUS) != 0)
    {
        my_putstr(DRIVE_SYSTEM_CHECK_FAILED);
    }
    my_putstr(DRIVE_SYSTEM_CHECK_SUCCESS);
}

void		navigation_tools_system_check(t_ship *ship)
{
  my_putstr(NAVIGATION_TOOLS_SYSTEM_CHECK_BEGIN);
  if (my_strcmp(ship->navigation_tools->system_status, ONLINE_STATUS) != 0)
    {
      my_putstr(NAVIGATION_TOOLS_SYSTEM_CHECK_FAILED);
    }
  my_putstr(NAVIGATION_TOOLS_SYSTEM_CHECK_SUCCESS);
}

void		weapon_system_check(t_ship *ship)
{
  my_putstr(WEAPON_SYSTEM_CHECK_BEGIN);
  if (my_strcmp(ship->weapon->system_status, ONLINE_STATUS) != 0)
    {
      my_putstr(WEAPON_SYSTEM_CHECK_FAILED);
    }
  my_putstr(WEAPON_SYSTEM_CHECK_SUCCESS);
}

void		system_control(t_ship *ship)
{
  ftl_drive_system_check(ship);
  navigation_tools_system_check(ship);
  weapon_system_check(ship);
}
