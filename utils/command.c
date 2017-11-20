/*
** command.c for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Mon Nov  6 21:06:01 2017 BOURDALE Jules
** Last update Fri Nov 10 00:49:06 2017 BOURDALE Jules
*/

#include "ftl.h"
#include "ship/ship.h"

static const t_prompt_command   g_prompt_commands[] =
  {
    {GET_BONUS_COMMAND, get_bonus},
    {REPAIR_SYSTEM_COMMAND, system_repair},
    {CONTROL_SYSTEM_COMMAND, system_control},
    {STAT_COMMAND, status},
    {QUIT_COMMAND, quit},
    {HELP_COMMAND, help},
    {HELP_COMMAND2, help},
    {NULL, NULL}
  };

static const t_prompt_sector_command g_prompt_sector_commands[] =
  {
    {ATTACK_COMMAND, attack},
    {JUMP_COMMAND, jump},
    {DETECT_COMMAND, detect},
    {NULL, NULL}
  };

int	run_command(t_ship *ship, char *command)
{
  int	i;

  i = 0;
  while (g_prompt_commands[i].name != NULL)
    {
      if (my_strcmp(g_prompt_commands[i].name, command) == 0)
	{
	  g_prompt_commands[i].command(ship);
	  return 1;
	}
      i++;
    }
  return 0;
}

int	run_sector_command(t_ship *ship, t_sector **sector, char *command)
{
  int	i;

  i = 0;
  while (g_prompt_sector_commands[i].name != NULL)
    {
      if (my_strcmp(g_prompt_sector_commands[i].name, command) == 0)
	{
	  g_prompt_sector_commands[i].command(ship, sector);
	  return 1;
	}
      i++;
    }
  return 0;
}

void	quit(t_ship *ship)
{
  ship = ship;
  my_putstr(QUIT_MESSAGE);
}

void	help(t_ship *ship)
{
  my_putstr(HELP_MESSAGE);
  ship = ship;
}
