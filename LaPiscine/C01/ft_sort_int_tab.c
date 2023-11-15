#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (tab[j] > tab[i])
			{
				tmp = *(tab + j);
				*(tab + j) = *(tab + i);
				*(tab + i) = tmp;
			}
			j++;
		}
		i++;
	}
}