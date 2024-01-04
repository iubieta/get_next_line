/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:45:06 by iubieta-          #+#    #+#             */
/*   Updated: 2024/01/04 20:22:12 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "/Users/iubieta-/IkerUbieta/repositorios/libft/libft.h"

int main(void)
{
	int	file;
	int	i;
	char	*rd_buffer;
	
	file = open("text.txt", O_RDONLY);
	printf("%i\n",file);
	read(file, rd_buffer, 8);
	printf("%s\n", rd_buffer);
	printf("%s",ft_substr(rd_buffer, 0, 4));
}