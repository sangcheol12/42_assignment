int	is_next_capital(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (0);
	if (c >= 'a' && c <= 'z')
		return (0);
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	yes_cap;

	yes_cap = 1;
	i = 0;
	while (*(str + i) != 0)
	{
		if (yes_cap == 0)
		{
			if (*(str + i) >= 'A' && *(str + i) <= 'Z')
				*(str + i) += ('a' - 'A');
		}
		else
		{
			if (*(str + i) >= 'a' && *(str + i) <= 'z')
				*(str + i) -= ('a' - 'A');
		}
		yes_cap = is_next_capital(*(str + i));
		i++;
	}
	return (str);
}