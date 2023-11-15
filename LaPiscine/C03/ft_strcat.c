int	ft_size(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	dest_idx;
	int	src_idx;

	dest_idx = ft_size(dest);
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