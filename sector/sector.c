/*
** sector.c for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Mon Nov  6 18:05:59 2017 BOURDALE Jules
** Last update Fri Nov 10 11:23:11 2017 BOURDALE Jules
*/
#include "ftl.h"
#include "sector.h"
#include "utils/utils.h"

t_sector        *add_new_sector(t_sector *first)
{
  t_sector	*new;
  t_sector	*last;

  if ((new = malloc(sizeof(t_sector))) == NULL)
    return NULL;
  new->detection_done = 0;
  new->ennemi = NULL;
  if (first != NULL)
    {
      last = first;
      while (last->next != NULL)
	last = last->next;
      new->level = last->level + 1;
      new->ennemi = create_ennemi(first);
      last->next = new;
      new->prev = last;
      new->next = NULL;
    }
  else
    {
      new->level = 0;
      new->ennemi = create_ennemi(NULL);
      new->prev = NULL;
      new->next = NULL;
    }
  return new;
}

t_ennemi	*create_ennemi(t_sector *first)
{
  t_sector	*last;
  t_ennemi	*new_ennemi;

  new_ennemi = NULL;
  last = first;
  if (first != NULL)
    {
      while (last->next != NULL)
	last = last->next;
      while (last->prev != NULL && last->ennemi == NULL)
	last = last->prev;
    }
  if (random_by_percent(30))
    {
      new_ennemi = malloc(sizeof(t_ennemi));
      if (last == NULL || last->ennemi == NULL)
	{
	  new_ennemi->damage = 10;
	  new_ennemi->hp = 20;
	}
      else
	{
	  new_ennemi->damage = (int)(last->ennemi->damage * 1.5);
	  new_ennemi->hp = (int)(last->ennemi->hp * 1.5);
	}
    }
  else
    new_ennemi = NULL;
  return new_ennemi;
}

t_sector	*create_sectors(int nb)
{
  int		i;
  t_sector	*sectors;

  sectors = add_new_sector(NULL);
  i = 0;
  while (i < nb)
    {
      add_new_sector(sectors);
      i++;
    }
  return sectors;
}

void		free_sectors(t_sector *sectors)
{
  t_sector	*prev;

  prev = NULL;
  while (sectors != NULL)
    {
      if (prev != NULL)
	{
	  free(prev->ennemi);
	  free(prev);
	}
      prev = sectors;
      sectors = sectors->next;
    }
  free(prev->ennemi);
  free(prev);
}
