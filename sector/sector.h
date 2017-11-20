/*
** sector.h for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Mon Nov  6 18:42:00 2017 BOURDALE Jules
** Last update Fri Nov 10 00:32:41 2017 BOURDALE Jules
*/

#ifndef __SECTOR_H__
#define __SECTOR_H__

#include <stdlib.h>
#include "ftl.h"

t_sector	*add_new_sector(t_sector *first);
t_sector	*create_sectors(int nb);
void            free_sectors(t_sector *sectors);
t_ennemi	*create_ennemi(t_sector *first);

#endif
