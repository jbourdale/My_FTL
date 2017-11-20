/*
** my_ftl.c for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Mon Nov  6 10:40:58 2017 BOURDALE Jules
** Last update Fri Nov 10 23:25:31 2017 BOURDALE Jules
*/
#include <stdlib.h>
#include <time.h>
#include "ftl.h"
#include "utils/utils.h"
#include "ship/ship.h"
#include "sector/sector.h"
#include "core/core.h"
#include "output/output.h"
#include "save/save.h"

int		run_prompt(t_ship *ship, t_sector **sector)
{
  char		*command;
  int		valid_command;
  int		quit;

  command = NULL;
  valid_command = 0;
  while (! valid_command)
  {
    my_putstr(PROMPT_GLOBAL);
    free(command);
    command = readLine();
    valid_command = run_command(ship, command);
    if (valid_command == 0)
      valid_command = run_sector_command(ship, sector, command);
    if (! valid_command)
      my_putstr(PROMPT_GLOBAL_BAD_COMMAND);
  }
  quit = 0;
  if (my_strcmp(command, QUIT_COMMAND) == 0)
    quit = 1;
  free(command);
  return quit;
}

int		run_game(t_ship *ship, t_sector *sectors)
{
  int		quit;
  SDL_Renderer	*renderer;
  SDL_Window    *window;
  SDL_Event	event;

  if (get_options(0, "gui"))
    {
      if (init_SDL(&window, &renderer))
          return 1;
    }
  quit = 0;
  while (won_game(ship) == 0 && quit == 0)
    {
      if (get_options(0, "gui"))
        {
          if (SDL_WaitEvent(&event))
            quit = handle_event(event, ship, &sectors);
          if (render(renderer, ship))
            return 1;
        }
      else
	quit = run_prompt(ship, &sectors);
    }
  if (quit == 0)
    display_win(won_game(ship), renderer);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  return 0;
}

int		main(int argc, char **argv)
{
  t_ship	*ship;
  t_sector	*sectors;

  if (parse_args(argc, argv))
    return 1;
  srand(time(NULL));
  ship = create_ship();
  sectors = create_sectors(10);
  if (load(&ship, &sectors) && get_options(0, "gui"))
    enter_sector_gui(&sectors);
  if (run_game(ship, sectors))
    my_putstr("Error when running the game\n");
  else
    {
      free_ship(ship);
      free_sectors(sectors);
      if (get_options(0, "gui"))
        {
          TTF_Quit();
          SDL_Quit();
        }
      return 0;
    }
  return 1;
}
