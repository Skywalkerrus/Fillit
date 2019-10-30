/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hslartib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 18:43:34 by hslartib          #+#    #+#             */
/*   Updated: 2019/06/03 18:48:42 by hslartib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	dots_and_sharps(char *str)
{
	int sharp;
	int dot;
	int i;

	sharp = 0;
	dot = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			sharp++;
		if (str[i] == '.')
			dot++;
		i++;
	}
	if (!(sharp == 4 && dot == 12))
		fault();
}

void	additional(char *str, int count)
{
	if ((str[4] != '\n' && str[9] != '\n' && str[14] != '\n' &&
				str[19] != '\n') || count > 25)
		fault();
}

void	validation(char *str, int count)
{
	int i;
	int valid;

	i = 0;
	valid = 0;
	dots_and_sharps(str);
	additional(str, count);
	while (str[i])
	{
		if (str[i] == '#')
		{
			if ((i + 1) <= 20 && str[i + 1] == '#')
				valid++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				valid++;
			if ((i + 5) <= 20 && str[i + 5] == '#')
				valid++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				valid++;
		}
		i++;
	}
	if (!(valid == 6 || valid == 8))
		fault();
}

void	fault(void)
{
	write(1, "error\n", 6);
	exit(0);
}

int		read_file(int fd)
{
	int		count;
	char	buff[22];
	int		ret;

	count = 0;
	while ((ret = read(fd, buff, 21)))
	{
		buff[ret] = '\0';
		validation(buff, count);
		count++;
	}
	if (buff[20] != '\0')
		fault();
	close(fd);
	return (count);
}
