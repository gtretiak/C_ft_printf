# ft_printf

🎯 A custom implementation of the standard C `printf()` function — variadic, formatted output in your own library.

---

## 📚 Project Overview

The `ft_printf` project is part of the 42 school curriculum. It´s recreation one of the most fundamental and versatile functions in C: `printf()`.

## Concepts:
- Memory management
- Variadic functions
- String and character handling
- Modular and extensible C programming

The goal is to create a function that mimics the behavior of the standard `printf`, handling format specifiers and producing formatted output to the standard output (file descriptor 1).

---

## 🔧 Function Prototype

```c
int ft_printf(const char *format, ...);
```
## Supported Format Specifiers
- %c	Print a single character
- %s	Print a string
- %p	Print a pointer address in hexadecimal
- %d	Print a signed decimal integer
- %i	Print a signed decimal integer
- %u	Print an unsigned decimal integer
- %x	Print an unsigned hexadecimal number (lowercase)
- %X	Print an unsigned hexadecimal number (uppercase)
- %%	Print a literal percent sign
## Program Output:
Formatted text written to standard output (stdout)
## Required External Functions:
malloc, free, write, va_start, va_arg, va_copy, va_end

## Compilation
```
make
make clean
make fclean
make re
make test
```
