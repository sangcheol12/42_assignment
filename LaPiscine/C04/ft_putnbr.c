#include <unistd.h>

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

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2", 2);
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar(nb % 10 + '0');
}