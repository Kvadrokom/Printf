/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifudecint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skharjo <skharjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:35:57 by skharjo           #+#    #+#             */
/*   Updated: 2020/12/09 20:18:06 by skharjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	ifudecint(t_struct *f, va_list ap)
{
	unsigned int	uval;
	char			*str;

	uval = va_arg(ap, unsigned int);
	if (uval == 0)
		f->arg_zero = 1;
	f->plus = 0;
	if (f->presicion == -2 && uval == 0)
	{
		ft_bprint(f, "");
		return ;
	}
	str = ft_itoabase(uval, 10, 'x');
	if (str)
	{
		f->length = ft_strlen(str);
		ft_bprint(f, str);
		free(str);
	}
}
