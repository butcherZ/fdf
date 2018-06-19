#include "libft.h
	"
int	*intdup(int const *src, size_t len)
{
	int *p;

	p = malloc(len * sizeof(int));
	ft_memcpy(p, src, len * sizeof(int));

	return (p);
}
