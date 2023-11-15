int	ft_size(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

char	*is_space_or_minus(char *str, int *sign)
{
	int	i;

	i = 0;
	*sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (str + i);
}

void	cal_base(char *str, char *base, int base_size, long *ret)
{
	int	i;
	int	j;
	int	x;

	i = ft_size(str) - 1;
	x = 1;
	while (i >= 0)
	{
		j = 0;
		while (j < base_size)
		{
			if (str[i] == base[j])
			{
				*ret += x * j;
				break ;
			}
			j++;
		}
		if (j == base_size)
			return ;
		x *= base_size;
		i--;
	}
}

int	ft_atoi_base(char *str, char *base)
{
	long	ret;
	int		sign;
	int		base_size;
	int		real_ret;

	ret = 0;
	base_size = check_invalid(base);
	if (!base_size)
		return (0);
	str = is_space_or_minus(str, &sign);
	cal_base(str, base, base_size, &ret);
	ret *= sign;
	real_ret = (int)ret;
	return (ret);
}