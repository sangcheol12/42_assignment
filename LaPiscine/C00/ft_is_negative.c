#include <unistd.h>

void	ft_is_negative(int n)
{
	char	pn[3];

	pn[0] = 'P';
	pn[1] = 'N';
	if (n >= 0)
	{
		write(1, pn, 1);
	}
	else
	{
		write(1, pn + 1, 1);
	}
}