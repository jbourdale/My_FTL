/*
** core.h for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Mon Nov  6 18:40:44 2017 BOURDALE Jules
** Last update Fri Nov 10 23:24:45 2017 BOURDALE Jules
*/

#ifndef __CORE_H__
# define __CORE_H__

#include <stdlib.h>
#include "ftl.h"

# define BACKGROUND1_NAME		"background1"
# define BACKGROUND1_FILE		"./assets/background1.png"
# define BACKGROUND1                     {BACKGROUND1_NAME, BACKGROUND1_FILE, \
                                         1, 0, 0, NULL, NULL, NULL}
# define BACKGROUND2_NAME		"background2"
# define BACKGROUND2_FILE		"./assets/background2.png"
# define BACKGROUND2                     {BACKGROUND2_NAME, BACKGROUND2_FILE, \
                                         0, 0, 0, NULL, NULL, NULL}
# define BACKGROUND3_NAME		"background3"
# define BACKGROUND3_FILE		"./assets/background3.png"
# define BACKGROUND3                     {BACKGROUND3_NAME, BACKGROUND3_FILE, \
                                         0, 0, 0, NULL, NULL, NULL}
# define BACKGROUND4_NAME		"background4"
# define BACKGROUND4_FILE		"./assets/background4.png"
# define BACKGROUND4                     {BACKGROUND4_NAME, BACKGROUND4_FILE, \
                                         0, 0, 0, NULL, NULL, NULL}
# define BACKGROUND5_NAME		"background5"
# define BACKGROUND5_FILE		"./assets/background5.png"
# define BACKGROUND5                     {BACKGROUND5_NAME, BACKGROUND5_FILE, \
                                         0, 0, 0, NULL, NULL, NULL}
# define BACKGROUND6_NAME		"background6"
# define BACKGROUND6_FILE		"./assets/background6.png"
# define BACKGROUND6                     {BACKGROUND6_NAME, BACKGROUND6_FILE, \
                                         0, 0, 0, NULL, NULL, NULL}
# define BACKGROUND7_NAME		"background7"
# define BACKGROUND7_FILE		"./assets/background7.png"
# define BACKGROUND7                     {BACKGROUND7_NAME, BACKGROUND7_FILE, \
                                         0, 0, 0, NULL, NULL, NULL}
# define BACKGROUND8_NAME		"background8"
# define BACKGROUND8_FILE		"./assets/background8.png"
# define BACKGROUND8                     {BACKGROUND8_NAME, BACKGROUND8_FILE, \
                                         0, 0, 0, NULL, NULL, NULL}
# define BACKGROUNDS			{BACKGROUND1_NAME, BACKGROUND2_NAME, \
					 BACKGROUND3_NAME, BACKGROUND4_NAME, \
					 BACKGROUND5_NAME, BACKGROUND6_NAME, \
					 BACKGROUND7_NAME, BACKGROUND8_NAME}
# define NB_BACKGROUND			8
# define ATTACK_NAME			"attack"
# define ATTACK_FILE			"./assets/attack.png"
# define FREIGHT_NAME			"freight"
# define FREIGHT_FILE			"./assets/freight.png"
# define RADAR_NAME			"radar"
# define RADAR_FILE			"./assets/radar.png"
# define SHIP_NAME			"ship"
# define SHIP_FILE			"./assets/spaceship.png"
# define ENNEMI_NAME			"ennemi"
# define ENNEMI_FILE			"./assets/ennemi.png"
# define SECTOR_NAME			"sector_text"
# define MENU_NAME			"menu"
# define MENU_FILE			"./assets/menu.png"
# define TOUCH_ENNEMI_ANIMATION_NAME	"touch_animation"
# define TOUCH_ENNEMI_ANIMATION_FILE	"./assets/explosion.png"

# define METRICS_NAME			"metrics"
# define METRIC_HULL_NAME		"metric_hull"
# define METRIC_DAMAGE_NAME		"metric_damage"
# define METRIC_EVADE_NAME		"metric_evade"
# define METRIC_ENERGY_NAME		"metric_energy"
# define METRIC_LOAD_NAME		"metric_load"
# define METRICS_ALL_NAME		{ METRIC_HULL_NAME, METRIC_DAMAGE_NAME, \
					 METRIC_EVADE_NAME, METRIC_ENERGY_NAME, \
					 METRIC_LOAD_NAME}
# define METRICS_POSITION		{{435, 47}, {525, 47}, {605, 47}, \
                                         {690, 47}, {770, 47}}

