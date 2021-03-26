/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifpercent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skharjo <skharjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:41:17 by skharjo           #+#    #+#             */
/*   Updated: 2020/12/08 20:31:42 by skharjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	ifpercent(t_struct *f)
{
	if (f->minus)
	{
		f->nprint += ft_putstr("%", 1);
		f->nprint += ft_printch(f->width - 1, ' ');
	}
	else
	{
		if (!f->lzero)
			f->nprint += ft_printch(f->width - 1, ' ');
		else
			f->nprint += ft_printch(f->width - 1, '0');
		f->nprint += ft_putstr("%", 1);
	}
}
