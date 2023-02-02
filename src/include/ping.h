#ifndef PING_H
# define PING_H

#include <stdio.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>

/* utils.c */
void	*ft_memset(void *dest, int a, size_t len);

#endif