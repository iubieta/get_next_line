/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:30:09 by iubieta-          #+#    #+#             */
/*   Updated: 2024/01/04 20:13:41 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

BUFFER_SIZE = 256;

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*read_str = NULL;
	char		*start;
	char		*end;
	size_t		read_ret;
	
	read_str = malloc(sizeof(char)*BUFFER_SIZE);
	if (!read_str)
		return(0);
	start = 0;
	if (ft_strrchr(read_str, '\n'))
		start = ft_strrchr(read_str, '\n');
	printf("%i\n",start);
	end = start;
	printf("%i\n",end);
	while (end == start)
	{
		buf = malloc(8*sizeof(char));
		if (!buf)
			return(0);
		read_ret = read(fd, buf, 8);
		printf("%s\n",buf);
		printf("%i\n",read_ret);
		ft_strjoin(read_str, buf);
		free(buf);
//SEGUIR AQUI: Cambiar "ft_strrchr" para que devuelva la posicion(i) y no el puntero.
		end = ft_strrchr(read_str,'\n');
		/* if (read_ret == 8)
			end = ft_strrchr(read_str,'\n');
		else if (read_ret >= 0)
			end = ft_linelen(read_str);
		else
			printf("ERROR\n"); */
		printf("%i\n",end);
	}
	return(ft_substr(read_str, start, end));
}
