/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameltsen <ameltsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:06:49 by ameltsen          #+#    #+#             */
/*   Updated: 2023/08/18 17:22:08 by ameltsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>

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
	static char	*rest[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	rest[fd] = ft_read_to_rest(fd, rest[fd]);
	if (!rest[fd])
		return (NULL);
	line = ft_get_line(rest[fd]);
	rest[fd] = ft_new_rest(rest[fd]);
	return (line);
}

#include <fcntl.h>

int main(void)
{
    char *line;
    int fd1;
    int fd2;
    int fd3;
    int i = 1;

    fd1 = open("test_txt/test1.txt", O_RDONLY);
    fd2 = open("test_txt/test2.txt", O_RDONLY);
    fd3 = open("test_txt/test3.txt", O_RDONLY);

    while (i < 10)
    {
        line = get_next_line(fd1);
        printf("line [%02d] (fd1): %s", i, line);
        free(line);

        line = get_next_line(fd2);
        printf("line [%02d] (fd2): %s", i, line);
        free(line);

        line = get_next_line(fd3);
        printf("line [%02d] (fd3): %s", i, line);
        free(line);

        i++;
		
    }

    close(fd1);
    close(fd2);
    close(fd3);

    return (0);
}