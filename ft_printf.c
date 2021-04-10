/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skharjo <skharjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:57:12 by skharjo           #+#    #+#             */
/*   Updated: 2020/12/08 20:32:07 by skharjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *fmt, ...)
{
	va_list			ap;
	int				length;
	static t_struct	f;
	int				i;

	length = 0;
	i = 0;
	f.fmt = fmt;
	va_start(ap, fmt);
	length = ft_printf_prs(fmt, &f, ap, i);
	va_end(ap);
	f.nprint = 0;
	return (length);
}
