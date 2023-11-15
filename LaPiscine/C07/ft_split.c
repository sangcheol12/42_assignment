#include <stdlib.h>

char	*ft_strdup(char **ret, char *str, int *i, int idx)
{
	int	j;
	int	t;

	j = *i;
	while (str[j])
		j++;
	ret[idx] = (char *)malloc(sizeof(char) * (j - *i + 1));
	if (ret[idx] == NULL)
		return (NULL);
	t = 0;
	while (t < j - *i)
	{
		ret[idx][t] = str[*i + t];
		t++;
	}
	ret[idx][t] = 0;
	*i = j;
	return (ret[idx]);
}

void	link_str(char **ret, char *str, int cnt, int len)
{
	int	idx;
	int	i;

	i = 0;
	idx = 0;
	while (i < len && idx < cnt)
	{
		if (str[i] != 0)
		{
			if (ft_strdup(ret, str, &i, idx) == NULL)
				return ;
			idx++;
		}
		i++;
	}
	ret[idx] = NULL;
}

int	split_count(char *str, int cnt)
{
	int	ret;
	int	i;
	int	is_cnt;

	i = 0;
	ret = 0;
	is_cnt = 1;
	while (i < cnt)
	{
		if (str[i] != 0)
		{
			if (is_cnt)
			{
				ret++;
				is_cnt = 0;
			}
		}
		else
			is_cnt = 1;
		i++;
	}
	return (ret);
}

int	fill_null(char *str, char *charset)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (str[i] == charset[j])
			{
				str[i] = 0;
				break ;
			}
			j++;
		}
		i++;
	}
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	char	*new_str;
	int		len;
	int		wd_cnt;
	int		i;

	i = 0;
	while (str[i])
		i++;
	new_str = (char *)malloc(sizeof(char) * (i + 1));
	if (new_str == NULL)
		return (NULL);
	i = -1;
	while (str[++i])
		new_str[i] = str[i];
	new_str[i] = 0;
	len = fill_null(new_str, charset);
	wd_cnt = split_count(new_str, len);
	ret = (char **)malloc(sizeof(char *) * (wd_cnt + 1));
	if (ret == NULL)
		return (NULL);
	link_str(ret, new_str, wd_cnt, len);
	return (ret);
}