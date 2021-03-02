#include "../../includes/ultimate.h"

int isarg(char c)
{
    if ((c >= '0' && c <= '9') || c == '.')
        return (1);
    else
        return (0);
}

int countargs(char *s)
{
    int res;

    res = 0;

    while (*s)
    {
        while (!isarg(*s) && *s)
            s++;
        if (*s)
            res++;
        while (isarg(*s))
            s++;
    }
    return (res);
}