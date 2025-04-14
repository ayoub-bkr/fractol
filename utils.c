#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (s1[i] > s2[i] || s1[i] < s2[i])
			return (1);
		i++;
	}
	return (0);
}