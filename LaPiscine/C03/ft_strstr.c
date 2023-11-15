int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	str_len;
	int	find_len;

	i = 0;
	str_len = ft_len(str);
	find_len = ft_len(to_find);
	while (i <= (str_len - find_len))
	{
		j = 0;
		while (str[i + j] == to_find[j] && j < find_len)
			j++;
		if (j == find_len)
			return (str + i);
		i++;
	}
	return (0);
}