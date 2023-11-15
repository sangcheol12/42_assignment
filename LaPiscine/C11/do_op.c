#include <unistd.h>

int	add(int a, int b)
{
	return (a + b);
}

int	minus(int a, int b)
{
	return (a - b);
}

int	mul(int a, int b)
{
	return (a * b);
}

int	div(int a, int b)
{
	return (a / b);
}

int	mod(int a, int b)
{
	return (a % b);
}

int	init_i(int n)
{
	int	i;

	i = 1;
	while (i != 1000000000)
	{
		if (i * 10 > n)
			break ;
		i *= 10;
	}
	return (i);
}

void	ft_putnbr(int nb)
{
	char	c;
	int		i;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	i = init_i(nb);
	while (i != 0)
	{
		c = (char)(nb / i) + '0';
		write(1, &c, 1);
		nb %= i;
		i /= 10;
	}
}

#include <unistd.h>

void	ft_putnbr(int nb);
int		add(int a, int b);
int		minus(int a, int b);
int		mul(int a, int b);
int		div(int a, int b);
int		mod(int a, int b);

int	ft_atoi(char *str)
{
	int	ret;
	int	i;
	int	sign;

	ret = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			break ;
		ret = ret * 10 + (str[i] - '0');
		i++;
	}
	ret *= sign;
	return (ret);
}

void	cal(int n, int n2, char c)
{
	int	ret;
	int	(*fp[5])(int, int);

	ret = 0;
	fp[0] = add;
	fp[1] = minus;
	fp[2] = mul;
	fp[3] = div;
	fp[4] = mod;
	if (c == '+')
		ret = fp[0](n, n2);
	if (c == '-')
		ret = fp[1](n, n2);
	if (c == '*')
		ret = fp[2](n, n2);
	if (c == '/')
		ret = fp[3](n, n2);
	if (c == '%')
		ret = fp[4](n, n2);
	ft_putnbr(ret);
	write(1, "\n", 1);
}

void	do_op(char **argv)
{
	int	n1;
	int	n2;
	int	i;

	i = 0;
	while (argv[2][i])
		i++;
	if (i != 1)
	{
		write(1, "0\n", 2);
		return ;
	}
	n1 = ft_atoi(argv[1]);
	n2 = ft_atoi(argv[3]);
	if ((argv[2][0] == '/' || argv[2][0] == '%') && n2 == 0)
	{
		if (argv[2][0] == '/')
			write(1, "Stop : division by zero\n", 24);
		if (argv[2][0] == '%')
			write(1, "Stop : modulo by zero\n", 22);
		return ;
	}
	cal(n1, n2, argv[2][0]);
	return ;
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
		return (0);
	do_op(argv);
	return (0);
}