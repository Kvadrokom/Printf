/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifchar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skharjo <skharjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:21:34 by skharjo           #+#    #+#             */
/*   Updated: 2020/12/08 20:31:24 by skharjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	ifchar(t_struct *f, va_list ap)
{
	char c;

	c = va_arg(ap, int);
	if (f->minus)
	{
		f->nprint += ft_putchar(c);
		f->nprint += ft_printch(f->width - 1, ' ');
	}
	else
	{
		f->nprint += ft_printch(f->width - 1, ' ');
		f->nprint += ft_putchar(c);
	}
}
