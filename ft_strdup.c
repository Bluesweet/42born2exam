#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	char	*tmp;
	
	tmp = (char*)str;
	if (!str)
		return (0);
	while (*tmp)
		++tmp;
	return (tmp - str);
}

}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int	i = 0;
	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dup)
		return (NULL);
	else
	{
		while (s && s[i])
		{
			dup[i] = s[i];
			i++;
		}
		dup[i] = '\0';
	}
	return (dup);
}
