##
## Makefile for Make port in /u/all/capot_r/cu/rendu/math/105equation
##
## Made by romain capot
## Login   <capot_r@epitech.net>
##
## Started on  Fri Jan 15 12:47:14 2010 romain capot
## Last update Sun Jun  5 10:27:22 2011 romain capot
##

NAME	= bomberman

MAP	= map

SRCS	= 	main.cpp		\
		Bomberman.cpp		\
		Primitives.cpp		\
		AObject.cpp		\
		APlayer.cpp		\
		Human.cpp		\
		Bomb.cpp		\
		Menu.cpp		\
		Button.cpp		\
		APlay.cpp		\
		Play.cpp		\
		IA.cpp			\
		ModPlayer.cpp		\
		ModBomb.cpp		\
		Camera.cpp		\
		create_cube.cpp		\
		Plate.cpp		\
		AffMap.cpp		\
		AffPlayer.cpp		\
		AffNb.cpp		\
		AffWinner.cpp		\
		CheckBomb.cpp		\
		CheckQuit.cpp		\
		Credit.cpp		\
		HighScores.cpp		\
		MapSize.cpp		\
		LoadGame.cpp		\
		NbIA.cpp		\
		Score.cpp		\
		Start.cpp		\
		PlaySound.cpp		\
		Options.cpp		\
		SaveGame.cpp		\
		$(MAP)/AllWall.cpp	\
		$(MAP)/AObj.cpp		\
		$(MAP)/empty.cpp	\
		$(MAP)/lineWall.cpp	\
		$(MAP)/map.cpp		\
		$(MAP)/Wall.cpp		\

OBJS	= $(SRCS:.cpp=.o)

CC	= g++

RM	= rm -f

GDL	= -I/afs/epitech.net/users/labos/gamelab/public/include -L/afs/epitech.net/users/labos/gamelab/public/lib -Wl,--rpath=/afs/epitech.net/users/labos/gamelab/public/lib -lgdl_gl -lGL -lGLU

CPPFLAGS	= -W -Werror -Wall $(GDL)

$(NAME)	: $(OBJS)
	$(CC) $(GDL) -lsfml-audio -lsfml-system $(OBJS) -o $(NAME)

all	: $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME) *~ \#

re	: fclean all