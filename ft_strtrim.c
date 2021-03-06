/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalaoui <yaalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 11:43:47 by yaalaoui          #+#    #+#             */
/*   Updated: 2020/11/21 20:23:30 by yaalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "ray.h"

int			ft_isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	return (0);
}

static int	ft_back(const char *main, const char *trim)
{
	int j;

	j = ft_strlen(main) - 1;
	while (main[j] == trim[0])
		j--;
	return (j);
}

char		*ft_strtrim(char *s1, char const *set)
{
	char	*sset;
	int		start;
	int		finish;

	if (!s1)
		return (0);
	start = 0;
	finish = ft_back(s1, set);
	if (start >= finish)
	{
		sset = malloc(1);
		sset[0] = 0;
		return (sset);
	}
	sset = ft_substr(s1, start, finish + 1);
	return (sset);
}
