/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   personone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 15:14:21 by svan-nie          #+#    #+#             */
/*   Updated: 2019/07/03 14:41:33 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <sys/uio.h>
#include <fcntl.h>
#define BUFF_SIZE 32;

int	ft_strlen(char *str)
{
	int count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
void	ft_putstr_fd(int fd, char *str)
{
		write(fd, str, ft_strlen(str));
}

void	ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
}

int	main(int argc, char **argv)
{
	int fd;
	int readfile;
	char	buff[BUFF_SIZE + 1];

	if (argc == 1)
	{
		fd = open("person2", O_RDONLY);
		while ((readfile = read(buff, BUFF_SIZE)))
		{
			buff[readfile] = '\0';
			ft_putstr(buff);
		}
	}
	else if (argc == 3)
	{
		fd = open("person1", O_RDWR | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);
		if (fd == -1)
		{
			ft_putstr_fd(1, "open() ERROR");
			return (1);
		}
		if (argv[1])
		{
			if (*argv[1] == '\0')
			{
				ft_putstr("No Name ERROR");
				return (0);
			}
			ft_putstr_fd(fd, argv[1]);
			ft_putstr_fd(fd, ": ");
		}
		if (argv[1] && argv[2])
		{
			if (*argv[2] == '\0')
			{
				ft_putstr("No Message ERROR");
				return (0);
			}
			ft_putstr_fd(fd, argv[2]);
		}
	}
	else
	{
		ft_putstr("ERROR");
		return (1);
	}
	ft_putchar(fd, '\n');
	return (0);
}
