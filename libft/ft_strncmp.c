/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:28:28 by eebersol          #+#    #+#             */
/*   Updated: 2015/12/11 19:07:10 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- > 0)
	{
		if (*s1 != *s2)
		{
			if (*(unsigned char *)s1 > *(unsigned char *)s2)
				return (1);
			else
				return (-1);
		}
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (0);
}
