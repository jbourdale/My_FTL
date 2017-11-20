/*
** annimation.c for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Wed Nov  8 19:22:12 2017 BOURDALE Jules
** Last update Fri Nov 10 00:49:55 2017 BOURDALE Jules
*/

#include <time.h>
#include "ftl.h"
#include "core/core.h"
#include "ship/ship.h"
#include "utils/utils.h"
#include "output.h"

int			touch_ennemi_animation(SDL_Renderer *renderer,
					       t_gui_component *comp, t_ship *ship
					       )
{
  time_t		begin;
  time_t		end;
  SDL_Texture		*texture;
  SDL_Rect		dest;

  ship = ship;
  begin = time(NULL);
  comp = get_state_by_name(TOUCH_ENNEMI_ANIMATION_NAME);
  if (create_sprite(comp) == 0)
    return 0;
  texture = SDL_CreateTextureFromSurface(renderer, comp->sprite);
  if (texture != NULL && comp->display == 1)
    {
      dest = create_rect(comp->x, comp->y,
                         comp->sprite->w, comp->sprite->h);
      SDL_RenderCopy(renderer, texture, NULL, &dest);
      SDL_DestroyTexture(texture);
      SDL_RenderPresent(renderer);
    }
  else
      my_putstr(SDL_GetError());
  end = time(NULL);
  while (difftime(end, begin) < 0.003)
    end = time(NULL);
  comp->display = 0;
  return 1;
}
