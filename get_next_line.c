/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:30:09 by iubieta-          #+#    #+#             */
/*   Updated: 2023/12/05 13:19:53 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

BUFFER_SIZE = 256;

char	*get_next_line(int fd)
{
	char		*buf[BUFFER_SIZE];
	static char	*read_str = NULL;
	char		*start;
	char		*end;
	size_t		read_val;
	
	start = ft_strrchr(read_str, '\n');
	end = start;
	while (end == start)
	{
		// malloc(buf)
		read_val = read(fd, buf, BUFFER_SIZE)
		ft_strjoin(read_str, buf);
		// free(buf)
		if (read_val == buffer size)
			end = ft_strrchr(read_str,'\n');
		else if (read_val >= 0)
			end = ft_strlen(read_str);
		else
			printf("ERROR\n");
	}
	return(ft_substr(read_str, start, end));
}
