/*
** handle_event.c for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Tue Nov  7 16:55:36 2017 BOURDALE Jules
** Last update Thu Nov  9 20:29:00 2017 BOURDALE Jules
*/
#include "output/output.h"
#include "input.h"
#include "core/core.h"

int	handle_event(SDL_Event event, t_ship *ship, t_sector **sectors)
{
  if (event.type == SDL_WINDOWEVENT)
    {
      if (event.window.event == SDL_WINDOWEVENT_CLOSE)
	  return 1;
    }
  else if (event.type == SDL_MOUSEBUTTONUP)
    handle_click(event, ship, sectors);
  else if (event.type == SDL_KEYDOWN)
    handle_keyboard(event, ship, sectors);
  return 0;
}

void			handle_click(SDL_Event event, t_ship *ship, t_sector **sectors)
{
  t_gui_component	**state;
  int			i;

  state = get_actual_state();
  i = 0;
  while (state[i]->name != NULL)
    {
      if (state[i]->sprite != NULL)
	{
	  if (is_in_rect(
			 state[i]->x, state[i]->y,
			 state[i]->sprite->w, state[i]->sprite->h,
			 event.button.x, event.button.y
			 )
	      && state[i]->on_click != NULL && state[i]->display == 1
	      )
	    {
	      state[i]->on_click(event, ship, sectors);
	    }
	}
      i++;
    }
  SDL_FlushEvent(SDL_MOUSEBUTTONUP);
}

void			handle_keyboard(SDL_Event event,
                                        t_ship *ship,
                                        t_sector **sectors)
{
  if (event.key.keysym.sym == SDLK_RIGHT)
    move_ship(DIRECTION_RIGHT, ship, sectors);
  else if (event.key.keysym.sym == SDLK_LEFT)
    move_ship(DIRECTION_LEFT, ship, sectors);
  else if (event.key.keysym.sym == SDLK_UP)
    move_ship(DIRECTION_UP, ship, sectors);
  else if (event.key.keysym.sym == SDLK_DOWN)
    move_ship(DIRECTION_DOWN, ship, sectors);
  SDL_FlushEvent(SDL_KEYDOWN);
}

int		is_in_rect(int x, int y, int w,
                           int h, int x2, int y2)
{
  return (x2 >= x && x2 <= (x + w) && y2 >= y && y2 <= (y + h));
}
