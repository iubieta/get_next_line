/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:30:09 by iubieta-          #+#    #+#             */
/*   Updated: 2024/01/05 17:27:49 by iubieta-         ###   ########.fr       */
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
	
	// printf("---------------------------------------\n");
	// printf("START:%i\n", start);
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
			printf("ERROR\n");
		else
		{
			read_str = ft_strdup(buf); //strjoin??
			// printf("LEIDO:\n.\n%s\n.\n", buf);
			// printf("TEXTO:\n.\n%s\n.\n", read_str);
			free(buf);
		}
		start = 0;			
	}
	while (!(ft_strchr(&read_str[start],'\n') != 0) && read_ret == 8)
	{
		// printf("bucle...\n");
		buf = malloc(8);
		if (!buf)
			return(0);
		read_ret = read(fd, buf, 8);
		if (read_ret < 0)
			printf("ERROR\n");	
		else
		{
			read_str = ft_strjoin(read_str, buf);
			// printf("LEIDO:\n.\n%s\n.\n", buf);
			// printf("TEXTO:\n.\n%s\n.\n", read_str);
			free(buf);
		}
	}
	if (read_ret == 8)
	{
		// printf("LINEA:\n");
		line_len = ft_linelen(&read_str[start]) + 1;
		// printf("%i\n",line_len);
		line = ft_substr(read_str, start, line_len);
		start = start + line_len;
		// printf("START:%i\n",start);
	}
	else if (read_ret < 8 && read_ret > 0)
	{
		// printf("FIN:\n");
		line = ft_strdup(&read_str[start]); //substr??
		start = start + read_ret + 1;
		read_ret = 0;
	}
	else 
		return(0);
	printf("---------------------------------------\n");
	return(line);
}
