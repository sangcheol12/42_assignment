int	ft_find_next_prime(int nb)
{
	int	i;
	int	not_prime;

	if (nb < 2)
		return (2);
	while (1)
	{
		not_prime = 0;
		i = 2;
		while (i <= nb / i)
		{
			if (!(nb % i))
			{
				not_prime = 1;
				break ;
			}
			i++;
		}
		if (!not_prime)
			break ;
		nb++;
	}
	return (nb);
}