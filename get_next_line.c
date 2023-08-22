/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameltsen <ameltsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:47:30 by ameltsen          #+#    #+#             */
/*   Updated: 2023/08/21 12:34:10 by ameltsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_to_rest(int fd, char *rest)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(rest, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		rest = ft_strjoin(rest, buff);
	}
	free(buff);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	rest = ft_read_to_rest(fd, rest);
	if (!rest)
		return (NULL);
	line = ft_get_line(rest);
	rest = ft_new_rest(rest);
	return (line);
}

// #include <fcntl.h>

// int main(void)
// {
//     char *line;
//     int fd;
//     int i = 1;

//     fd = open("test_txt/test1.txt", O_RDONLY);

//     while (i < 5)
//     {
//         printf("line [%02d] : %s\n", i, (line = get_next_line(fd)));
//         free(line);
//         i++;
//     }

//     close(fd);

//     return (0);
// }