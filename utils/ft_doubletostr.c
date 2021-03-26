/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubletostr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skharjo <skharjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:54:35 by skharjo           #+#    #+#             */
/*   Updated: 2020/12/09 20:50:12 by skharjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

char		*ft_dblstr(char *str, int j, int pres)
{
	char	*tmp;
	int		i;

	str[j] = '\0';
	i = 0;
	j++;
	tmp = (char *)malloc(sizeof(char) * j);
	while (i < j)
	{
		if (pres == 0)
		{
			if (str[i] == '.')
			{
				tmp[i] = '\0';
				return (tmp);
			}
		}
		tmp[i] = str[i];
		i++;
	}
	return (tmp);
}

void		ft_subdbstr(double *num, int *j, int *i, char *s)
{
	if ((int)(*num) == 0)
	{
		s[(*j)++] = '0';
		s[(*j)++] = '.';
	}
	else
	{
		while (((int)(*num)) > 0)
		{
			*num = *num / 10;
			(*i)++;
		}
	}
}

char		*ft_doubletostr(double num, int tolerance)
{
	char	s[40];
	int		i;
	int		j;

	i = tolerance;
	j = 0;
	if (num < 0)
	{
		num = -num;
		s[j++] = '-';
	}
	ft_subdbstr(&num, &j, &i, s);
	num = num * 10;
	while (i > 0)
	{
		s[j++] = (int)num + '0';
		if (--i == tolerance)
			s[j++] = '.';
		num = (num - (double)((int)num)) * 10;
	}
	return (ft_dblstr(s, j, tolerance));
}
