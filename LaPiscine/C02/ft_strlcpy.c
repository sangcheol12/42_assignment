unsigned int	src_lenth(char *src)
{
	unsigned int	i;

	i = 0;
	while (*(src + i))
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	t;

	i = 0;
	t = src_lenth(src);
	while (i < t && i + 1 < size)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = 0;
	return (t);
}