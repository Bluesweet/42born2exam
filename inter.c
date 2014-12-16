#include <unistd.h>

void	inter(char *s1, char *s2)
{
	int		i;
	int		j;
	int		k = 0;
	int		ctrl;
	while (s1[k] != '\0')
	{
		i = 0;
		while (s2[i] != '\0')
		{
			ctrl = 0;
			if (s1[k] == s2[i])
			{
				j = k - 1;
				while (j >= 0)
				{
					if (s1[j] == s1[k])
						ctrl += 1;
					j--;
				}
				j = i - 1;
				while (j >= 0)
				{
					if (s2[j] == s2[i])
						ctrl += 1;
					j--;
				}
				if (ctrl == 0)
					write(1, &s1[k], 1);
			}
			i++;
		}
		k++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 3)
		inter(av[1], av[2]);
	write(1, "\n", 1);
	return (0);	
}
