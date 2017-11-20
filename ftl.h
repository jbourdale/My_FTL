/*
** ftl.h for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Mon Nov  6 10:14:44 2017 BOURDALE Jules
** Last update Thu Nov  9 23:23:53 2017 BOURDALE Jules
*/

#ifndef __FTL_H__
#define __FTL_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL_ttf.h>
#include <stdlib.h>

typedef struct s_ship			t_ship;
typedef struct s_freight		t_freight;
typedef struct s_repair_command		t_repair_command;
typedef struct s_container		t_container;
typedef struct s_navigation_tools	t_navigation_tools;
typedef struct s_ftl_drive		t_ftl_drive;
typedef struct s_weapon			t_weapon;
typedef struct s_prompt_command		t_prompt_command;
typedef struct s_sector			t_sector;
typedef struct s_ftl_ennemi		t_ennemi;
typedef struct s_prompt_sector_command	t_prompt_sector_command;
typedef struct s_option			t_option;
typedef struct s_gui_component		t_gui_component;
typedef struct s_position		t_position;

struct		s_gui_component
{
  char		*name;
  char		*fileName;
  int		display;
  int		x;
  int		y;
  SDL_Surface	*sprite;
  void		(*on_click)(SDL_Event event,
                            t_ship *ship, t_sector **sectors);
  int		(*render)(SDL_Renderer *renderer,
                          t_gui_component *comp, t_ship *ship);
};

struct		s_option
{
  char		*name;
  int		value;
};

struct		s_ftl_ennemi
{
  int		damage;
  int		hp;
};

struct		s_sector
{
  int		level;
  t_ennemi	*ennemi;
  int		detection_done;
  t_sector	*next;
  t_sector	*prev;
};

struct		s_prompt_command
{
  char		*name;
  void		(*command)(t_ship *ship);
};

struct		s_prompt_sector_command
{
  char		*name;
  void		(*command)(t_ship *ship, t_sector **sector);
};

struct		s_repair_command
{
  char		*name;
  void		(*command)(t_ship *ship);
};

struct		s_freight
{
  char		*item;
  t_freight	*next;
  t_freight	*prev;
};

struct		s_container
{
  t_freight	*first;
  t_freight	*last;
  int		nb_elem;
};

struct		s_navigation_tools
{
  char		*system_status;
  int		sector;
  int		evade;
};

struct		s_ftl_drive
{
  char		*system_status;
  int		energy;
};

struct		s_weapon
{
  char		*system_status;
  int		damage;
};

struct			s_ship
{
  int			hull;
  t_weapon		*weapon;
  t_ftl_drive		*drive;
  t_navigation_tools	*navigation_tools;
  t_container		*container;
};

#endif
