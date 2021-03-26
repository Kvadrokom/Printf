/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bezerostruct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skharjo <skharjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:24:35 by skharjo           #+#    #+#             */
/*   Updated: 2020/12/13 16:12:58 by skharjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	bezerostruct(t_struct *f)
{
	f->minus = 0;
	f->space = 0;
	f->width = 0;
	f->presicion = 0;
	f->plus = 0;
	f->length = 0;
	f->zero = 0;
	f->sign_space = 0;
	f->dot = 0;
	f->lzero = 0;
	f->arg_zero = 0;
	f->sign_minus = 0;
	f->star = 0;
}
