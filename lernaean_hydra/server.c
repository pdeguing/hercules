/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 08:58:37 by pdeguing          #+#    #+#             */
/*   Updated: 2019/03/08 10:10:10 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define PORT		8888
#define MAX_BUF		1024

int		main() {
	char				str[MAX_BUF];
	int					listen_fd, comm_fd;
	struct sockaddr_in	servaddr;

	listen_fd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htons(INADDR_ANY);
	servaddr.sin_port = htons(PORT);

	bind(listen_fd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	listen(listen_fd, 10);

	while (1) {
		bzero(str, MAX_BUF);
		comm_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);
		read(comm_fd, str, MAX_BUF);
		printf("Received - %s", str);
		if (!strcmp(str, "Ping"))
			write(comm_fd, "Pong Pong", strlen("Pong Pong") + 1);
	}
	return (0);
}
