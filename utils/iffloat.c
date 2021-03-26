/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iffloat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skharjo <skharjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 17:40:23 by skharjo           #+#    #+#             */
/*   Updated: 2020/12/09 20:14:51 by skharjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int		ft_pow10(int pres)
{
	int pow10;

	pow10 = 1;
	while (pres--)
		pow10 *= 10;
	return (pow10);
}

void	ft_rounding(double *nmb, int pres)
{
	*nmb = *nmb * ft_pow10(pres + 1);
	if ((int)(*nmb) % 10 > 4)
	{
		*nmb = *nmb + 10;
		*nmb = *nmb / ft_pow10(pres + 1);
	}
	else
		*nmb = *nmb / ft_pow10(pres + 1);
}

void	iffloat(t_struct *f, va_list ap)
{
	double		dval;
	double		tval;
	char		*str;

	dval = va_arg(ap, double);
	if (dval == 0)
		f->arg_zero = 1;
	if (dval < 0)
		f->sign_minus = 1;
	tval = dval;
	if (f->presicion < 0)
		f->presicion = 0;
	else if (f->presicion == 0)
		f->presicion = 6;
	ft_rounding(&tval, f->presicion);
	str = ft_doubletostr(tval, f->presicion);
	if (str)
	{
		f->length = ft_strlen(str);
		ft_bprint(f, str);
		free(str);
	}
}
