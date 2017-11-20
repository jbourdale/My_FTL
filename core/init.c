/*
** init.c for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Tue Nov  7 13:43:25 2017 BOURDALE Jules
** Last update Fri Nov 10 10:55:42 2017 BOURDALE Jules
*/
#include "ftl.h"

t_gui_component         *create_empty_component()
{
  t_gui_component       *comp;

  comp = malloc(sizeof(t_gui_component));
  if (comp == NULL)
    return NULL;
  comp->name = NULL;
  comp->fileName = NULL;
  comp->display = 0;
  comp->x = 0;
  comp->y = 0;
  comp->sprite = NULL;
  comp->on_click = NULL;
  comp->render = NULL;
  return comp;
}
