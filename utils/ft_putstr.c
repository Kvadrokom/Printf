/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skharjo <skharjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:48:45 by skharjo           #+#    #+#             */
/*   Updated: 2020/12/08 20:42:17 by skharjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int	ft_putstr(char *str, int n)
{
	int		i;

	i = 0;
	if (str == NULL)
	{
		i = write(1, "(null)", n);
		return (i);
	}
	while (n--)
		i += write(1, &(*str++), 1);
	return (i);
}
