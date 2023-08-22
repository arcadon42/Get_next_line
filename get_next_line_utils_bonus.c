/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameltsen <ameltsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:04:07 by ameltsen          #+#    #+#             */
/*   Updated: 2023/08/20 22:32:02 by ameltsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *rest, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!rest)
	{
		rest = (char *) malloc(1 * sizeof (char));
		rest[0] = '\0';
	}
	if (!rest || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(rest) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (rest)
		while (rest[++i] != '\0')
			str[i] = rest[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(rest) + ft_strlen(buff)] = '\0';
	free(rest);
	return (str);
}

char	*ft_get_line(char *rest)
{
	int		i;
	char	*str;

	i = 0;
	if (!rest[i])
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		str[i] = rest[i];
		i++;
	}
	if (rest[i] == '\n')
	{
		str[i] = rest[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_rest(char *rest)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (!rest[i])
	{
		free(rest);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(rest) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (rest[i])
		str[j++] = rest[i++];
	str[j] = '\0';
	free(rest);
	return (str);
}
