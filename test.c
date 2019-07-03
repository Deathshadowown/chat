/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:17:09 by svan-nie          #+#    #+#             */
/*   Updated: 2019/07/02 15:33:56 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <string.h>

#define BUFF_SIZE 32

int	main(void)
{
	int fd;
	int	readline;
	char	buff[BUFF_SIZE + 1];

	fd = open("name", O_RDWR);

	//while ((readline = write(fd, buff, BUFF_SIZE)))
	//{
	//	buff[readline] = '\0';
		write(fd,"shane", 5);
	//}
	close(fd);

	fd = open("name", 'r');
	while ((readline = read(fd, buff, BUFF_SIZE)))
	{
		buff[readline] = '\0';
		//puts(buff);
	}
	puts(buff);
	close(fd);
}
