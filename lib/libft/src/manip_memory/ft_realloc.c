
#include "libft.h"

void *ft_realloc(void *ptr, size_t old_size, size_t size)
{
    void *new_ptr = malloc(size);
    ft_bzero(new_ptr, size);
    if (ptr)
	{
        ft_memcpy(new_ptr, ptr, size, old_size);
        free(ptr);
    }
    return new_ptr;
}
