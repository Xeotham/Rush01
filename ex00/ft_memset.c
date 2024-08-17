/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 12:01:17 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/17 12:04:23 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static void	memset_loop(char *s, int c, size_t n, size_t i)
{
	if (i < n)
	{
		s[i] = c;
		return (memset_loop(s, c, n, ++i));
	}
}

void	*ft_memset(void *s, int c, size_t n)
{
	memset_loop((char *)s, c, n, 0);
	return (s);
}
