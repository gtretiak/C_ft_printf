#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main (void)
{
	int     res;
        int     result;
        char    *x = "\0";
        void    *ptr;
        char    *s;

        res = 0;
        result = 0;
        ptr = NULL;
        s = "gf\0hg\0";
        res = ft_printf("MINE\nText:ran%%%cdom\nDec_i:%i\nDec_d:%d\nChar:%c\n"
        "hex:%x\nHEX:%X\nUNSIGNED:%u\nAddress:%p\nAddress of the pointer that"
        "points to nowhere:%p\nStr:%s\nNULL-Str:%s\n", '!', -247483648, \
        -247483648, '\v', -147483648, -27483648, 0, &x, ptr, \
        "s%ctr", s);
        ft_printf("Written: %d characters\n\n\n", res);
        result = printf("ORIG\nText:ran%%%cdom\nDec_i:%i\nDec_d:%d\nChar:%c\n"
        "hex:%x\nHEX:%X\nUNSIGNED:%u\nAddress:%p\nAddress of the pointer that"
        "points to nowhere:%p\nStr:%s\nNULL-Str:%s\n", '!', -247483648, \
        -247483648, '\v', -147483648, -27483648, 0, &x, ptr, \
        "s%ctr", s);
        printf("Written: %d characters", result);
	return (0);
}
