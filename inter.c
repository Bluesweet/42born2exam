#include <unistd.h>

void	inter(char *s1, char *s2)
{
	int		i;
	while (*s1)
	{
		i = 0;
		while (s2[i])
		{
			if (*s1 == s2[i])
				write(1, s1, 1);
			i++;
		}
		s1++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 3)
		inter(av[1], av[2]);
	write(1, "\n", 1);
	return (0);	
}
