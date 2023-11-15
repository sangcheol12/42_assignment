unsigned int	ft_size(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	dest_idx;
	unsigned int	src_idx;

	dest_idx = ft_size(dest);
	src_idx = 0;
	while (src[src_idx] && src_idx < nb)
	{
		dest[dest_idx] = src[src_idx];
		dest_idx++;
		src_idx++;
	}
	dest[dest_idx] = 0;
	return (dest);
}