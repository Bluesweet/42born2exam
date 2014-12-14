#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void    ft_putchar(char c)
{
	write(1, &c, 1);
}

int     ft_strlen(char *str)
{
	int     count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

void    ft_putstr(char *str)
{
	int     count;

	count = 0;
	while (str[count] != '\0')
	{
		ft_putchar(str[count]);
		count++;
	}
}

int     *recup_size(char *str)
{
	int     count;
	int     *xy;
	int     fd;
	char    buff[1024];
	int     nb_read;

	xy = malloc(2 * sizeof(*xy));
	xy[0] = 0;
	xy[1] = 0;
	if ((fd = open(str, O_RDONLY)) < 0)
		return (0);
	while ((nb_read = read(fd, buff, 1024)))
	{
		count = 0;
		while (count < nb_read)
		{
			if (xy[0] == 0 && buff[count] == '\n')
				xy[0] = count;
			if (buff[count] == '\n')
				xy[1]++;
			count++;
		}
	}
	return (xy);
}

void    aff_map(char **map)
{
	int     count;

	count = 0;
	while (map[count + 1] != 0)
	{
		ft_putstr(map[count]);
		ft_putchar('\n');
		count++;
	}
	ft_putstr(map[count]);
}

char    **recup_map(char *str, int *xy)
{
	int     fd;
	int     count;
	char    **map;

	count = 0;
	map = malloc((xy[1] + 1) * sizeof(*map));
	fd = open(str, O_RDONLY);
	while (count < xy[1])
	{
		map[count] = malloc((xy[0] + 1) * sizeof(*map));
		read(fd, map[count], xy[0] + 1);
		map[count][xy[0]] = '\0';
		count++;
	}
	map[count] = 0;
	close(fd);
	return (map);
}

void    change(char ile, char **map, int x, int y)
{
	map[y][x] = ile;
	if (((x - 1) >= 0) && (map[y][x - 1] == 'X'))
		change(ile, map, x - 1, y);
	if ((map[y][x + 1] != '\0') && (map[y][x + 1] == 'X'))
		change(ile, map, x + 1, y);
	if ((map[y + 1] != 0) && (map[y + 1][x] == 'X'))
		change(ile, map, x, y + 1);
	if (((y - 1) >= 0) && (map[y - 1][x] == 'X'))
		change(ile, map, x, y - 1);
}

void    check_map(char **map)
{
	int     x;
	int     y;
	char    ile;

	ile = '0';
	y = 0;
	while (map[y] != 0)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'X')
				change(ile++, map, x, y);
			x++;
		}
		y++;
	}
}

int     main(int ac, char **av)
{
	int     *xy;
	char    **map;

	if (ac == 2)
	{
		if ((xy = recup_size(av[1])))
		{
			map = recup_map(av[1], xy);
			if (map[0])
			{
				check_map(map);
				aff_map(map);
			}
		}
	}
	ft_putchar('\n');
	return (0);
}
