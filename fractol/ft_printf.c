#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

#define hex "0123456789abcdef"
int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
int is_flag(char c)
{
	if ((c >= '0' && c <= '9') || c == '.')
		return (1);
	return (0);
}

int before(const char *str, int i)
{
	int f = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		f = f * 10 + (int)(str[i]) - 48;
		i++;
	}
	if (!f)
		f = -1;
	return (f);
}
int after(const char *str, int i)
{
	int f = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		f = f * 10 + (int)(str[i]) - 48;
		i++;
	}
	if (str[i - 1] != '0' && str[i - 1] != '.' && f == 0)
		f = -1;
	return (f);
}
int ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
int ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}
int ft_putstr(char *str, int f1, int f2)
{
	int space;
	int i = 0;
	int ret = 0;
	if (!str)
		return (ft_putstr("(null)", f1, f2));
	if (f2 >= 0)
		space = f1 - ft_min(f2, ft_strlen(str));
	else
		space = f1 - ft_strlen(str);
	while (space > 0)
	{
		ret += ft_putchar(' ');
		space--;
	}
	while (str[i] && f2)
	{
		ret += ft_putchar(str[i]);
		f2--;
		i++;
	}
	return (ret);
}
int ft_nblen(long n, int base)
{
	if (n == 0)
		return (1);
	int i = 0;
	if (n < 0 && base == 10)
	{	
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

int ft_putnbr(long long n, int base, int f1, int f2, int t)
{
	int ret = 0;
	int k = 0;
	if (n < 0 && base == 16)
		n += 4294967295;
	int	len = ft_nblen(n, base);
	int abs_len = len;
	if (n < 0)
		abs_len--;
	if (t)
	{
		int space;
		if (f2 >= 0)
			space = f1 - ft_max(f2 + len - abs_len, len);
		if (f2 == 0 && n == 0)
			space = f1;
		if (f2 < 0)
			space = f1 - len;
		while (space > 0)
		{
			ret += ft_putchar(' ');
			space--;
		}
		if (f2 > abs_len && n < 0)
		{
			ret += ft_putchar('-');
			k = 1;
		}
		while (f2 - abs_len > 0)
		{
			ret += ft_putchar('0');
			f2--;
		}
	}
	if (n == 0 && f2 == 0)
		return (ret);
	if (n < 0 && base == 10)
	{
		if (!k)
			ret += ft_putchar('-');
		n *= -1;
	}
	if (n >= base)
		ret += ft_putnbr(n / base, base, f1, f2, 0);
	ret += ft_putchar(hex[n % base]);
	return (ret);
}
int ft_printf(const char *str, ...)
{
	va_list	ar;
	va_start(ar, str);
	int i = 0;
	int ret = 0;
	int f1,f2;
	while (str[i])
	{
		f1 = f2 = -1;
		if (str[i] != '%')
			ret += ft_putchar(str[i]);
		else
		{
			i++;
			if (is_flag(str[i]))
			{
				f1 = before(str, i);
				f2 = after(str, i);
			}
			while (is_flag(str[i]))
				i++;
			if (str[i] == 'd')
				ret += ft_putnbr(va_arg(ar, int), 10, f1, f2, 1);
			if (str[i] == 'x')
				ret += ft_putnbr(va_arg(ar, long long), 16, f1, f2, 1);	
			if (str[i] == 's')
				ret += ft_putstr(va_arg(ar, char *), f1 ,f2);	
		}
		i++;
	}
	va_end(ar);
	return (ret);
}

int main()
{
	int a = ft_printf("%5.4d\n", -12);
	int b = printf("%5.4d\n", -12);
	printf("%d  %d\n", a, b);
}