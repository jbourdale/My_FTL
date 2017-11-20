/*
** detect.c for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Tue Nov  7 01:04:20 2017 BOURDALE Jules
** Last update Fri Nov 10 23:11:30 2017 BOURDALE Jules
*/
#include "ftl.h"
#include "ship.h"
#include "core/core.h"
#include "utils/utils.h"

void		detect(t_ship *ship, t_sector **sector_ptr)
{
  int		i;
  t_freight	*freight;
  t_sector	*sector;

  sector = (*sector_ptr);
  if (sector->detection_done == 0)
    {
      sector->detection_done = 1;
      i = 0;
      while (i < 10)
	{
	  if ((freight = gen_freight()) == NULL)
            return ;
	  add_freight_to_container(ship, freight);
	  i++;
	}
      display_detect(sector);
    }
  else if (get_options(0, "gui") == 0)
    my_putstr(DETECT_BONUS_NOT_AVAILIBLE);
}

t_freight	*gen_freight()
{
  t_freight	*freight;
  int		item;

  if ((freight = malloc(sizeof(t_freight))) == NULL)
    return NULL;
  freight->next = NULL;
  freight->prev = NULL;
  if (random_by_percent(70))
    freight->item = my_strdup(SCRAP_BONUS);
  else
    {
      item = rand() % 100;
      if (item <= 33)
	freight->item = my_strdup(ATTACK_BONUS);
      else if (item <= 66)
	freight->item = my_strdup(EVADE_BONUS);
      else if (item <= 99)
	freight->item = my_strdup(ENERGY_BONUS);
      else
	freight->item = my_strdup(SCRAP_BONUS);
    }
  return freight;
}

void			display_detect(t_sector *sector)
{
  t_gui_component	*freight;

  if (get_options(0, "gui") == 0)
    {
      my_putstr(DETECT_BONUS_SUCCESS);
      if (sector->ennemi != NULL)
	my_putstr("Il y a un ennemi dans cette zone\n");
      else
	my_putstr("Il n'y a pas d'ennemi dans cette zone\n");
    }
  else
    {
      freight = get_state_by_name(FREIGHT_NAME);
      freight->display = 1;
    }

}
