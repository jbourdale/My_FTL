/*
** save.c for  in /home/dev/C/My_FTL/bourda_j/save
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Fri Nov 10 15:57:35 2017 BOURDALE Jules
** Last update Fri Nov 10 22:01:10 2017 BOURDALE Jules
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "save.h"
#include "ftl.h"

int     save(t_gui_component **state, t_ship *ship, t_sector **sectors)
{
  int   fd;

  ship = ship;
  fd = open(SAVE_FILE,
            O_WRONLY | O_CREAT | O_TRUNC,
            S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  if (fd < 0)
    return 1;
  save_state(fd, state);
  save_sectors(fd, sectors);
  save_ship(fd, ship);
  close(fd);
  return 0;
}

int     load(t_ship **ship, t_sector **sectors)
{
  int   fd;
  char  **lines;
  int   ret;
  char  content[1024];

  ship = ship;
  fd = open(SAVE_FILE, O_RDONLY);
  if (fd < 0)
    return 1;
  if ((ret = read(fd, content, 1023)) < 0)
    return 1;
  content[ret] = '\0';
  lines = explode_save_file(content, get_nb_lines(content), '\n');
  ret = load_state(lines);
  ret = load_sectors(lines, sectors, ret);
  load_ship(lines, ship, get_nb_lines(content), ret);
  ret = 0;
  while ((*sectors)->level < (*ship)->navigation_tools->sector)
    (*sectors) = (*sectors)->next;
  close(fd);
  return 0;
}
