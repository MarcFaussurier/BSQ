/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   stdio.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/19 15:36:15 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/20 20:23:47 by hmarlin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int s;

	s = 0;
	while (str[s] != '\0')
	{
		ft_putchar(str[s]);
		s++;
	}
}

char	*ft_read_input(char delimiter, int fd)
{
	unsigned int	input_len;
	char			*input_buffer;

	input_len = 0;
	input_buffer = malloc(sizeof(char));
	while (1)
	{
		if (!read(fd, input_buffer + input_len, 1))
			break ;
		if ((int)*(input_buffer + input_len) == (int)delimiter)
			break ;
		input_len += 1;
		input_buffer = realloc(input_buffer, (input_len + 1) * sizeof(char));
	}
	input_buffer = realloc(input_buffer, (input_len + 1) * sizeof(char));
	*(input_buffer + input_len) = '\0';
	return (input_buffer);
}

char	*ft_read_file(char *file_path)
{
	int		fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (0);
	else
	{
		return (ft_read_input(-1, fd));
	}
}
