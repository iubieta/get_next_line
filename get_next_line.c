/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:30:09 by iubieta-          #+#    #+#             */
/*   Updated: 2024/02/10 14:50:18 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *text)
{
	int		read_bytes;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	read_bytes = BUFFER_SIZE;
	while (!(ft_strchr(text, '\n')) && read_bytes == BUFFER_SIZE)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[read_bytes] = '\0';
		if (read_bytes >= 0)
			text = ft_join(text, buffer);
		else
			return (free (buffer), buffer = NULL, NULL);
	}
	free (buffer);
	buffer = NULL;
	return (text);
}

int	ft_linelen(const char *text)
{
	size_t	count;

	count = 0;
	if (!text)
		return (0);
	while (text[count] != '\0' && text[count] != '\n')
		count++;
	if (text[count] == '\n')
		count++;
	return (count);
}

char	*ft_errorscheck(int fd, char *text)
{
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		if (text)
		{
			free(text);
			text = NULL;
		}
		return (0);
	}
	if (!text)
	{
		text = malloc(sizeof(char));
		if (!text)
			return (0);
		text[0] = '\0';
	}
	return (text);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*del;
	char		*line;
	int			line_len;

	text = ft_errorscheck(fd, text);
	if (text == 0)
		return (NULL);
	text = ft_read(fd, text);
	if (text[0] == '\0')
		return (free(text), text = NULL, NULL);
	line_len = ft_linelen(text);
	line = ft_substr(text, 0, line_len);
	del = text;
	text = ft_substr(text, line_len, ft_strlen(text) - line_len);
	free(del);
	del = NULL;
	return (line);
}
