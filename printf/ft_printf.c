#include "ft_printf.h"
#include <stdio.h>

static int  print_address(long long address)
{
    char *deci_alpha = "0123456789abcdef";
    int len;
    char *ret;
    long long fake_add;

    len = 1;
    fake_add = address;
    while (fake_add /= 16)
		len++;
    ret = (char *)malloc(len + 1);
    if(ret == NULL)
        return (0);
    ret[len--] = '\0';
    while(address)
    {
        ret[len--] = deci_alpha[address % 16];
        address /= 16;
    }
    len = write(0, ft_strjoin("0x",ret), ft_strlen(ret)+2);
    return len;
}

static char *convert_unsigned(int n, char *deci_alpha, int divide_n) {
    unsigned int u;
    unsigned int fake_u;
    char *ret;
    int len;

    u = (unsigned int)n;
    fake_u = u;
    len = 1;
    while (fake_u /= divide_n)
		len++;
    ret = (char *)malloc(len + 1);
    if(ret == NULL)
        return (NULL);
    ret[len--] = '\0';
    while(u)
    {
        ret[len--] = deci_alpha[u % divide_n];
        u /= divide_n;
    }
    return (ret);
}

static int print_int(char c, int n)
{
    int len = 0;
    char *s;
    //char *deci_alpha;
    //int divide_n;

    if (c == 'c')
    {
        len = write(0, &n, 1);
        return (len);
    }
    if(c == 'd' || c == 'i')
        s = ft_itoa(n);
    else
    {
        if (c == 'u')
            s = convert_unsigned(n, "0123456789", 10);
        else if(c == 'x')
            s = convert_unsigned(n, "0123456789abcdef", 16);
        else if(c == 'X')
            s = convert_unsigned(n, "0123456789ABCDEF", 16);
    }
    len = write(0, s, ft_strlen(s));
    return (len);
}

static int match_option(char c, va_list *ap)
{
    int n;
    int len;
    long long long_n;
    char *s;

    len = 0;
    if(c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == 'c')
    {
        n = va_arg(*ap, int);
        len = print_int(c, n);
    }
    else if(c == 's')
    {
        s = va_arg(*ap, char *);
        len = write(0,s,ft_strlen(s));
    }
    else if(c == 'p')
    {
        long_n = va_arg(*ap, long long);
        len = print_address(long_n);
    }
    else if(c == '%')
        len = write(0, "%%", 1);
    return (len);
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    const char    *find;
    int total_len;
    
    total_len = 0;
    va_start(ap, format);
    while ((find = ft_strchr(format, '%')))
    {
        total_len += write(0, format, find - format);
        total_len += match_option(*(find+1),&ap);
        format = find+2;
    }
    total_len += write(0, format, ft_strlen(format));
    va_end(ap);
    return (total_len);
}

/*
%c
$s
%p
%d
$i
%u
%x %X
%%
*/

int main() {
    int a = 0;
    (void)a;
    int n1 = ft_printf("주소 : %p 안녕하세요 %s 저의\'%c%% 나이는 %d %x %u %X %i 입니다. sfad1241\n",&a ,"탱님",'s', -053, -053, -053, -053, -053);
    printf("%d\n",n1);
    int n2 = printf("주소 : %p 안녕하세요 %s 저의\'%c%% 나이는 %d %x %u %X %i 입니다. sfad1241\n",&a , "탱님",'s', -053, -053, -053, -053, -053);
    printf("%d\n",n2);
}
/*
오버 플로우 범위 다름 고려해서 테스트
*/