/*
** ship.c for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Tue Nov  7 12:42:01 2017 BOURDALE Jules
** Last update Fri Nov 10 21:50:28 2017 BOURDALE Jules
*/
#include "core/core.h"
#include "input/input.h"
#include "utils/utils.h"
#include "ship/ship.h"

void			move_ship(int direction, t_ship *ship, t_sector **sectors)
{
  t_gui_component	*ship_gui;
  int			max_right;

  max_right = 700;
  ship_gui = get_state_by_name(SHIP_NAME);
  if (direction == DIRECTION_RIGHT)
    {
      if (can_jump(ship, sectors))
	max_right = 900;
      if (ship_gui->x + 8 <= max_right)
	ship_gui->x += 8;
      if (ship_gui->x >= 800)
	jump(ship, sectors);
    }
  else if (direction == DIRECTION_LEFT)
    {
      if (ship_gui->x - 8 > 0)
	ship_gui->x -= 8;
    }
  else if (direction == DIRECTION_UP)
    {
      if (ship_gui->y >= 0)
	ship_gui->y -= 8;
    }
  else if (direction == DIRECTION_DOWN)
    {
      if (ship_gui->y < 466)
	ship_gui->y += 8;
    }
}

void			enter_sector_gui(t_sector **sectors)
{
  static char		bgs[NB_BACKGROUND][50] = BACKGROUNDS;
  t_gui_component	*ship;
  t_gui_component	*ennemi;
  t_gui_component	*asteroids;
  t_gui_component	*bg;
  int                   i;

  ship = get_state_by_name(SHIP_NAME);
  ship->x = -25;
  asteroids = get_state_by_name(FREIGHT_NAME);
  asteroids->display = 0;
  ennemi = get_state_by_name(ENNEMI_NAME);
  ennemi->display = 0;
  if ((*sectors)->ennemi != NULL)
    {
      if ((*sectors)->ennemi->hp > 0)
        ennemi->display = 1;
    }
  i = 0;
  while (i < NB_BACKGROUND)
    {
      bg = get_state_by_name(bgs[i]);
      bg->display = 0;
      i++;
    }
  bg = get_state_by_name(bgs[(*sectors)->level % 8]);
  bg->display = 1;
}
