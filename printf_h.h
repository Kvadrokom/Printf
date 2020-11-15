#ifndef HEAD_PRINTF
#define	HEAD_PRINTF

#define STRL "0123456789abcdef"
#define STRU "0123456789ABCDEF"

typedef struct			S_struct
{
	int					nprint;
	const char			*fmt;
    int                 sign_space;
	int		            i;
    int                 len;
    int                 minus;
    int                 plus;
    int                 space;
    int                 zero;
    int                 width;
    int                 presicion;
    int                 star;
    int                 length;
}						T_struct;

void    ft_putchar(char    c);
void    ft_putnbr(long int n);
void    ft_putnbr_base(long int n, int  base, char ch);
void    ft_putstr(char  *str, int n);
char    *ft_dblstr(char *str, int j);
char    *DoubleToStr(double num, int tolerance);
int     count_inbr(long int nbr);
char	*ft_strchr (const char *str, int ch);
char    *ft_itoabase(__int64 num, int base, char c);
void    ft_printnmb(T_struct *f, __int64 num, char *str);
void    ft_printch(int count, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void    ft_bprint(T_struct *f,__int64 ival, char *str);
int     ft_strlen(const char *str);
int     ft_isdigit(char ch);

#endif