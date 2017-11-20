/*
** input.h for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Mon Nov  6 11:18:39 2017 BOURDALE Jules
** Last update Fri Nov 10 00:40:14 2017 BOURDALE Jules
*/

#ifndef __INPUT_H__
# define __INPUT_H__

#include <unistd.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "ftl.h"

# define MENU_RECT_ATTAQUE	(287 + 1), (27 + 527), 40, 40
# define MENU_RECT_DETECT	(354 + 1), (27 + 527), 40, 40
# define MENU_RECT_REPAIR	(416 + 1), (27 + 527), 40, 40
# define MENU_RECT_SAVE		(474 + 1), (27 + 527), 40, 40
# define FREIGHT_RECT_1		{ 186, 91, 50, 50 }
# define FREIGHT_RECT_2		{ 329, 124, 50, 50 }
# define FREIGHT_RECT_3		{ 459, 52, 50, 50 }
# define FREIGHT_RECT_4		{ 626, 149, 50, 50 }
# define FREIGHT_RECT_5		{ 262, 226, 50, 50 }
# define FREIGHT_RECT_6	        { 394, 194, 50, 50 }
# define FREIGHT_RECT_7		{ 157, 326, 50, 50 }
# define FREIGHT_RECT_8		{ 249, 397, 50, 50 }
# define FREIGHT_RECT_9		{ 375, 352, 50, 50 }
# define FREIGHT_RECT_10		{ 537, 297, 50, 50 }
# define NB_FREIGHT		10
# define FREIGHT_RECTS		{ FREIGHT_RECT_1, FREIGHT_RECT_2, \
                                  FREIGHT_RECT_3, FREIGHT_RECT_4, \
                                  FREIGHT_RECT_5, FREIGHT_RECT_6, \
				  FREIGHT_RECT_7, FREIGHT_RECT_8, \
                                  FREIGHT_RECT_9, FREIGHT_RECT_10 }
# define DIRECTION_RIGHT		1
# define DIRECTION_LEFT		2
# define DIRECTION_UP		3
# define DIRECTION_DOWN		4

# define GPS_REPAIR_BTN		317, 356, 32, 32
# define WEAPON_REPAIR_BTN	317, 415, 32, 32
# define DRIVE_REPAIR_BTN	317, 474, 32, 32

char	*readLine();
void    handle_click(SDL_Event event, t_ship *ship, t_sector **sectors);
int     handle_event(SDL_Event event, t_ship *ship, t_sector **sectors);
void    menu_click(SDL_Event event, t_ship *ship, t_sector **sectors);
void    click_freight(SDL_Event event, t_ship *ship, t_sector **sectors);
void    click_menu_repair(SDL_Event ent, t_ship *ship, t_sector **sectors);
int     is_in_rect(int x, int y, int w, int h, int x2, int y2);
void    handle_keyboard(SDL_Event event, t_ship *ship, t_sector **sectors);
#endif
