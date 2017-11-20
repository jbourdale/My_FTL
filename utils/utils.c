/*
** utils.c for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Thu Nov  9 00:41:09 2017 BOURDALE Jules
** Last update Fri Nov 10 00:47:40 2017 BOURDALE Jules
*/
#include "ftl.h"
#include "utils.h"
#include "core/core.h"

const char		*g_reset_color = "\033[0m";
static const t_color	g_color[] =
  {
    {"clear", "\033[H\033[2J"},
    {"red", "\033[31m"},
    {"green", "\033[32m"},
    {"yellow", "\033[33m"},
    {"blue", "\033[34m"},
    {"magenta", "\033[35m"},
    {"cyan", "\033[36m"},
    {NULL, NULL}
  };

t_gui_component		*get_state_by_name(char *name)
{
  int			i;
  t_gui_component	**state;

  state = get_actual_state();
  i = 0;
  while (state[i]->name != NULL && my_strcmp(state[i]->name, name) != 0)
    i++;
  return state[i];
}

void			my_putstr_color(const char *color, const char *str)
{
  int			i;

  i = 0;
  while (g_color[i].color != NULL && (my_strcmp(g_color[i].color, color) != 0))
    i++;
  if (g_color[i].color == NULL)
    {
      my_putstr(str);
      return ;
    }
  my_putstr(g_color[i].unicode);
  my_putstr(str);
  my_putstr(g_reset_color);
}
