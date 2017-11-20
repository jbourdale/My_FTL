/*
** save.c for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Fri Nov 10 13:19:27 2017 BOURDALE Jules
** Last update Fri Nov 10 22:05:28 2017 BOURDALE Jules
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "ftl.h"
#include "save.h"
#include "utils/utils.h"
#include "core/core.h"

int     save_state(int fd, t_gui_component **state)
{
  int   i;
  i = 0;
  while (state[i]->name != NULL)
    {
      save_comp(fd, state[i]);
      i++;
    }
  return i;
}

int     save_comp(int fd, t_gui_component *comp)
{
  if (save_int(fd, comp->display))
    return 1;
  write(fd, ",", 1);
  if (save_int(fd, comp->x))
    return 1;
  write(fd, ",", 1);
  if (save_int(fd, comp->y))
    return 1;
  write(fd, "\n", 1);
  return 0;
}

int             load_state(char **lines)
{
  static char   *state_elem[22] = STATE_NAMES;
  int           i;

  i = 0;
  while (i < 22)
    {
      load_state_elem(lines[i], state_elem[i]);
      i++;
    }
  return i;
}

int             load_state_elem(char *line, char *name)
{
  char          **nums;

  nums = explode_save_file(line, 3, ',');
  get_state_by_name(name)->display = my_getnbr(nums[0]);
  get_state_by_name(name)->x = my_getnbr(nums[1]);
  get_state_by_name(name)->y = my_getnbr(nums[2]);
  return 1;
}

int     get_nb_lines(char *content)
{
  int   i;
  int   nb_lines;

  nb_lines = 0;
  i = 0;
  while (content[i] != '\0')
    {
      if (content[i] == '\n')
        nb_lines++;
      i++;
    }
  return nb_lines;
}
