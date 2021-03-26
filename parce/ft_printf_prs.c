/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skharjo <skharjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:46:01 by skharjo           #+#    #+#             */
/*   Updated: 2020/12/08 20:30:02 by skharjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int	ft_printf_prs(const char *fmt, t_struct *list, va_list ap, int i)
{
	while (fmt[i])
	{
		if (fmt[i] != '%')
			list->nprint += write(1, &fmt[i], 1);
		else
		{
			if (!ft_strchr(ALLSYMBOLS, fmt[i + 1]))
				break ;
			while (ft_strchr(ALLSYMBOLS, fmt[i + 1]))
			{
				i++;
				if (ft_strchr("cspdiouxXfy%", fmt[i]))
				{
					i = parcel2(list, i, fmt, ap) + 2;
					break ;
				}
				else
					i = parcel2(list, i, fmt, ap);
			}
			continue;
		}
		i++;
	}
	return (list->nprint);
}
