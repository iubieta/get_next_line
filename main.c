/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:38:00 by iubieta-          #+#    #+#             */
/*   Updated: 2024/01/08 19:47:05 by iubieta-         ###   ########.fr       */
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
	while (i < 10)
	{
		line = get_next_line(file);
		if (line)
			printf("Linea %d: %s", i, line);
		else
			printf("\nFIN.");
		i++;
	}
}