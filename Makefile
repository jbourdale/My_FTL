##
## Makefile for  in /home/dev/C/myLib/bourda_j
## 
## Made by BOURDALE Jules
## Login   <bourda_j@etna-alternance.net>
## 
## Started on  Fri Oct 20 18:14:57 2017 BOURDALE Jules
## Last update Fri Nov 10 23:26:05 2017 BOURDALE Jules
##
CC		= gcc
INCFLAGS	= -I .		
CFLAGS		= -Wall -Werror -W
LDFLAGS		= `sdl2-config --cflags --libs` -lSDL2_image -lSDL2_ttf
NAME		= my_ftl
SRC		= input/readline.c	\
		input/handle_event.c	\
		input/click.c		\
		ship/air_shed.c		\
		ship/container.c	\
		ship/system_control.c	\
		ship/system_repair.c	\
		ship/attack.c		\
		ship/jump.c		\
		ship/detect.c		\
		ship/status.c		\
		sector/sector.c		\
		core/win.c		\
		core/state.c		\
		core/init.c		\
		core/parse_args.c	\
		output/render.c		\
		output/components.c	\
		output/annimation.c	\
		output/ship.c		\
		utils/my_string.c	\
		utils/random.c		\
		utils/my_put_nbr.c	\
		utils/command.c		\
		utils/my_strcat.c	\
		utils/my_itoa.c		\
		utils/my_strcpy.c	\
		utils/utils.c		\
		utils/my_get_nbr.c	\
		save/save.c		\
		save/state.c		\
		save/sector.c		\
		save/ship.c		\
		my_ftl.c

all:	fclean $(NAME)

$(NAME):
	$(CC) -g3 $(CFLAGS) $(INCFLAGS) $(SRC) -o $(NAME) $(LDFLAGS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
