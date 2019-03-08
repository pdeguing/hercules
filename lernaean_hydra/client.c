/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 09:32:53 by pdeguing          #+#    #+#             */
/*   Updated: 2019/03/08 10:08:19 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define PORT			8888
#define MAX_BUF			1024

int		main() {
	int					sockfd;
	struct sockaddr_in	server_address;
	char				buf[MAX_BUF];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&server_address, sizeof(server_address));

	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(PORT);

	inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);

	connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address));

	write(sockfd, "Ping", 5);
	printf("Ping - You just cut a head off the Hydra.\n");
	bzero(buf, MAX_BUF);
	read(sockfd, buf, MAX_BUF);
	printf("%s - And it has two more now, good job.\n", buf);

	return (0);
}
