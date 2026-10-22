/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 11:39:52 by crgrandj          #+#    #+#             */
/*   Updated: 2026/09/19 12:33:36 by crgrandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t length)
{
	char	*temp;
	size_t	i;

	i = 0;
	if (length > 0)
	{
		temp = ptr;
		while (i < length)
		{
			*temp++ = (unsigned char) c;
			i++;
		}
	}
	return (ptr);
}

// int main(void)
// {
// 	int t = 5;
// 	int ch;
// 	char s1[] = "bonsoir";
// 	char s2[] = "bonsoir";
// 	char c = '@';
// 	ch = c;
// 	printf("   string :%s\n", s1);
// 	ft_memset(s1, ch, t);
// 	memset(s2, ch, t);
// 	printf("ft_memset :%s\n", s1);
// 	printf("   memset :%s\n", s2);
// }