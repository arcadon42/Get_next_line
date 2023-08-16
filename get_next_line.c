/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameltsen <ameltsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:47:30 by ameltsen          #+#    #+#             */
/*   Updated: 2023/08/16 20:28:03 by ameltsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Reads from an open fd and appends the content to the rest(restder from the
// previous read). 
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

// Takes int fd representing the descriptor of the file from which the lines
// will be read. Returns a pointer to a character array(string) containing the
// next line read from the file, or NULL if the end of the file is reached or an
// error occurs.
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
//     int fd1;
//     int fd2;
//     int fd3;
//     int i = 1;

//     fd1 = open("test_txt/test1.txt", O_RDONLY);
//     fd2 = open("test_txt/test2.txt", O_RDONLY);
//     fd3 = open("test_txt/test3.txt", O_RDONLY);

//     while (i < 10)
//     {
// 		printf("\n");
				
//         line = get_next_line(fd1);
//         printf("line [%02d] (fd1): %s", i, line);
//         free(line);

//         line = get_next_line(fd2);
//         printf("line [%02d] (fd2): %s", i, line);
//         free(line);

//         line = get_next_line(fd3);
//         printf("line [%02d] (fd3): %s\n\n", i, line);
//         free(line);

//         i++;
//     }

//     close(fd1);
//     close(fd2);
//     close(fd3);

//     return (0);
// }
