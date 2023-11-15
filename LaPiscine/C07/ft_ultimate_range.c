#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	min_i;
	int	*num;

	i = 0;
	if (min >= max)
		return (0);
	num = (int *)malloc(sizeof(int) * (max - min));
	if (num == NULL)
		return (-1);
	i = 0;
	min_i = min;
	while (min_i < max)
	{
		num[i] = min_i;
		min_i++;
		i++;
	}
	*range = num;
	return (max - min);
}