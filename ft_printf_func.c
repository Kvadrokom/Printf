#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <io.h>
#include "printf_h.h"

#define STRL "0123456789abcdef"
#define STRU "0123456789ABCDEF"

void    ft_putchar(char    c)
{
	_write(1, &c, 1);
}

int     ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_isdigit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

void    ft_putstr(char  *str, int n)
{
	while (n--)
		_write(1, &(*str++), 1);
}


char  *ft_dblstr(char *str, int j)
{
	char  *tmp;
	int   i;

	i = 0;
	j++;
	tmp = (char*)malloc(sizeof(char) * j);
	while (i < j)
	{
		tmp[i] = str[i];
		i++;
	}
	return (tmp);
}

char* DoubleToStr(double num, int tolerance)
{
	char    s[40];
	int     i;
	int     j;

	i = tolerance;
	j = 0;
	if (num < 0)
	{
		num = -num;
		s[j++] = '-';
	}
	while ((int)num > 0)
	{
		num = num / 10;
		i++;
	}
	num = num * 10;
	while (i > 0)
	{
		s[j++] = (int)num + '0';
		if (--i == tolerance)
			s[j++] = '.';
		num = (num - (double)((int)num)) * 10;
	}
	s[j] = '\0';
	return(ft_dblstr(s, j));
}

int count_inbr(long int nbr)
{
	int i;

	i = 0;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *str, int ch)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)ch)
			return((char *)str + i);
		i++;
	}
	if (str[i] == (char)ch)
		return((char *)str + i);
	return(NULL);
}

char  *make_str_from_int(char *c, int i)
{
	int k;
	char *tmp;

	k = 0;
	tmp = malloc(sizeof(char) * (i + 1));
	if (tmp)
	{
		while (i > 0)
			tmp[k++] = c[(i--) - 1];
		tmp[k] = '\0';
		return(tmp);
	}
	return(NULL);
}

char  *ft_itoabase(__int64 num, int base, char ch)
{
	char  c[40];
	int   i;
	char  *tmp;
	char  *str;

	if (ch == 'x')
		str = STRL;
	else
		str = STRU;
	i = 0;
	if (num < 0)
		num = -num;
	while (num > 0)
	{
		c[i++] = str[num % base];
		num = num / base;
	}
	tmp = make_str_from_int(c, i);
	return (tmp);
}

void    ft_printch(int count, char c)
{
	if (count < 0)
		count = 0;
	while (count--)
		ft_putchar(c);
}

void    ft_printnmb(T_struct *f, __int64 nmb, char *str)
{
	if (f->sign_space && nmb >= 0)
		ft_putchar(' ');
	if (f->minus)
	{
		if (nmb < 0)
			ft_printch(1, '-');
		else if (nmb >= 0 && f->plus)
			ft_printch(1, '+');
		ft_printch(f->zero, '0');
		ft_putstr(str, ft_strlen(str));
		ft_printch(f->space, ' ');
	}
	else
	{
		ft_printch(f->space, ' ');
		if (nmb < 0)
			ft_printch(1, '-');
		else if (nmb >= 0 && f->plus)
			ft_printch(1, '+');
		ft_printch(f->zero, '0');
		ft_putstr(str, ft_strlen(str));
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	int		i;

	i = 0;
	strjoin = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (strjoin)
	{
		while (*s1)
		{
			strjoin[i] = *s1++;
			i++;
		}
		while (*s2)
		{
			strjoin[i] = *s2++;
			i++;
		}
		strjoin[i] = '\0';
	}
	else
		return(NULL);
	return(strjoin);
}

void    ft_bprint(T_struct *f, __int64 ival, char *str)
{
	f->length = ft_strlen(str);
	if (f->width < f->presicion)
	{
		f->width = f->presicion;
		f->zero = f->width > f->length ? f->width - f->length : 0;
	}
	else
	{
		if (f->presicion)
			f->zero = f->presicion > f->length ? f->presicion - f->length : 0;
		f->space = f->width - f->length - f->zero - (f->plus || f->minus);
	}
	ft_printnmb(f, ival, str);
}