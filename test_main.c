#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main (void)
{
    int	ret1;
    int	ret2;
    void *ptr = (void *)0x12345678;

    // Test 1: Simple string
    ret1 = ft_printf("FT: Hello, %s!\n", "world");
    ret2 = printf("OR: Hello, %s!\n", "world");
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    // Test 2: Character and integer
    ret1 = ft_printf("FT: Char: %c, Int: %d\n", 'A', 42);
    ret2 = printf("OR: Char: %c, Int: %d\n", 'A', 42);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    // Test 3: Hexadecimal
    ret1 = ft_printf("FT: Hex: %x %X\n", 255, 255);
    ret2 = printf("OR: Hex: %x %X\n", 255, 255);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    // Test 4: Pointer
    ret1 = ft_printf("FT: Pointer: %p\n", ptr);
    ret2 = printf("OR: Pointer: %p\n", ptr);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    // Test 5: Unsigned and negative
    ret1 = ft_printf("FT: Unsigned: %u, Negative: %d\n", UINT_MAX, -123);
    ret2 = printf("OR: Unsigned: %u, Negative: %d\n", UINT_MAX, -123);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    // Test 6: Percent sign
    ret1 = ft_printf("FT: 100%% done!\n");
    ret2 = printf("OR: 100%% done!\n");
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    return (0);
}
