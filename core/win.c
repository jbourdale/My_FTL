/*
** win.c for  in /home/dev/C/My_FTL/bourda_j
** 
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
** 
** Started on  Mon Nov  6 18:40:18 2017 BOURDALE Jules
** Last update Fri Nov 10 23:14:00 2017 BOURDALE Jules
*/

#include "core.h"
#include "utils/utils.h"
#include "output/output.h"

int	won_game(t_ship *ship)
{
  if (ship->navigation_tools->sector >= 10)
    return 1;
  if (ship->drive->energy <= 0 || ship->hull <= 0)
    return -1;
  return 0;
}

void            display_win(int winner, SDL_Renderer *renderer)
{
  if (winner == -1)
    {
      if (get_options(0, "gui"))
        display_end(renderer, "./assets/loose.png");
      my_putstr("Oh non Nebuchadnezzar! VOUS AVEZ PERDU\n");
    }
  else if (winner == 1) 
    {
      if (get_options(0, "gui"))
        display_end(renderer, "./assets/win.png");
      else
        my_putstr("BRAVO Nebuchadnezzar! VOUS AVEZ GAGNE!\n");
    }
  if (get_options(0, "gui"))
    wait_enter();
}

void            display_end(SDL_Renderer *renderer, char *fileName)
{
  SDL_RWops     *rwop;
  SDL_Surface   *sprite;
  SDL_Texture   *texture;
  SDL_Rect      dest;

  SDL_Delay(500);
  rwop = SDL_RWFromFile(fileName, "rb");
  if ((sprite = IMG_LoadPNG_RW(rwop)) == NULL )
    return ;
  texture = SDL_CreateTextureFromSurface(renderer, sprite);
  if (texture != NULL)
    {
      dest = create_rect(0, 0, 800, 600);
      SDL_RenderCopy(renderer, texture, NULL, &dest);
      SDL_RenderPresent(renderer);
      SDL_DestroyTexture(texture);
    }
  free(rwop);
}


void            wait_enter()
{
  int           quit;
  SDL_Event     event;

  quit = 0;
  while (quit == 0)
    {
      if (SDL_WaitEvent(&event))
        {
          if (event.type == SDL_KEYDOWN &&
              event.key.keysym.sym == SDLK_RETURN)
            quit = 1;
        }
    }
}
