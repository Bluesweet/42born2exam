#include <unistd.h>

int		ft_rotone(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 65 && str[i] < 90) || (str[i] >= 97 && str[i] < 122))
			str[i] += 1;
		else if (str[i] == 90)
			str[i] = 65;
		else if (str[i] == 122)
			str[i] = 97;
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	ft_rotone(av[1]);
	return (0);
}
