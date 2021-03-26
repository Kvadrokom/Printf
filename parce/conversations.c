/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skharjo <skharjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:42:30 by skharjo           #+#    #+#             */
/*   Updated: 2020/12/09 18:51:24 by skharjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	conversations(char c, t_struct *f, va_list ap)
{
	if (c == 'c')
		ifchar(f, ap);
	if (c == 's')
		ifstring(f, ap);
	if (c == 'p')
		ifptr(f, ap);
	if (c == 'd' || c == 'i')
		ifint(f, ap);
	if (c == 'u')
		ifudecint(f, ap);
	if (c == 'x' || c == 'X')
		ifhex(f, ap);
	if (c == 'f')
		iffloat(f, ap);
	if (c == '%')
		ifpercent(f);
}
