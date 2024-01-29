/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:30:09 by iubieta-          #+#    #+#             */
/*   Updated: 2024/01/29 19:42:41 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *text)
{
	int		read_bytes;
	char	*buffer;
	
	buffer = malloc(BUFFER_SIZE + 1);
	// printf("\nMALLOC: buffer\n");
	if (!buffer)
		return (0);
	read_bytes = BUFFER_SIZE;
	while (!(ft_strchr(text,'\n')) && read_bytes == BUFFER_SIZE)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[read_bytes] = '\0';
		if (read_bytes > 0)
			text = ft_join(text, buffer);
		else
		{
			free(text);
			free(buffer);
			return (0);
		}
	}
	free (buffer);
	// printf("\nFREE: buffer\n");
	return (text);
}
int	ft_linelen(const char *text)
{
	size_t	count;

	count = 0;
	if (!text)
		return (0);
	while (text[count] != '\0' &&  text[count] != '\n')
		count++;
	if (text[count] == '\n')
		count++;
	return (count);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*del;
	char		*line;
	int			line_len;
	
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		if (text)
		{
			free(text);
			text = NULL;
		}
		return (NULL);
	}
	if (!text)
	{
		text = malloc(sizeof(char));
		if (!text)
			return (0);
		text[0] = '\0';	
	}
	text = ft_read(fd, text);
	if (!text)
		return (0);
	line_len = ft_linelen(text);
	line = ft_substr(text, 0, line_len);
	del = text;
	text = ft_substr(text, line_len, ft_strlen(text) - line_len);
	free(del);
	return (line);
}
