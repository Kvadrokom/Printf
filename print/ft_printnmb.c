/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnmb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skharjo <skharjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 20:20:47 by skharjo           #+#    #+#             */
/*   Updated: 2020/12/09 20:32:05 by skharjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	ft_printnmb(t_struct *f, char *str)
{
	if (f->sign_space && !f->sign_minus)
		f->nprint += ft_putchar(' ');
	if (f->minus)
	{
		if (f->sign_minus)
			f->nprint += ft_printch(1, '-');
		else if (!f->sign_minus && f->plus)
			f->nprint += ft_printch(1, '+');
		f->nprint += ft_printch(f->zero, '0');
		f->nprint += ft_putstr(str, ft_strlen(str));
		f->nprint += ft_printch(f->space, ' ');
	}
	else
	{
		f->nprint += ft_printch(f->space, ' ');
		if (f->sign_minus)
			f->nprint += ft_printch(1, '-');
		else if (!f->sign_minus && f->plus)
			f->nprint += ft_printch(1, '+');
		f->nprint += ft_printch(f->zero, '0');
		f->nprint += ft_putstr(str, ft_strlen(str));
	}
}
