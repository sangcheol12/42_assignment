#include <unistd.h>

void	print_hexa(unsigned char c)
{
	int		i;
	char	arr[2];

	i = 0;
	write(1, "\\", 1);
	arr[0] = "0123456789abcdef"[c / 16];
	arr[1] = "0123456789abcdef"[c % 16];
	write(1, arr, 2);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	c;

	i = 0;
	while (*(str + i) != 0)
	{
		c = (unsigned char) *(str + i);
		if (c >= 32 && c < 127)
			write(1, (str + i), 1);
		else
			print_hexa(c);
		i++;
	}
}