#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>
#include "printf_h.h"

#define ALLSYMBOLS "cspdiouxXfy%#-+ .*0123456789hLljz"

void    bezerostruct(T_struct *f)
{
    f->minus = 0;
    f->space = 0;
    f->width = 0;
    f->presicion = 0;
    f->plus = 0;
    f->length = 0;
    f->zero = 0;
    f->sign_space = 0;
}

void    modifiers(const char *fmt, T_struct *f, va_list ap)
{
    while (fmt[f->i] == '-' || fmt[f->i] == '+' || fmt[f->i] == ' ' || fmt[f->i] == '*')
    {
    if (fmt[f->i] == '-')
        f->minus = 1;
    else if (fmt[f->i] == '+')
        f->plus = 1;
    else if (fmt[f->i] == ' ')
        f->sign_space = 1;
    else if (fmt[f->i] == '*')
        f->star = 1;
    f->i++;
    }
    while (ft_isdigit(fmt[f->i]))
    {
        f->width = f->width * 10 + (fmt[f->i] - '0');
        f->i++;
    }
    if (fmt[f->i] == '.')
    {
        f->i++;
        while (ft_isdigit(fmt[f->i]))
        {
             f->presicion = f->presicion * 10 + (fmt[f->i] - '0');
             f->i++;
        }
    }
}

void    ifchar(T_struct *f, va_list ap)
{
    char    c;

    c = va_arg(ap, int);
    if (f->minus)
    {
        ft_putchar(c);
        ft_printch(f->width - 1, ' ');
    }
    else
    {
        ft_printch(f->width - 1, ' ');
        ft_putchar(c);
    }
}

void    ifstring(T_struct *f, va_list ap)
{
    char    *str;

    str = va_arg(ap, char*);
    if (f->width < f->presicion)
        f->width = f->presicion;
    f->space = f->width - f->presicion;
    if (f->minus)
    {
        ft_putstr(str, (f->presicion > ft_strlen(str) ? ft_strlen(str):f->presicion));
        ft_printch(f->space, ' ');
    }
    else
    {
        ft_printch(f->space, ' ');
        ft_putstr(str, (f->presicion > ft_strlen(str) ? ft_strlen(str):f->presicion));
    }
    f->nprint += ft_strlen(str) > f->width ? f->width:ft_strlen(str);
}

void    ifptr(T_struct *f, va_list ap)
{
    void    *ptr;
    char    *str;
    char    *tmp;

    ptr = va_arg(ap, void*);
    str = ft_itoabase((long long int)ptr, 16, 'x');
    tmp = str;
    str = ft_strjoin("0x", str);
    if (tmp)
        free(tmp);
    if (str)
    {
        ft_bprint(f, (long long int)ptr, str);
        free(str); 
        f->nprint += f->width + 2;
    }
}

void    ifint(T_struct *f, va_list ap)
{
    int     ival;
    char    *str;

    ival = va_arg(ap, int);
    if (f->star)
    {
        f->width = ival;
        ival = va_arg(ap, int);
    }
    str  = ft_itoabase(ival, 10, 'x');
    if (str)
    {
        ft_bprint(f, ival, str);
        free(str);
    }
    f->nprint += f->width > f->presicion ? f->width + 1:f->presicion + 1;
}

void    ifudecint(T_struct *f, va_list ap)
{
    unsigned int    uval;
    char    *str;

    uval = va_arg(ap, unsigned int);
    f->plus = 0;
    if (f->star)
    {
        f->width = uval;
        uval = va_arg(ap, unsigned int);
    }
    str  = ft_itoabase(uval, 10, 'x');
    if (str)
    {
        ft_bprint(f, uval, str);
        free(str);
    }
    f->nprint += f->width > f->presicion ? f->width + 1:f->presicion + 1;
}

void    ifhex(T_struct *f, va_list ap)
{
    unsigned int    val16;
    char            *str;

    val16 = va_arg(ap, int);
    str = ft_itoabase(val16, 16, f->fmt[f->i]);
    f->plus = 0;
    f->sign_space = 0;
    if (str)
    {
        ft_bprint(f, val16, str);
        free(str);
    }
    f->nprint += f->width > f->presicion ? f->width + 1:f->presicion + 1;
}

void    ifloat(T_struct *f, va_list ap)
{
    double  dval;
    char    *str;

    dval = va_arg(ap, double);
    str = DoubleToStr(dval, f->presicion);
    if (str)
    {
        ft_bprint(f, dval, str);
        free(str);
    }
    f->nprint += f->width > f->presicion ? f->width + 1:f->presicion + 1;
}

void    ifpercent(T_struct *f)
{
    ft_putchar('%');
    f->nprint += 1;
}

void    conversations(char c, T_struct *f, va_list ap)
{
    if (c == 'c')
        ifchar(f, ap);
    if (c == 's')
        ifstring(f, ap);
    if (c == 'p')
        ifptr(f, ap);
    if (c == 'd' || c== 'i')
        ifint(f, ap);
    if (c == 'u')
        ifudecint(f, ap);
    if (c == 'x' || c == 'X')
        ifhex(f, ap);
    if (c == 'f')
        ifloat(f, ap);
    if (c == '%')
        ifpercent(f);
}

int parcel2(T_struct *f, int i, const char *fmt, va_list ap)
{
    f->i = i;
    if (!ft_strchr("cspdfiuxX%", fmt[i]))
        modifiers(fmt, f, ap);
    else if (ft_strchr("cspdfiuxX%", fmt[i]))
    {
        conversations(fmt[i], f, ap);
        bezerostruct(f);
    }
    return(f->i - 1);
}

int     ft_printf_prs(const char*fmt, T_struct  *list, va_list ap, int i)
{
    while (fmt[i])
    {
        if (fmt[i] != '%')
            list->nprint += write(1, &fmt[i], 1);
        else
        {
            if (!ft_strchr(ALLSYMBOLS,fmt[i + 1]))
                break;
            while (ft_strchr(ALLSYMBOLS,fmt[i + 1]))
            {
                i++;
                if (ft_strchr("cspdiouxXfy%", fmt[i]))
                {
                    i = parcel2(list, i, fmt, ap) + 2;
                    break;
                }
                else
                    i = parcel2(list, i, fmt, ap);
            }
            continue;
        }
        i++;
    }
    return(list->nprint);
}

int ft_printf(char *fmt, ...)
{
    va_list             ap;
    int                 length;
    static T_struct     f;
    int                 i;

    length = 0;
    i = 0;
    f.fmt = fmt;
    va_start(ap, fmt);
    length = ft_printf_prs(fmt, &f, ap, i);
    va_end(ap);
    f.nprint = 0;
    return (length);
}

int     main(void)
{
    int a = ft_printf("%-.4f \n", 123.1234567);
    int b = ft_printf("%-3.8d\n", 1000);
    int c = ft_printf("%10.15s\n", "Eto prostay proverka.");
    ft_printf("%d %d %d", a, b, c);
	return (0);
}