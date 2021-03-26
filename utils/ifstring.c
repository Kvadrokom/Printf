/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifstring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skharjo <skharjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:28:26 by skharjo           #+#    #+#             */
/*   Updated: 2020/12/13 16:52:29 by skharjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	ifstring(t_struct *f, va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if ((f->presicion == 0) || f->presicion >= ft_strlen(str))
		f->presicion = ft_strlen(str);
	else if (f->presicion == -2)
		f->presicion = 0;
	if (f->width >= f->presicion)
		f->space = f->width - f->presicion;
	if (f->minus)
	{
		f->nprint += ft_putstr(str, f->presicion);
		f->nprint += ft_printch(f->space, ' ');
	}
	else
	{
		f->nprint += ft_printch(f->space, ' ');
		f->nprint += ft_putstr(str, f->presicion);
	}
}
