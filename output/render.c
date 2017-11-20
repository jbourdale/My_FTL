/*
** render.c for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Tue Nov  7 16:57:41 2017 BOURDALE Jules
** Last update Fri Nov 10 22:10:37 2017 BOURDALE Jules
*/
#include "ftl.h"
#include "output.h"
#include "utils/dial.h"
#include "utils/utils.h"
#include "core/core.h"

int				render(SDL_Renderer *renderer, t_ship *ship)
{
  static t_gui_component	**render_state = NULL;
  t_gui_component		**state;
  int				i;
  int                           render_custom;

  state = get_actual_state();
  if (render_state == NULL || state_changed(state, render_state) != 0)
    {
      i = 0;
      while (state[i]->name != NULL)
	{
          render_custom = render_component(renderer, state[i], ship);
	  if (render_custom == 1)
	    i = -1;
          else if (render_custom == -1)
            return 1;
	  i++;
	}
      free_state(render_state);
      if ((render_state = copy_state(state)) == NULL)
        return 1;
      SDL_RenderPresent(renderer);
    }
  return 0;
}

SDL_Rect        create_rect(int x, int y, int w, int h)
{
  SDL_Rect      rect;

  rect.x = x;
  rect.y = y;
  rect.w = w;
  rect.h = h;
  return rect;
}

int     init_SDL(SDL_Window **window, SDL_Renderer **renderer)
{
  *renderer = NULL;
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
    return 1;
  else
    {
      if (!TTF_Init())
        {
          *window = NULL;
          *window = SDL_CreateWindow(GUI_WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    800,
                                    600,
                                    SDL_WINDOW_SHOWN);
          if (*window != NULL)
            *renderer = SDL_CreateRenderer(*window, -1,
                                           SDL_RENDERER_ACCELERATED);
          else
            return 1;
        }
      else
        return 1;
    }
  return 0;
}
