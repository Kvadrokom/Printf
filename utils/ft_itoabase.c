/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skharjo <skharjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:58:34 by skharjo           #+#    #+#             */
/*   Updated: 2020/12/08 20:30:56 by skharjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

#define STR "2147483648"

static char	*ft_min_zero(int num)
{
	char	*tmp;
	int		i;

	i = 0;
	if (num == 0)
	{
		tmp = (char *)malloc(sizeof(char) * 2);
		if (!tmp)
			return (NULL);
		tmp[0] = '0';
		tmp[1] = '\0';
		return (tmp);
	}
	tmp = (char *)malloc(sizeof(char) * 11);
	if (tmp)
	{
		while (i < 11)
		{
			tmp[i] = STR[i];
			i++;
		}
		tmp[i] = '\0';
		return (tmp);
	}
	return (NULL);
}

char		*make_str_from_int(char *c, int i)
{
	int		k;
	char	*tmp;

	k = 0;
	tmp = malloc(sizeof(char) * (i + 1));
	if (tmp)
	{
		while (i > 0)
			tmp[k++] = c[(i--) - 1];
		tmp[k] = '\0';
		return (tmp);
	}
	return (NULL);
}

char		*ft_itoabase(__int64_t num, int base, char ch)
{
	char	c[40];
	int		i;
	char	*tmp;
	char	*str;

	if (num == -2147483648 || num == 0)
		return (ft_min_zero(num));
	if (ch == 'x')
		str = STRL;
	else
		str = STRU;
	i = 0;
	if (num < 0)
		num = -num;
	while (num > 0)
	{
		c[i++] = str[num % base];
		num = num / base;
	}
	tmp = make_str_from_int(c, i);
	return (tmp);
}
