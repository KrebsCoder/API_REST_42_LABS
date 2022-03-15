/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 20:59:00 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/02/26 02:55:54 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/api.h"

size_t	ft_strlen(const char *string)
{
	size_t	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len1;
	int		len2;
	char	*ccat;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ccat = malloc(len1 + len2 + 1);
	if (!ccat)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ccat[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		ccat[i + j] = s2[j];
		j++;
	}
	ccat[i + j] = '\0';
	return (ccat);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dst;

	dst = malloc(ft_strlen(src) + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
