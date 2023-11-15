int	ft_atoi(char *str)
{
	int	ret;
	int	i;
	int	sign;

	ret = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			break ;
		ret = ret * 10 + (str[i] - '0');
		i++;
	}
	ret *= sign;
	return (ret);
}