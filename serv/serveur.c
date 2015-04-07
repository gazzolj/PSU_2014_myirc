/*
** serveur.c for myirc in /home/gazzol_j/rendu/PSU_2014_myirc/serv
** 
** Made by julien gazzola
** Login   <gazzol_j@epitech.net>
** 
** Started on  Tue Apr  7 12:01:36 2015 julien gazzola
** Last update Tue Apr  7 12:01:49 2015 julien gazzola
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../irc.h"

static int		init_serveur(int fd, struct sockaddr_in s_in, struct protoent *pe)
{
  if ((fd = my_socket(pe)) == -1)
    return (-1);
  if (my_bind(fd, s_in) == -1)
    return (-1);
  if (my_listen(fd) == -1)
    return (-1);
  if (my_accept(fd) == -1)
    return (-1);
  return (0);
}

static int		my_serveur(int port)
{
  struct sockaddr_in	s_in;
  struct protoent	*pe;
  int			fd;

  fd = 0;
  if ((pe = getprotobyname("TCP")) == NULL)
    return (-1);
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = INADDR_ANY;
  if (!pe)
    {
      printf("error : protoent\n");
      return (-1);
    }
  if (init_serveur(fd, s_in, pe) == -1)
    return (-1);
  return (0);
}

int	main(int ac, char **av)
{
  if (ac != 2)
    {
      printf("USAGE: ./serveur [port]\n");
      return (-1);
    }
  if (my_serveur(atoi(av[1])) == -1)
    return (-1);
  return (0);
}
