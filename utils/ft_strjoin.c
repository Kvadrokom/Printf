/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skharjo <skharjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:09:17 by skharjo           #+#    #+#             */
/*   Updated: 2020/12/13 15:28:32 by skharjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*strjoin;
	int		i;
	char	*tmp;

	i = 0;
	tmp = s2;
	strjoin = (char *)malloc(sizeof(char) * (ft_strlen(s1) +
			ft_strlen(s2) + 1));
	if (strjoin)
	{
		while (*s1)
		{
			strjoin[i] = *s1++;
			i++;
		}
		while (*s2)
		{
			strjoin[i] = *s2++;
			i++;
		}
		strjoin[i] = '\0';
		free(tmp);
		return (strjoin);
	}
	return (NULL);
}
