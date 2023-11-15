#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*ret;
	int		i;

	i = 0;
	while (src[i])
		i++;
	ret = (char *)malloc(sizeof(char) * (i + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}