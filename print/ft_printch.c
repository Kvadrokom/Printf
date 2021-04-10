/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skharjo <skharjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 20:20:41 by skharjo           #+#    #+#             */
/*   Updated: 2020/12/08 20:30:24 by skharjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int	ft_printch(int count, char c)
{
	int i;

	i = 0;
	if (count < 0)
		count = 0;
	i = count;
	while (count--)
		ft_putchar(c);
	return (i);
}
