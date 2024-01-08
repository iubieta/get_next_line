/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:30:09 by iubieta-          #+#    #+#             */
/*   Updated: 2024/01/08 19:52:31 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

BUFFER_SIZE = 256;

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*read_str;
	char		*line;
	static int	start;
	int			line_len;
	static int	read_ret;
	
	//printf("---------------------------------------\n");
	//printf("START:%i\n", start);
	
	//PRIMERA LECTURA:
	if (!read_str)
	{
		read_str = malloc(BUFFER_SIZE * sizeof(char));
		if (!read_str)
			return(0);
		buf = malloc(8);
		if (!buf)
			return(0);
		read_ret = read(fd, buf, 8);
		if (read_ret < 0)
			//printf("ERROR\n");
			return(0);
		else
		{
			read_str = ft_strjoin(read_str, buf);
			//printf("LEIDO:\n.\n%s\n.\n", buf);
			//printf("TEXTO:\n.\n%s\n.\n", read_str);
			free(buf);
		}
		start = 0;			
	}
	
	//LECTURA:
	while (!(ft_strchr(&read_str[start],'\n') != 0) && read_ret == 8)
	{
		//printf("bucle...\n");
		buf = malloc(8);
		if (!buf)
			return(0);
		read_ret = read(fd, buf, 8);
		if (read_ret < 0)
			//printf("ERROR\n");
			return (0);
		else
		{
			read_str = ft_strjoin(read_str, buf);
			//printf("LEIDO:\n.\n%s\n.\n", buf);
			//printf("TEXTO:\n.\n%s\n.\n", read_str);
			free(buf);
		}
	}

	//SACAR LINEA:
	//printf("LINEA:\n");
	line_len = ft_linelen(&read_str[start]);
	if (line_len < 1)
		return(0);
	//printf("%i\n",line_len);
	line = ft_substr(read_str, start, line_len);
	//printf("%s",line);
	start = start + line_len;
	//printf("START:%i\n",start);
	return(line);
}
