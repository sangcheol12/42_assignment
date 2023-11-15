#include "ft_stock_str.h"
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

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		write(1, par[i].str, par[i].size);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		write(1, par[i].copy, par[i].size);
		write(1, "\n", 1);
		i++;
	}
}