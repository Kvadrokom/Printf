/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skharjo <skharjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:05:33 by skharjo           #+#    #+#             */
/*   Updated: 2020/12/08 20:31:09 by skharjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

char	*ft_strchr(const char *str, int ch)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)ch)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == (char)ch)
		return ((char *)str + i);
	return (NULL);
}
