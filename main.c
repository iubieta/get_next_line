/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:38:00 by iubieta-          #+#    #+#             */
/*   Updated: 2024/01/05 17:19:03 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
	int		file;
	char	*line;
	int		i;
	
	file = open("test.txt", O_RDONLY);
	i = 0;
	while (i < 8)
	{
		line = get_next_line(file);
		printf("%s",line);
		i++;
	}
}