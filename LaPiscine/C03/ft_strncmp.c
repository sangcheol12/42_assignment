int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*u1;
	unsigned char	*u2;

	i = 0;
	u1 = (unsigned char *)s1;
	u2 = (unsigned char *)s2;
	while (u2[i] && i < n)
	{
		if (u1[i] != u2[i])
			return (u1[i] - u2[i]);
		i++;
	}
	if (i < n && u1[i])
		return (u1[i]);
	return (0);
}