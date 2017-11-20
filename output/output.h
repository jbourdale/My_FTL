/*
** output.h for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Tue Nov  7 17:00:23 2017 BOURDALE Jules
** Last update Fri Nov 10 11:27:15 2017 BOURDALE Jules
*/

#ifndef __OUTPUT_H__
# define __OUTPUT_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "ftl.h"

# define SPACE_FONT_FILE "./assets/spacefont.ttf"
# define GREEN_COLOR     {2, 135, 5, 255}
int             init_SDL(SDL_Window **window, SDL_Renderer **renderer);
int             render(SDL_Renderer *renderer, t_ship *ship);
int             render_component(SDL_Renderer *renderer,
                                 t_gui_component *comp, t_ship *ship);
int             render_sector_text(SDL_Renderer *renderer,
                                   t_gui_component *comp, t_ship *ship);
int	        touch_ennemi_animation(SDL_Renderer *renderer,
                                       t_gui_component *comp, t_ship *ship);
void            move_ship(int direction, t_ship *ship, t_sector **sectors);
void            enter_sector_gui(t_sector **sectors);
int             render_metrics_text(SDL_Renderer *renderer,
                                    t_gui_component *comp, t_ship *ship);
char            *build_metrics_text(t_ship *ship, char *name);
void		*my_memset(void *dst, int c, size_t n);
void            move_ship(int direction, t_ship *ship, t_sector **sectors);
int             create_sprite(t_gui_component *comp);
SDL_Rect        create_rect(int x, int y, int w, int h);
void            create_window(SDL_Window **);
#endif
