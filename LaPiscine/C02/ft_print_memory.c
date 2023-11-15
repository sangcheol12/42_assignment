#include <unistd.h>

void	print_hexa(unsigned char *addr)
{
	char	c[2];
	int		i;

	i = 0;
	while (i < 16)
	{
		c[0] = "0123456789abcdef"[*(addr + i) / 16];
		c[1] = "0123456789abcdef"[*(addr + i) % 16];
		write(1, c, 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		if (*(addr + i) == 0)
			break ;
		i++;
	}
	while (++i < 16)
	{	
		write(1, "  ", 2);
		if (i % 2 == 1)
			write(1, " ", 1);
	}
}

void	print_address(unsigned long addr)
{
	char	str[16];
	int		i;
	char	c;

	i = 15;
	while (i >= 0)
	{
		if (addr > 15)
			c = addr % 16;
		else
			c = addr;
		if (c < 10)
			str[i] = c + '0';
		else
			str[i] = (c - 10) + 'a';
		addr /= 16;
		i--;
	}
	write(1, str, 16);
}

void	print_value(unsigned char *addr)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (!(*(addr + i) >= 32 && *(addr + i) <= 127))
			write(1, ".", 1);
		else
			write(1, (addr + i), 1);
		if (*(addr + i) == 0)
			break ;
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*addr_c;

	i = 0;
	addr_c = (unsigned char *)addr;
	while (i <= size)
	{
		print_address((unsigned long)addr_c + i);
		write(1, ": ", 2);
		print_hexa((addr_c + i));
		print_value(addr_c + i);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}