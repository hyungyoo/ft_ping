#include "./include/ping.h"

void	*ft_memset(void *dest, int a, size_t len)
{
	unsigned int		i;
	unsigned char		c;
	char				*ptr;

	ptr = (char *)dest;
	i = 0;
	c = a;
	while (i != len)
	{
		ptr[i] = a;
		i++;
	}
	return (ptr);
}