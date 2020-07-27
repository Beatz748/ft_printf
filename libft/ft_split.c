/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwindom <hwindom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 18:59:21 by hwindom           #+#    #+#             */
/*   Updated: 2020/05/30 05:46:20 by hwindom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_freewords(char **result)
{
	unsigned int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}

static char		**ft_countwords(char const *s, char c)
{
	unsigned int	i;

	if (!s)
		return (0);
	i = 0;
	while (s && *s)
	{
		if (*s != c)
		{
			i++;
			s = ft_strchr((char *)s, c);
		}
		else
			s++;
	}
	return (ft_calloc(i + 1, sizeof(char *)));
}

char			**ft_split(char const *s, char c)
{
	char			**result;
	char			**temp;
	unsigned int	i;
	unsigned int	i_fin;

	if (!(result = ft_countwords(s, c)))
		return (0);
	temp = result;
	i = 0;
	i_fin = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c && ++i)
			i_fin++;
		while (s[i_fin] && s[i_fin] != c)
			i_fin++;
		if (i < i_fin)
			if (!(*temp++ = ft_substr(s, i, i_fin - i)))
				return (ft_freewords(result));
		i = i_fin;
	}
	*temp = 0;
	return (result);
}
