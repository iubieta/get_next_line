/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:30:09 by iubieta-          #+#    #+#             */
/*   Updated: 2024/01/10 20:11:19 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int BUFFER_SIZE = 1;

char	*ft_read(int fd, char *text)
{
	char	*buf;
	int		read_ret;

	buf = malloc(BUFFER_SIZE);
	if (!buf)
		return (0);
	read_ret = read(fd, buf, BUFFER_SIZE);
	if (read_ret < 0)
		return(0);
	else
		text = ft_strjoin(text, buf);
	return (text);
}

char	*get_next_line(int fd)
{
	// char		*buf;
	static char	*read_str;
	char		*line;
	static int	start;
	int			line_len;
	int			read_ret;

	//PRIMERA LECTURA:
	if (!read_str)
	{
		read_str = ft_read(fd, read_str);
		start = 0;
		read_ret = ft_strlen(&read_str[start]);
	}
	
	//SEGUIR AQUI: Mover bucle dentro de ft_read
	//LECTURA:
	while ((ft_strrchr(&read_str[start],'\n')) && read_ret == BUFFER_SIZE)
	{
		read_str = ft_read(fd, read_str);
		read_ret = ft_strlen(&read_str[read_ret]);
	}

	//SACAR LINEA:
	line_len = ft_linelen(&read_str[start]);
	if (line_len < 1)
		return(0);
	line = ft_substr(read_str, start, line_len);
	start = start + line_len;
	return(line);
}
