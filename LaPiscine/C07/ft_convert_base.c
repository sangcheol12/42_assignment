#include <stdlib.h>

int		ft_size(char *str);
char	*is_space_or_minus(char *str, int *sign);
int		check_invalid(char *str);

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

void	convert_n(long ret, char *base, char *r_ret, int sign)
{
	long	fake_ret;
	int		i;
	int		size;

	fake_ret = ret;
	i = 0;
	if (ret && sign == -1)
		r_ret[i++] = '-';
	size = 1 + i;
	while (fake_ret >= ft_size(base))
	{
		fake_ret /= ft_size(base);
		size++;
	}
	r_ret[i] = base[fake_ret];
	r_ret[size] = 0;
	size--;
	while (ret >= ft_size(base))
	{
		i = ret % ft_size(base);
		r_ret[size] = base[i];
		ret /= ft_size(base);
		size--;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	ret;
	int		sign;
	char	*real_ret;

	real_ret = (char *)malloc(sizeof(char) * 30);
	if (real_ret == NULL)
		return (NULL);
	ret = 0;
	if (!check_invalid(base_from) || !check_invalid(base_to))
		return (NULL);
	nbr = is_space_or_minus(nbr, &sign);
	cal_base(nbr, base_from, ft_size(base_from), &ret);
	convert_n(ret, base_to, real_ret, sign);
	return (real_ret);
}