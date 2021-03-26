/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skharjo <skharjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 20:06:51 by skharjo           #+#    #+#             */
/*   Updated: 2020/12/13 15:25:59 by skharjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# define STRL "0123456789abcdef"
# define STRU "0123456789ABCDEF"
# define ALLSYMBOLS "cspdfiuxX%-+ .*0123456789"

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_struct
{
	int			nprint;
	const char	*fmt;
	int			sign_space;
	int			i;
	int			sign_minus;
	int			minus;
	int			plus;
	int			space;
	int			zero;
	int			width;
	int			presicion;
	int			star;
	int			length;
	int			dot;
	int			lzero;
	int			arg_zero;
}				t_struct;

int				ft_putchar(char c);
void			ft_putnbr_base(long int n, int base, char ch);
int				ft_putstr(char *str, int n);
char			*ft_strchr(const char *str, int ch);
char			*ft_itoabase(__int64_t num, int base, char c);
void			ft_printnmb(t_struct *f, char *str);
int				ft_printch(int count, char c);
char			*ft_strjoin(char *s1, char *s2);
void			ft_bprint(t_struct *f, char *str);
int				ft_strlen(const char *str);
int				ft_isdigit(int c);
int				ft_printf(const char *fmt, ...);
void			conversations(char c, t_struct *f, va_list ap);
int				ft_printf_prs(const char *fmt,
							t_struct *list, va_list ap, int i);
void			modifiers(const char *fmt, t_struct *f, va_list ap);
int				parcel2(t_struct *f, int i, const char *fmt, va_list ap);
void			ifchar(t_struct *f, va_list ap);
void			ifhex(t_struct *f, va_list ap);
void			ifint(t_struct *f, va_list ap);
void			ifpercent(t_struct *f);
void			ifptr(t_struct *f, va_list ap);
void			ifstring(t_struct *f, va_list ap);
void			ifudecint(t_struct *f, va_list ap);
void			bezerostruct(t_struct *f);
char			*ft_doubletostr(double num, int tolerance);
void			iffloat(t_struct *f, va_list ap);

#endif
