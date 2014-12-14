#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*dup;

	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (dup == NULL)
		return (NULL);
	else
	{
		while (s && *s)
			*dup++ = *s++;
		*dup = '\0';
	}
	return (dup);
}
