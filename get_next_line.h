/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameltsen <ameltsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:37:57 by ameltsen          #+#    #+#             */
/*   Updated: 2023/08/16 20:27:41 by ameltsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_read_to_rest(int fd, char *rest);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *rest, char *buff);
size_t	ft_strlen(char *s);
char	*ft_get_line(char *rest);
char	*ft_new_rest(char *rest);

#endif
