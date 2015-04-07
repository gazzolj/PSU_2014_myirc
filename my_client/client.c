/*
** client.c for myirc in /home/gazzol_j/rendu/PSU_2014_myirc/my_client
** 
** Made by julien gazzola
** Login   <gazzol_j@epitech.net>
** 
** Started on  Tue Apr  7 12:00:52 2015 julien gazzola
** Last update Tue Apr  7 12:05:11 2015 julien gazzola
*/

#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../irc.h"

static int		my_connect(int fd, struct sockaddr_in s_in)
{
  if (connect(fd, (struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      if (close(fd) == -1)
	{
	  printf("Error on : close\n");
	  return (-1);
	}
      printf("Error on : connect\n");
      return (-1);
    }
  return (0);
}

static int		my_socket_client(struct protoent *pe)
{
  int			fd;

  fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (fd == -1)
    {
      printf("Error on : socket\n");
      return (-1);
    }
  return (fd);
}

static int     		my_client(char *ip, int port)
{
  struct sockaddr_in	s_in;
  struct protoent	*pe;
  int			fd;

  if ((pe = getprotobyname("TCP")) == NULL)
    return (-1);
  if ((fd = my_socket_client(pe)) == -1)
    return (-1);
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = inet_addr(ip);
  if (my_connect(fd, s_in) == -1)
    return (-1);
  if (close(fd) == -1)
    {
      printf("Error on : close\n");
      return (-1);
    }
   return (0);
}

int	main(int ac, char **av)
{
  if (ac != 3)
    {
      printf("USAGE: ./client [machine] [port]\n");
      return (-1);
    }
  if (my_client(av[1], atoi(av[2])) == -1)
    return (-1);
  return (0);
}
