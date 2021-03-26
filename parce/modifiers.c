/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skharjo <skharjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:26:17 by skharjo           #+#    #+#             */
/*   Updated: 2020/12/13 16:41:32 by skharjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	ft_get_flags(const char *fmt, t_struct *f)
{
	if (fmt[f->i] == '0')
	{
		f->lzero = 1;
		f->i++;
	}
	else if (fmt[f->i] == '-')
	{
		f->minus = 1;
		f->lzero = 0;
		f->i++;
	}
	else if (fmt[f->i] == '+')
	{
		f->plus = 1;
		f->i++;
	}
	else if (fmt[f->i] == ' ')
	{
		f->sign_space = 1;
		f->i++;
	}
}

void	ft_get_width(const char *fmt, t_struct *f, va_list ap)
{
	if (ft_isdigit(fmt[f->i]))
	{
		while (ft_isdigit(fmt[f->i]))
		{
			f->width = f->width * 10 + (fmt[f->i] - '0');
			f->i++;
		}
	}
	else if (fmt[f->i] == '*')
	{
		f->width = va_arg(ap, int);
		if (f->width < 0)
		{
			f->width *= -1;
			f->lzero = 0;
			f->minus = 1;
		}
		f->i++;
	}
}

void	ft_get_pres(const char *fmt, t_struct *f, va_list ap)
{
	f->i++;
	if (ft_isdigit(fmt[f->i]))
	{
		while (ft_isdigit(fmt[f->i]))
		{
			f->presicion = f->presicion * 10 + (fmt[f->i] - '0');
			f->i++;
		}
		if (f->presicion == 0)
			f->presicion = -2;
	}
	else if (fmt[f->i] == '*')
	{
		f->presicion = va_arg(ap, int);
		if (f->presicion < 0)
			f->presicion = 0;
		else if (f->presicion == 0)
			f->presicion = -2;
		f->i++;
	}
	else
		f->presicion = -2;
}

void	modifiers(const char *fmt, t_struct *f, va_list ap)
{
	ft_get_flags(fmt, f);
	ft_get_width(fmt, f, ap);
	if (fmt[f->i] == '.')
		ft_get_pres(fmt, f, ap);
}
