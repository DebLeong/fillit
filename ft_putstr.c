#include "fil_libft.h"

void    ft_putstr(char const *s)
{
    if (s != NULL)
        write(1, s, (int)ft_strlen(s));
}
