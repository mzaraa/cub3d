
#include "libft.h"

void *my_realloc(void *ptr, size_t size)
{
    void *new_ptr = malloc(size);
    if (ptr)
	{
        memcpy(new_ptr, ptr, size);
        free(ptr);
    }
    return new_ptr;
}
