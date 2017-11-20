/*
** ship.h for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Mon Nov  6 11:12:30 2017 BOURDALE Jules
** Last update Fri Nov 10 22:12:24 2017 BOURDALE Jules
*/

#ifndef __SHIP_H__
#define __SHIP_H__

#include <stdlib.h>
#include "ftl.h"
#include "utils/dial.h"
#include "utils/utils.h"
#include "input/input.h"

#define ATTACK_BONUS				"attackbonus"
#define EVADE_BONUS				"evadebonus"
#define ENERGY_BONUS				"energy"
#define SCRAP_BONUS				"scrap"

#define ATTACK_COMMAND				"attack"
#define GET_BONUS_COMMAND			"getbonus"
#define REPAIR_SYSTEM_COMMAND			"repair_system"
#define CONTROL_SYSTEM_COMMAND			"control_system"
#define STAT_COMMAND				"stat"
#define QUIT_COMMAND				"quit"
#define HELP_COMMAND				"help"
#define HELP_COMMAND2				"?"

#define DRIVE_REPAIR_COMMAND			"ftl_drive"
#define NAVIGATION_TOOLS_REPAIR_COMMAND		"navigation_tools"
#define WEAPON_REPAIR_COMMAND			"weapon"
#define JUMP_COMMAND				"jump"
#define DETECT_COMMAND				"detect"

t_ship		*create_ship();
int             add_weapon_to_ship(t_ship *ship);
int             add_ftl_drive_to_ship(t_ship *ship);
int             add_navigation_tools_to_ship(t_ship *ship);
int             add_container_to_ship(t_ship *ship);
void            ftl_drive_system_repair(t_ship *ship);
void            ftl_navigation_tools_system_repair(t_ship *ship);
void            ftl_weapon_system_repair(t_ship *ship);
void            system_repair(t_ship *ship);
void            system_control(t_ship *ship);
void		ship_touched(t_ship *ship, t_sector *sector);
void		attack(t_ship *ship, t_sector **sector);
void            get_bonus(t_ship *ship);
void		jump(t_ship *ship, t_sector **sector);
void            detect(t_ship *ship, t_sector **sector);
void		status(t_ship *ship);
void		del_freight_from_container(t_ship *ship, t_freight *freight);
void		add_freight_to_container(t_ship *ship, t_freight *freight);
void		free_ship(t_ship *ship);
void            touch_ennemi(t_ship *ship, t_sector *sector);
t_freight       *gen_freight();
void		display_detect(t_sector *sector);
int		can_jump(t_ship *ship, t_sector **sector);
void            delete_first_elem(t_freight *prev, t_freight *current,
                          t_ship *ship);
#endif