# define MOTOR_ON_NAME			"motor_on"
# define MOTOR_ON_FILE			"./assets/motor_on.png"
# define MOTOR_OFF_NAME			"motor_off"
# define MOTOR_OFF_FILE			"./assets/motor_off.png"
# define GPS_ON_NAME			"gps_on"
# define GPS_ON_FILE			"./assets/gps_on.png"
# define GPS_OFF_NAME			"gps_off"
# define GPS_OFF_FILE			"./assets/gps_off.png"
# define WEAPON_ON_NAME			"weapon_on"
# define WEAPON_ON_FILE			"./assets/weapon_on.png"
# define WEAPON_OFF_NAME			"weapon_off"
# define WEAPON_OFF_FILE			"./assets/weapon_off.png"
# define MENU_REPAIR_NAME		"menu_repair"
# define MENU_REPAIR_FILE		"./assets/menu_repair.png"
# define INIT_MENU                        {MENU_NAME, MENU_FILE, \
                                         1, 1, 527, NULL, menu_click,   \
                                         NULL};
# define INIT_SHIP                       {SHIP_NAME, SHIP_FILE, 1, \
                                         100, 200, NULL, NULL, NULL}
# define INIT_ENNEMI                     {ENNEMI_NAME, ENNEMI_FILE, 1, \
                                         600, 400, NULL, NULL, NULL}
# define INIT_FREIGHT                    {FREIGHT_NAME, FREIGHT_FILE, 0, \
                                         0, 0, NULL, click_freight, NULL}
# define INIT_TOUCH_ENNEMI_ANIMATION     {TOUCH_ENNEMI_ANIMATION_NAME, \
                                         TOUCH_ENNEMI_ANIMATION_FILE, \
                                         0, 634, 431, NULL, \
                                         NULL, touch_ennemi_animation}
# define INIT_SECTOR                     {SECTOR_NAME, NULL, 1, 5, 5, NULL, \
                                         NULL, render_sector_text}
# define INIT_METRICS                    {METRICS_NAME, NULL, 1, 435, 47, \
                                         NULL, NULL, render_metrics_text}
# define INIT_MOTOR_ON                   {MOTOR_ON_NAME, MOTOR_ON_FILE, 1, \
                                         90, 565, NULL, NULL, NULL}
# define INIT_MOTOR_OFF                  {MOTOR_OFF_NAME, MOTOR_OFF_FILE, 0, \
                                         90, 565, NULL, NULL, NULL}
# define INIT_GPS_ON                     {GPS_ON_NAME, GPS_ON_FILE, 1, 130, \
                                         565, NULL, NULL, NULL}
# define INIT_GPS_OFF                    {GPS_OFF_NAME, GPS_OFF_FILE, 0, 130, \
                                         565, NULL, NULL, NULL}
# define INIT_WEAPON_ON                  {WEAPON_ON_NAME, WEAPON_ON_FILE, 1, \
                                         170, 565, NULL, NULL, NULL}
# define INIT_WEAPON_OFF                 {WEAPON_OFF_NAME, WEAPON_OFF_FILE, \
                                         0, 170, 565, NULL, NULL, NULL}
# define INIT_MENU_REPAIR                {MENU_REPAIR_NAME, MENU_REPAIR_FILE, \
                                         0, 270, 306, NULL, \
                                         click_menu_repair, NULL}
# define INIT_STATE                      { &bg1, &bg2, &bg3, &bg4, &bg5, \
                                           &bg6, &bg7, &bg8, &menu, &ship, \
                                           &ennemi, &asteroid, &sector_text, \
                                           &metrics_text, &motor_on,    \
                                           &motor_off, &gps_on, &gps_off, \
                                           &weapon_on, &weapon_off,     \
                                           &menu_repair, &touch_ennemi, &end}
# define STATE_NAMES                    {BACKGROUND1_NAME, BACKGROUND2_NAME, \
                                         BACKGROUND3_NAME, BACKGROUND4_NAME, \
                                         BACKGROUND5_NAME, BACKGROUND6_NAME, \
                                         BACKGROUND7_NAME, BACKGROUND8_NAME, \
                                         MENU_NAME, SHIP_NAME, ENNEMI_NAME, \
                                         FREIGHT_NAME, SECTOR_NAME, \
                                         METRICS_NAME, MOTOR_ON_NAME, \
                                         MOTOR_OFF_NAME, GPS_ON_NAME, \
                                         GPS_OFF_NAME, WEAPON_ON_NAME,  \
                                         WEAPON_OFF_NAME, MENU_REPAIR_NAME, \
                                         TOUCH_ENNEMI_ANIMATION_NAME}

int				won_game(t_ship *ship);
int				get_options(int set, char *name, ...);
t_gui_component                 **get_actual_state();
int				state_changed(
                                              t_gui_component **state, \
                                              t_gui_component **render_state);
void				free_state(t_gui_component **state);
t_gui_component			**copy_state(t_gui_component **state);
t_gui_component                 *create_empty_component();
void                            display_win(int winner, SDL_Renderer *renderer);
void                            display_end(SDL_Renderer *renderer, char *fileName);
void                            wait_enter();
int                             parse_args(int argc, char **argv);
void                            usage(char **argv);
#endif
