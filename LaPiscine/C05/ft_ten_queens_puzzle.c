#include <unistd.h>

int	check_possibe(int *arr, int depth)
{
	int	i;

	i = 0;
	while (i < depth)
	{
		if (arr[i] == arr[depth] || \
		-(depth - i) == (arr[depth] - arr[i]) \
		|| (depth - i) == (arr[depth] - arr[i]))
			return (0);
		i++;
	}
	return (1);
}

void	recursive_queen(int *arr, int depth, int *cnt)
{
	int		y;
	int		i;
	char	c;

	i = 0;
	if (depth == 10)
	{
		while (i < 10)
		{
			c = (char)arr[i] + '0';
			write(1, &c, 1);
			i++;
		}
		write(1, "\n", 1);
		(*cnt)++;
	}
	y = 0;
	while (y < 10)
	{
		arr[depth] = y;
		if (check_possibe(arr, depth))
			recursive_queen(arr, depth + 1, cnt);
		y++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	arr[11];
	int	cnt;
	int	i;

	i = 0;
	while (i < 11)
		arr[i++] = 0;
	recursive_queen(arr, 0, &cnt);
	return (cnt);
}

#include <stdio.h>

int main()
{
	ft_ten_queens_puzzle();
}