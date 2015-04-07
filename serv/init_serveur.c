/*
** init_serveur.c for my_irc in /home/gazzol_j/rendu/PSU_2014_myirc/serv
** 
** Made by julien gazzola
** Login   <gazzol_j@epitech.net>
** 
** Started on  Tue Apr  7 12:01:16 2015 julien gazzola
** Last update Tue Apr  7 12:04:51 2015 julien gazzola
*/

#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include "../irc.h"

int	my_close(int fd)
{
  if (close(fd) == -1)
    {
      printf("Error on : close\n");
      return (-1);
    }
  return (0);
}

int	my_socket(struct protoent *pe)
{
  int	fd;

  fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (fd == -1)
    {
      printf("Error on : socket\n");
      return (-1);
    }
  return (fd);
}

int	my_bind(int fd, struct sockaddr_in s_in)
{
  if (bind(fd, (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      if (my_close(fd) == -1)
	return (-1);
      printf("Error on : bind\n");
      return (-1);
    }
  return (0);
}

int	my_listen(int fd)
{
  if (listen(fd, 10) == -1)
    {
      if (my_close(fd) == -1)
	return (-1);
      printf("error on : listen\n");
      return (-1);
    }
  return (0);
}

int			my_accept(int fd)
{
  int			fd_client;
  struct sockaddr_in	s_in_client;
  socklen_t		s_in_size;

  s_in_size = sizeof(s_in_client);
  fd_client = accept(fd, (struct sockaddr *)&s_in_client, &s_in_size);
  if (fd_client == -1)
    {
      if (my_close(fd) == -1)
	return (-1);
      return (-1);
    }
  if (my_close(fd) == -1 || my_close(fd_client) == -1)
    return (-1);
  return (0);
}
