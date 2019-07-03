/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 07:49:46 by svan-nie          #+#    #+#             */
/*   Updated: 2019/07/03 13:06:11 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFF_SIZE 32

int	ft_strlen(char *str)
{
	int count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}
void	ft_putstr(int fd,char *str)
{
	//while (*str)
		write(fd, str, ft_strlen(str));
}
void	ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
}
int	main(void)
{
	int	fd;
	int readline;
	char	buff[BUFF_SIZE + 1];
	//static char *str = "this is static";

	fd = open("name.txt", O_RDWR | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		puts("open() ERROR");
		return (1);
	}
	ft_putstr(fd, "Jax: ");
	if (close(fd) == -1)
	{
		puts("close() ERROR");
		return (1);
	}
	fd = open("name.txt", O_RDONLY);
	if (fd == -1)
	{
		puts("open() ERROR 2");
		return (1);
	}
	while ((readline = read(fd, buff, BUFF_SIZE)))
	{
		buff[readline] = '\0';
		ft_putstr(1, buff);
	}
	if (close(fd) == -1)
		puts("close() ERROR 2");
		return (1);
	return (0);
}
