/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skharjo <skharjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 20:20:17 by skharjo           #+#    #+#             */
/*   Updated: 2020/12/09 20:32:21 by skharjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	ft_bprint(t_struct *f, char *str)
{
	if (f->plus || f->sign_minus)
		f->width -= 1;
	f->zero = f->presicion * (f->presicion >= f->length)
			+ f->length * (f->presicion < f->length) - f->length;
	f->space = f->width * (f->width >= f->length)
			+ f->length * (f->width < f->length) - f->length - f->zero;
	if (f->lzero && (f->presicion == 0))
	{
		f->zero = f->space;
		f->space = 0;
	}
	if (f->dot && !f->presicion && f->arg_zero && !f->star)
	{
		if (f->width)
		{
			ft_printnmb(f, " ");
			return ;
		}
		else
		{
			ft_printnmb(f, "");
			return ;
		}
	}
	ft_printnmb(f, str);
}
