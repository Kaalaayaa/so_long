#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dest;

	dest = malloc(ft_strlen(str) + 1 * sizeof(char));
	if (!dest)
	{
		return (NULL);
	}
	ft_strlcpy(dest, str, ft_strlen(str)+ 1);
	return (dest);
}