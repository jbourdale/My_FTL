/*
** components.c for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Wed Nov  8 09:41:29 2017 BOURDALE Jules
** Last update Fri Nov 10 21:50:38 2017 BOURDALE Jules
*/
#include "ftl.h"
#include "output.h"
#include "utils/dial.h"
#include "utils/utils.h"
#include "core/core.h"

int		render_component(SDL_Renderer *renderer,
                                 t_gui_component *comp, t_ship *ship)
{
  SDL_Rect	dest;
  SDL_Texture	*texture;
  int		render_after_custom;

  if (comp->display)
    {
      render_after_custom = 1;
      if (comp->render != NULL)
	{
	  render_after_custom = comp->render(renderer, comp, ship);
	  if (render_after_custom == 1)
	    return 1;
	}
      else
	{
	  if (create_sprite(comp) == 0)
            return 0;
	  texture = SDL_CreateTextureFromSurface(renderer, comp->sprite);
	  if (texture != NULL && comp->display == 1)
	    {
	      dest = create_rect(comp->x, comp->y,
                                  comp->sprite->w, comp->sprite->h);
	      SDL_RenderCopy(renderer, texture, NULL, &dest);
	      SDL_DestroyTexture(texture);
	    }
	}
    }
  return 0;
}

int			render_sector_text(SDL_Renderer *renderer,
                                           t_gui_component *comp, t_ship *ship)
{
  static SDL_Color	black = {2, 135, 5, 255};
  TTF_Font		*font;
  SDL_Surface		*text;
  SDL_Texture		*texture;
  SDL_Rect	        dest;
  char			*sector;
  char			*num;

  if ((num = malloc(2 * sizeof(char))) == NULL)
    return 1;
  my_itoa(ship->navigation_tools->sector, num, 10);
  sector = malloc(my_strlen(SECTOR_GUI_TEXT) + my_strlen(num) + 1);
  if (sector == NULL)
    return 1;
  sector = my_strcpy(sector, my_strdup(SECTOR_GUI_TEXT));
  sector = my_strcat(sector, num);
  sector[my_strlen(my_strdup(SECTOR_GUI_TEXT)) + my_strlen(num)] = '\0';
  font = TTF_OpenFont(SPACE_FONT_FILE, 25);
  text = TTF_RenderText_Blended(font, sector, black);
  texture = SDL_CreateTextureFromSurface(renderer, text);
  if (texture != NULL)
    {
      dest = create_rect(comp->x, comp->y, text->w, text->h);
      SDL_RenderCopy(renderer, texture, NULL, &dest);
      SDL_DestroyTexture(texture);
    }
  free(num);
  free(sector);
  SDL_FreeSurface(text);
  TTF_CloseFont(font);
  return 0;
}

int                     render_metrics_text(SDL_Renderer *renderer,
                                            t_gui_component *comp,
                                            t_ship *ship)
{
  static SDL_Color      black = {2, 135, 5, 255};
  static int		pos[5][2] = METRICS_POSITION;
  static char		*names[] = METRICS_ALL_NAME;
  TTF_Font              *font = NULL;
  SDL_Surface           *text;
  SDL_Texture           *texture;
  SDL_Rect              dest;
  int			i;
  char                  *value;

  comp = comp;
  i = 0;
  font = TTF_OpenFont(SPACE_FONT_FILE, 25);
  while (i < 5)
    {
      value = build_metrics_text(ship, names[i]);
      text = TTF_RenderText_Blended(font, value, black);
      texture = SDL_CreateTextureFromSurface(renderer, text);
      if (texture != NULL)
	{
          dest = create_rect(pos[i][0], pos[i][1],
                             text->w, text->h);
	  SDL_RenderCopy(renderer, texture, NULL, &dest);
	  SDL_DestroyTexture(texture);
	}
      i++;
    }
  free(value);
  TTF_CloseFont(font);
  SDL_FreeSurface(text);
  return 0;
}

char		*build_metrics_text(t_ship *ship, char *name)
{
  char		*value;

  if ((value = malloc(3 * sizeof(char))) == NULL)
    return NULL;
  if (my_strcmp(name, METRIC_HULL_NAME) == 0)
    my_itoa(ship->hull, value, 10);
  else if (my_strcmp(name, METRIC_DAMAGE_NAME) == 0)
    my_itoa(ship->weapon->damage, value, 10);
  else if (my_strcmp(name, METRIC_EVADE_NAME) == 0)
    my_itoa(ship->navigation_tools->evade, value, 10);
  else if (my_strcmp(name, METRIC_ENERGY_NAME) == 0)
    my_itoa(ship->drive->energy, value, 10);
  else if (my_strcmp(name, METRIC_LOAD_NAME) == 0)
    my_itoa(ship->container->nb_elem, value, 10);
  return value;
}

int             create_sprite(t_gui_component *comp)
{
  SDL_RWops     *rwop;

  if (comp->sprite == NULL)
    {
      rwop = SDL_RWFromFile(comp->fileName, "rb");
      comp->sprite = IMG_LoadPNG_RW(rwop);
      if (comp->sprite == NULL)
        {
          my_putstr("[ERROR ANNIMATION] Can't create sprite\n");
          return 0;
        }
      free(rwop);
    }
  return 1;
}
