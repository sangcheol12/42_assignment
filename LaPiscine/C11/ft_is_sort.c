int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	orem;
	int	narim;

	i = 0;
	orem = 0;
	narim = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			orem++;
		else if (f(tab[i], tab[i + 1]) < 0)
			narim++;
		if (orem > 0 && narim > 0)
			return (0);
		i++;
	}
	return (1);
}