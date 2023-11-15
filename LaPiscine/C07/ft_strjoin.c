#include <stdlib.h>

int	ft_all_len(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			j++;
		i++;
	}
	cnt += j;
	j = 0;
	while (sep[j])
		j++;
	cnt += (j * (size - 1));
	return (cnt);
}

char	*ft_strcat(char *dest, char *src)
{
	int	dest_idx;
	int	src_idx;

	dest_idx = 0;
	while (dest[dest_idx])
		dest_idx++;
	src_idx = 0;
	while (src[src_idx])
	{
		dest[dest_idx] = src[src_idx];
		dest_idx++;
		src_idx++;
	}
	dest[dest_idx] = 0;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret;
	int		i;

	if (size == 0)
	{
		ret = (char *)malloc(sizeof(char));
		ret[0] = 0;
		return (ret);
	}
	ret = (char *)malloc(sizeof(char) * (ft_all_len(size, strs, sep) + 1));
	if (ret == NULL)
		return (NULL);
	ret[0] = 0;
	i = 0;
	while (i < size)
	{
		ft_strcat(ret, strs[i]);
		if (i != size - 1)
			ft_strcat(ret, sep);
		i++;
	}
	return (ret);
}