#include "fil_libft.h"

size_t  ft_strlen(char const *s)
{
    size_t count;

    count = 0;
    while (s[count] != '\0')
    {
        count += 1;
    }
    return (count);
}
