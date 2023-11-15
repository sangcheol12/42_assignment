int	ft_cnt(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	*u1;
	unsigned char	*u2;

	i = 0;
	u1 = (unsigned char *)s1;
	u2 = (unsigned char *)s2;
	while (u2[i])
	{
		if (u1[i] != u2[i])
			return ((u1[i] - u2[i]));
		i++;
	}
	if (u1[i])
		return (u1[i]);
	return (0);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	int		n;
	char	*tmp;

	n = ft_cnt(tab);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}