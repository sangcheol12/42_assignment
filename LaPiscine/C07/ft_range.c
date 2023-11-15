#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*ret;

	if (min >= max)
		return (NULL);
	ret = (int *)malloc(sizeof(int) * (max - min));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (min < max)
	{
		ret[i] = min;
		i++;
		min++;
	}
	return (ret);
}