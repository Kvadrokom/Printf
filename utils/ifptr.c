/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifptr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skharjo <skharjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:31:37 by skharjo           #+#    #+#             */
/*   Updated: 2020/12/13 15:25:23 by skharjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	ifptr(t_struct *f, va_list ap)
{
	void	*ptr;
	char	*str;

	ptr = va_arg(ap, void *);
	if (f->presicion < 0)
	{
		str = "0x";
		f->length = ft_strlen(str);
		ft_bprint(f, str);
	}
	else
	{
		if (ptr == 0)
			f->arg_zero = 1;
		str = ft_itoabase((long long int)ptr, 16, 'x');
		str = ft_strjoin("0x", str);
		if (str)
		{
			f->length = ft_strlen(str);
			ft_bprint(f, str);
			free(str);
		}
	}
}
