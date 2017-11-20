/*
** attack.c for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Mon Nov  6 17:40:03 2017 BOURDALE Jules
** Last update Sat Nov 11 09:21:31 2017 BOURDALE Jules
*/
#include "ftl.h"
#include "ship.h"
#include "core/core.h"

void		attack(t_ship *ship, t_sector **sector_ptr)
{
  t_sector	*sector;

  sector = (*sector_ptr);
  if (sector->ennemi != NULL && sector->ennemi->hp > 0)
    {
      if (my_strcmp(ship->weapon->system_status, ONLINE_STATUS) == 0)
	{
	  touch_ennemi(ship, sector);
	  if (random_by_percent(ship->navigation_tools->evade))
            {
	      if (get_options(0, "gui") == 0)
		my_putstr(ATTACK_ENNEMI_EVADE);
	    }
	  else
	    ship_touched(ship, sector);
	  if (random_by_percent(50))
	    {
	      ship->drive->energy--;
	      if (get_options(0, "gui") == 0)
		my_putstr(ATTACK_PLAYER_LOSE_ENERGY);
	    }
	}
      else
	my_putstr(ATTACK_SYSTEM_NOT_AVAILIBLE);
    }
  else
    my_putstr(ATTACK_NOT_AVAILIBLE);
}

void	ship_touched(t_ship *ship, t_sector *sector)
{
  int	touched_system;

  ship->hull -= sector->ennemi->damage;
  if (get_options(0, "gui") == 0)
    {
      my_putstr(ATTACK_ENNEMI_TOUCHED);
      my_put_nbr(sector->ennemi->damage);
    }
  if (random_by_percent(20))
    {
      touched_system = rand() % 3;
      if (touched_system == 0)
	{
	  free(ship->weapon->system_status);
	  ship->weapon->system_status = my_strdup(OFFLINE_STATUS);
	  get_state_by_name(WEAPON_OFF_NAME)->display = 1;
	}
      else if (touched_system == 1)
	{
	  free(ship->navigation_tools->system_status);
	  ship->navigation_tools->system_status = my_strdup(OFFLINE_STATUS);
	  get_state_by_name(GPS_OFF_NAME)->display = 1;
	}
      else
	{
	  free(ship->drive->system_status);
	  ship->drive->system_status = my_strdup(OFFLINE_STATUS);
	  get_state_by_name(MOTOR_OFF_NAME)->display = 1;
	}
    }
}

void			touch_ennemi(t_ship *ship, t_sector *sector)
{
  sector->ennemi->hp -= ship->weapon->damage;
  if (get_options(0, "gui") == 0)
    {
      my_putstr(ATTACK_PLAYER_LAUNCH);
      my_putstr(ATTACK_PLAYER_TOUCHED);
      my_put_nbr(ship->weapon->damage);
      my_putstr(ATTACK_PLAYER_TOUCHED_END);
      my_putstr(ATTACK_ENNEMI_LAUNCH);
    }
  else
      get_state_by_name(TOUCH_ENNEMI_ANIMATION_NAME)->display = 1;
  if (sector->ennemi->hp <= 0)
    {
      if (get_options(0, "gui"))
	  get_state_by_name(ENNEMI_NAME)->display = 0;
      else
	my_putstr(ATTACK_ENNEMI_KILLED);
    }
}
