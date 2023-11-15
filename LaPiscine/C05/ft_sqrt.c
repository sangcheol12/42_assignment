int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i < nb / i)
		i++;
	if (i * i == nb)
		return (i);
	return (0);
}