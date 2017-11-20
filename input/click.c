/*
** click.c for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Wed Nov  8 17:45:59 2017 BOURDALE Jules
** Last update Fri Nov 10 19:20:19 2017 BOURDALE Jules
*/

#include "ftl.h"
#include "ship/ship.h"
#include "input.h"
#include "core/core.h"
#include "save/save.h"

void			menu_click(SDL_Event event, t_ship *ship, t_sector **sectors)
{
  t_gui_component	*menu_repair;

  if (is_in_rect(MENU_RECT_ATTAQUE, event.button.x, event.button.y))
    {
      attack(ship, sectors);
    }
  else if (is_in_rect(MENU_RECT_DETECT, event.button.x, event.button.y))
    {
      detect(ship, sectors);
    }
  else if (is_in_rect(MENU_RECT_REPAIR, event.button.x, event.button.y))
    {
      menu_repair = get_state_by_name(MENU_REPAIR_NAME);
      menu_repair->display = (menu_repair->display + 1) % 2;
    }
  else if (is_in_rect(MENU_RECT_SAVE, event.button.x, event.button.y))
    {
      save(get_actual_state(), ship, sectors);
    }
}

void			click_freight(SDL_Event event,
				      t_ship *ship,
				      t_sector **sectors)
{
  static int		freights[10][4] = FREIGHT_RECTS;
  int			i;
  t_gui_component	*asteroids;

  sectors = sectors;
  i = 0;
  while (i < NB_FREIGHT)
    {
      if (is_in_rect(freights[i][0], freights[i][1],
		     freights[i][2], freights[i][3],
		     event.button.x, event.button.y))
	{
	  get_bonus(ship);
	  asteroids = get_state_by_name(FREIGHT_NAME);
	  asteroids->display = 0;
	}
      i++;
    }
}

void		click_menu_repair(SDL_Event event,
				  t_ship *ship,
				  t_sector **sectors)
{
  int		click;

  sectors = sectors;
  click = 0;
  if (is_in_rect(GPS_REPAIR_BTN, event.button.x, event.button.y))
    {
      click = 1;
      ftl_navigation_tools_system_repair(ship);
      get_state_by_name(GPS_OFF_NAME)->display = 0;
    }
  else if (is_in_rect(DRIVE_REPAIR_BTN, event.button.x, event.button.y))
    {
      click = 1;
      ftl_drive_system_repair(ship);
      get_state_by_name(MOTOR_OFF_NAME)->display = 0;
    }
  else if (is_in_rect(WEAPON_REPAIR_BTN, event.button.x, event.button.y))
    {
      click = 1;
      ftl_weapon_system_repair(ship);
      get_state_by_name(WEAPON_OFF_NAME)->display = 0;
    }
  if (click)
    {
      get_state_by_name(MENU_REPAIR_NAME)->display = 0;
      ship->drive->energy--;
    }
}
