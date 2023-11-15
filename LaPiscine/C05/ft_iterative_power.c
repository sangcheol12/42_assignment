int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	ret;

	if (power < 0)
		return (0);
	i = 0;
	ret = 1;
	while (i < power)
	{
		ret *= nb;
		i++;
	}
	return (ret);
}