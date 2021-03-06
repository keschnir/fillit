/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fblin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:52:04 by fblin             #+#    #+#             */
/*   Updated: 2015/11/28 18:50:21 by fblin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int s1_len;
	int i;

	s1_len = ft_strlen(s1);
	i = 0;
	while ((int)n > i && *s2)
	{
		*(s1 + s1_len + i) = *(char *)s2;
		i++;
		s2++;
	}
	*(s1 + s1_len + i) = 0;
	return (s1);
}
