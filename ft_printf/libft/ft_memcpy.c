/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 10:10:53 by crgrandj          #+#    #+#             */
/*   Updated: 2026/10/10 14:50:26 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*s;
	char		*d;

	s = (char *)src;
	d = (char *)dst;
	i = -1;
	while (++i < n)
		*d++ = *s++;
	return (dst);
}

// *d++ = *s++ == d[i] = s[i];

// int main(void)
// {
// 	char s1[] = "abcde";
// 	char s2[] = "000000";
// 	int t = 3;

// 	printf("     dst b4 :%s\n", s1);
// 	printf("      src b4:%s\n", s2);
// 	ft_memcpy(s1, s2, t);
// 	printf("  dst after :%s\n", s1);
// 	memcpy(s1, s2, t);
// 	printf("real memcpy :%s\n", s1);
// }