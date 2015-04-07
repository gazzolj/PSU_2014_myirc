##
## Makefile for myftp in /home/gazzol_j/rendu/PSU_2014_myftp
## 
## Made by julien gazzola
## Login   <gazzol_j@epitech.net>
## 
## Started on  Thu Mar 12 09:36:05 2015 julien gazzola
## Last update Tue Apr  7 11:41:02 2015 julien gazzola
##

CC	=	gcc

RM	=	rm -f

NAMES	=	server

NAMEC	=	client

SRCS	=	serv/serveur.c \
		serv/init_serveur.c

SRCC	=	my_client/client.c

CFLAGS	=	-Wall -Wextra -Werror

OBJS	=	$(SRCS:.c=.o)

OBJC	=	$(SRCC:.c=.o)

all:		$(NAMES) $(NAMEC)

$(NAMES):	$(OBJS)
		$(CC) $(OBJS) -o $(NAMES)

$(NAMEC):	$(OBJC)
		$(CC) $(OBJC) -o $(NAMEC)

clean:
		$(RM) $(OBJS)
		$(RM) $(OBJC)

fclean:		clean
		$(RM) $(NAMES)
		$(RM) $(NAMEC)

re:		fclean all

.PHONY:		all clean fclean re
