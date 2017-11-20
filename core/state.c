/*
** options.c for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Tue Nov  7 13:01:16 2017 BOURDALE Jules
** Last update Sat Nov 11 09:33:36 2017 BOURDALE Jules
*/

#include <stdarg.h>
#include "ftl.h"
#include "core.h"
#include "output/output.h"
#include "input/input.h"
#include "utils/utils.h"

int			get_options(int set, char *name, ...)
{
  va_list		args;
  int			value;
  int			i;
  static t_option	options[] = {
    {"gui", 1},
    {NULL, -1}
  };

  value = -1;
  if (set == 1)
    {
      va_start(args, name);
      value = va_arg(args, int);
      va_end(args);
    }
  i = 0;
  while (options[i].name != NULL && my_strcmp(options[i].name, name) != 0)
    i++;
  if (options[i].name != NULL && value != -1)
      options[i].value = value;
  return options[i].value;
}

t_gui_component			**get_actual_state()
{
  static t_gui_component	bg1 = BACKGROUND1;
  static t_gui_component	bg2 = BACKGROUND2;
  static t_gui_component	bg3 = BACKGROUND3;
  static t_gui_component	bg4 = BACKGROUND4;
  static t_gui_component	bg5 = BACKGROUND5;
  static t_gui_component	bg6 = BACKGROUND6;
  static t_gui_component	bg7 = BACKGROUND7;
  static t_gui_component	bg8 = BACKGROUND8;
  static t_gui_component	menu = INIT_MENU;
  static t_gui_component	ship = INIT_SHIP;
  static t_gui_component	ennemi = INIT_ENNEMI;
  static t_gui_component	asteroid = INIT_FREIGHT;
  static t_gui_component	touch_ennemi = INIT_TOUCH_ENNEMI_ANIMATION;
  static t_gui_component	sector_text = INIT_SECTOR;
  static t_gui_component	metrics_text = INIT_METRICS;
  static t_gui_component	motor_on = INIT_MOTOR_ON;
  static t_gui_component	motor_off = INIT_MOTOR_OFF;
  static t_gui_component	gps_on = INIT_GPS_ON;
  static t_gui_component	gps_off = INIT_GPS_OFF;
  static t_gui_component	weapon_on = INIT_WEAPON_ON;
  static t_gui_component	weapon_off = INIT_WEAPON_OFF;
  static t_gui_component	menu_repair = INIT_MENU_REPAIR;
  static t_gui_component	end = {NULL, NULL, 0, 0, 0, NULL, NULL, NULL};
  static t_gui_component	*state[] = INIT_STATE;

  return state;
}

int		state_changed(t_gui_component **state,
                              t_gui_component **render_state)
{
  int		i;

  i = 0;
  while (*render_state != NULL && state[i]->name != NULL)
    {
      if (state[i]->display != render_state[i]->display)
          return 1;
      if (state[i]->x != render_state[i]->x ||
          state[i]->y != render_state[i]->y)
        {
          return 1;
        }
      i++;
    }
  return 0;
}

void		free_state(t_gui_component **state)
{
  int		i;

  i = 0;
  if (state != NULL)
    {
      while (state != NULL && state[i]->name != NULL)
	{
	  free(state[i]);
	  i++;
	}
      free(state[i]);
    }
  free(state);
}

t_gui_component		**copy_state(t_gui_component **state)
{
  int			i;
  t_gui_component	**state_cpy;

  if ((state_cpy = malloc(sizeof(t_gui_component*) * 23)) == NULL)
    return NULL;
  i = 0;
  while (state[i]->name != NULL)
    {
      state_cpy[i] = malloc(sizeof(t_gui_component));
      if (state_cpy[i] == NULL)
        return NULL;
      state_cpy[i]->name = state[i]->name;
      state_cpy[i]->fileName = state[i]->fileName;
      state_cpy[i]->display = state[i]->display;
      state_cpy[i]->x = state[i]->x;
      state_cpy[i]->y = state[i]->y;
      state_cpy[i]->sprite = state[i]->sprite;
      state_cpy[i]->on_click = state[i]->on_click;
      state_cpy[i]->render = state[i]->render;
      i++;
    }
  if ((state_cpy[i] = create_empty_component()) == NULL)
    return NULL;
  return state_cpy;
}
