#include <unistd.h>

void	print_array(char *first, char *second);
void	init_second(char *first);
void	ft_print_comb2(void);

void	print_array(char *first, char *second)
{
	while (second[0] <= '9' && second[1] <= '9')
	{
		write(1, first, 2);
		write(1, " ", 1);
		write(1, second, 2);
		if (!(first[0] == '9' && first[1] == '8'))
			write(1, ", ", 2);
		if (second[1] == '9')
		{
			second[0]++;
			second[1] = '0';
		}
		else
			second[1]++;
	}
}

void	init_second(char *first)
{
	char	second[3];

	if (first[1] == '9')
	{
		second[0] = first[0] + 1;
		second[1] = '0';
	}
	else
	{
		second[0] = first[0];
		second[1] = first[1] + 1;
	}
	second[2] = 0;
	print_array(first, second);
}

void	ft_print_comb2(void)
{
	char	first[3];

	first[0] = '0';
	first[1] = '0';
	first[2] = 0;
	while (first[0] <= '9' && first[1] <= '9')
	{
		if (first[0] == '9' && first[1] == '9')
			break ;
		init_second(first);
		if (first[1] == '9')
		{
			first[0]++;
			first[1] = '0';
		}
		else
			first[1]++;
	}
}