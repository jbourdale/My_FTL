/*
** container.c for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Mon Nov  6 12:16:42 2017 BOURDALE Jules
** Last update Fri Nov 10 00:44:58 2017 BOURDALE Jules
*/
#include "core/core.h"
#include "ship.h"
#include "ftl.h"
#include "utils/dial.h"

int		add_container_to_ship(t_ship *ship)
{
  t_container	*container;

  if (! get_options(0, "gui"))
    my_putstr(CONTAINER_ADD);
  container = malloc(sizeof(t_container));
  if (container != NULL)
    {
      container->first = NULL;
      container->last = NULL;
      container->nb_elem = 0;
      ship->container = container;
      if (! get_options(0, "gui"))
	my_putstr(CONTAINER_ADD_SUCCESS);
      return 1;
    }
  if (! get_options(0, "gui"))
    my_putstr(CONTAINER_ADD_FAILED);
  return 0;
}

void		add_freight_to_container(t_ship *ship, t_freight *current)
{
  if (ship->container->nb_elem == 0)
    {
      ship->container->first = current;
      current->prev = NULL;
      current->next = NULL;
      ship->container->last = current;
    }
  else
    {
      ship->container->last->next = current;
      current->prev = ship->container->last;
      current->next = NULL;
      ship->container->last = current;
    }
  ship->container->nb_elem++;
}

void		del_freight_from_container(t_ship *ship, t_freight *elem)
{
  t_freight	*current;
  t_freight	*prev;

  prev = NULL;
  current = ship->container->first;
  while (current != NULL)
    {
      if (current == elem)
	{
	  if (prev == NULL)
            delete_first_elem(prev, current, ship);
	  else
	    {
	      prev->next = current->next;
	      if (current->next == NULL)
                ship->container->last = prev;
              else
                current->next->prev = prev;
              free(current);
	    }
	  ship->container->nb_elem--;
	}
      prev = current;
      if (current != NULL)
	current = current->next;
    }
}

void    delete_first_elem(t_freight *prev, t_freight *current,
                          t_ship *ship)
{
  prev = current;
  current = current->next;
  ship->container->first = current;
  free(prev->item);
  free(prev);
}

void		get_bonus(t_ship *ship)
{
  t_freight	*current;
  t_freight	*prev;

  current = ship->container->first;
  while (current != NULL)
    {
      if (my_strcmp(current->item, ATTACK_BONUS) == 0)
	ship->weapon->damage += 5;
      else if (my_strcmp(current->item, EVADE_BONUS) == 0)
	ship->navigation_tools->evade += 3;
      else if (my_strcmp(current->item, ENERGY_BONUS) == 0)
	ship->drive->energy += 1;
      current = current->next;
    }
  prev = NULL;
  current = ship->container->first;
  while (current != NULL)
    {
      if (prev != NULL)
	del_freight_from_container(ship, prev);
      prev = current;
      current = current->next;
    }
  del_freight_from_container(ship, prev);
}
