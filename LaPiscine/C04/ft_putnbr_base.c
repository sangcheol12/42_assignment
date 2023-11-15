#include <unistd.h>

int	check_invalid(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			return (0);
		j = 0;
		if (str[i] == '+' || str[i] == '-')
			return (0);
		while (j < i)
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

int	recursive_print(long nbr, long size, char *base)
{
	char	c;

	if (nbr < size)
		return (nbr);
	recursive_print(nbr / size, size, base);
	c = base[nbr % size];
	write(1, &c, 1);
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	c;
	long	base_size;
	long	i;
	long	i2;

	i = (long)nbr;
	base_size = check_invalid(base);
	if (!base_size)
		return ;
	if (i < 0)
	{
		write(1, "-", 1);
		i *= -1;
	}
	i2 = i;
	while (i2 >= base_size)
		i2 /= base_size;
	c = base[i2];
	write(1, &c, 1);
	nbr = recursive_print(i, base_size, base);
}