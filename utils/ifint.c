/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skharjo <skharjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:33:27 by skharjo           #+#    #+#             */
/*   Updated: 2020/12/09 20:14:09 by skharjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	ifint(t_struct *f, va_list ap)
{
	int		ival;
	char	*str;

	ival = va_arg(ap, int);
	if (ival < 0)
		f->sign_minus = 1;
	if (ival == 0)
		f->arg_zero = 1;
	if (f->presicion == -2 && ival == 0)
	{
		ft_bprint(f, "");
		return ;
	}
	str = ft_itoabase(ival, 10, 'x');
	if (str)
	{
		f->length = ft_strlen(str);
		ft_bprint(f, str);
		free(str);
	}
}
