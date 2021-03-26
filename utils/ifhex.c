/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifhex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skharjo <skharjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:37:41 by skharjo           #+#    #+#             */
/*   Updated: 2020/12/09 20:15:19 by skharjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	ifhex(t_struct *f, va_list ap)
{
	unsigned int	val16;
	char			*str;

	val16 = va_arg(ap, int);
	if (val16 == 0)
		f->arg_zero = 1;
	if (val16 < 0)
		f->sign_minus = 1;
	if (f->presicion == -2 && val16 == 0)
	{
		ft_bprint(f, "");
		return ;
	}
	str = ft_itoabase(val16, 16, f->fmt[f->i]);
	f->plus = 0;
	f->sign_space = 0;
	if (str)
	{
		f->length = ft_strlen(str);
		ft_bprint(f, str);
		free(str);
	}
}
