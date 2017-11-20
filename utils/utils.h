/*
** utils.h for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Mon Nov  6 10:33:26 2017 BOURDALE Jules
** Last update Fri Nov 10 14:59:54 2017 BOURDALE Jules
*/
#ifndef __MYFTL_UTILS_H__
#define __MYFTL_UTILS_H__

#include "ftl.h"

typedef			struct s_color	t_color;

struct			s_color
{
  char			*color;
  char			*unicode;
};

void    my_putchar(const char c);
int     my_strlen(const char *str);
void    my_putstr(const char *str);
int     my_strcmp(const char *s1, const char *s2);
char    *my_strdup(const char *str);
void    my_putstr_color(const char *color, const char *str);
int     random_by_percent(int percent);
void    quit(t_ship *ship);
void    help(t_ship *ship);
void    my_put_nbr(int n);
int     run_command(t_ship *ship, char *command);
int     run_sector_command(t_ship *ship, t_sector **sector, char *command);
char    *my_strcat(char *dest, char *src);
char    *my_itoa(int num, char* str, int base);
char    *my_strcpy(char* str, char *dest);
t_gui_component         *get_state_by_name(char *name);
int     my_getnbr(char *str);
#endif
