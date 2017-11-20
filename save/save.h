/*
** save.h for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Fri Nov 10 13:28:41 2017 BOURDALE Jules
** Last update Fri Nov 10 22:02:07 2017 BOURDALE Jules
*/

#ifndef __SAVE_H__
# define __SAVE_H__

#include "ftl.h"

# define SAVE_FILE "ftl.save"

int     save(t_gui_component **state, t_ship *ship, t_sector **sectors);
int     save_state(int fd, t_gui_component **state);
int     save_comp(int fd, t_gui_component *comp);
int     save_sectors(int fd, t_sector **sectors);
int     save_int(int fd, int val);
int     save_sector(int fd, t_sector *sector);
int     save_freight(int fd, t_ship *ship);
int     save_ship(int td, t_ship *ship);
int     load(t_ship **ship, t_sector **sectors);
int     load_state();
int     load_state_elem(char *line, char *name);
int     load_sectors(char **lines, t_sector **sectors, int offset);
int     load_sector(t_sector *sector, char *dmg, char *hp, char *detect);
int     load_ship(char **lines, t_ship **ship, int nb_lines, int offset);
int     load_freight(char **lines, t_ship **ship, int nb_lines);
char    **explode_save_file(char *content, int nb_lines, char separator);
int     get_nb_lines(char *content);
#endif
