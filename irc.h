/*
** irc.h for myirc in /home/gazzol_j/rendu/PSU_2014_myirc
** 
** Made by julien gazzola
** Login   <gazzol_j@epitech.net>
** 
** Started on  Tue Apr  7 11:44:35 2015 julien gazzola
** Last update Tue Apr  7 12:03:54 2015 julien gazzola
*/

#ifndef IRC_H_
# define IRC_H_

#include <netdb.h>

/*
**serveur
*/
int	my_close(int fd);
int	my_socket(struct protoent *pe);
int	my_bind(int fd, struct sockaddr_in s_in);
int	my_listen(int fd);
int	my_accept(int fd);


#endif /* !IRC_H_ */
