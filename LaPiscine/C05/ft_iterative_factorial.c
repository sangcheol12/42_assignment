int	ft_iterative_factorial(int nb)
{
	int	ret;

	if (nb < 0)
		return (0);
	ret = 1;
	while (nb > 1)
	{
		ret *= nb;
		nb--;
	}
	return (ret);
}