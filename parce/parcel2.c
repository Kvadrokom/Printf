/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcel2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skharjo <skharjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:43:53 by skharjo           #+#    #+#             */
/*   Updated: 2020/12/08 20:30:14 by skharjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int	parcel2(t_struct *f, int i, const char *fmt, va_list ap)
{
	f->i = i;
	if (!ft_strchr("cspdfiuxX%", fmt[i]))
		modifiers(fmt, f, ap);
	else if (ft_strchr("cspdfiuxX%", fmt[i]))
	{
		conversations(fmt[i], f, ap);
		bezerostruct(f);
	}
	return (f->i - 1);
}
