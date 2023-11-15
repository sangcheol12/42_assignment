#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*ret;
	int		i;

	i = 0;
	while (src[i])
		i++;
	ret = (char *)malloc(sizeof(char) * (i + 1));
	if (ret == NULL)
		return (0);
	i = 0;
	while (src[i])
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*stocks;
	int			i;
	int			str_len;

	i = 0;
	stocks = (t_stock_str *) malloc(sizeof(t_stock_str) * (ac + 1));
	if (stocks == NULL)
		return (NULL);
	while (i < ac)
	{
		str_len = ft_len(av[i]);
		stocks[i].size = str_len;
		stocks[i].str = av[i];
		stocks[i].copy = ft_strdup(av[i]);
		i++;
	}
	stocks[i].size = 0;
	stocks[i].str = 0;
	stocks[i].copy = 0;
	return (stocks);
}