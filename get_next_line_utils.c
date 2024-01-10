/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:43:45 by iubieta-          #+#    #+#             */
/*   Updated: 2024/01/10 19:16:26 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int	ft_linelen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0' &&  s[count] != '\n')
		count++;
	if (s[count] == '\n')
		count++;
	return (count);
}

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*ptr;

	ch = (char)c;
	ptr = (char *)s;
	while (*ptr != '\0')
		ptr++;
	while (*ptr != ch && ptr != s)
		ptr--;
	if (*ptr == ch)
		return (ptr);
	else
		return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final_str;

	final_str = NULL;
	if (!s1 && !s2)
		return (NULL);
	else if (s1 && !s2)
		final_str = ft_strdup(s1);
	else if (!s1 && s2)
		final_str = ft_strdup(s2);
	else if (s1 && s2)
	{
		final_str = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
		if (!final_str)
			return (NULL);
		final_str = ft_memcpy(final_str, s1, ft_strlen(s1));
		ft_strlcat(final_str, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	}
	if (!final_str)
		return (NULL);
	else
		return (final_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (0);
	ft_strlcpy(substr, &s[start], len + 1);
	return (substr);
}