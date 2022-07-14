/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcapela <clcapela@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 05:12:44 by clcapela          #+#    #+#             */
/*   Updated: 2022/06/15 21:10:56 by clcapela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *str, char c)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str != c)
		{
			++i;
			while (*str != c && *str)
				++str;
		}
		else
			++str;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**cl;
	int		i;
	int		count;

	if (!s)
		return (NULL);
	count = 0;
	cl = malloc((1 + ft_count_words(s, c)) * sizeof(char *));
	if (!cl)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			i = 0;
			while (*s != c && *s != '\0' && ++i)
				++s;
			cl[count++] = ft_substr(s - i, 0, i);
		}
		else
			++s;
	}
	cl[count] = 0;
	return (cl);
}

/*#include <stdio.h>
int	main(void)
{
	char cl[] = ".Claudia..Fernanda..da Silva...";
	char c = '.';
	char **aux;
	aux = ft_split(cl, c);
	printf("%s \n", aux[0]);
	printf("%s \n", aux[1]);
	printf("%s \n", aux[2]);
	return (0);
}*/
