#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	*u1;
	unsigned char	*u2;

	i = 0;
	u1 = (unsigned char *)s1;
	u2 = (unsigned char *)s2;
	while (u2[i])
	{
		if (u1[i] != u2[i])
			return ((u1[i] - u2[i]));
		i++;
	}
	if (u1[i])
		return (u1[i]);
	return (0);
}

void	print_argv(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < i)
		{
			if (ft_strcmp(argv[i], argv[j]) < 0)
			{
				tmp = argv[i];
				argv[i] = argv[j];
				argv[j] = tmp;
			}
			j++;
		}
		i++;
	}
	print_argv(argc, argv);
	return (0);
}