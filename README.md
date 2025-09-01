# ft_printf - Custom Printf Implementation

<img align="right" height="150" src="https://media.giphy.com/media/aQwvKKi4Lv3t63nZl9/giphy.gif?cid=790b7611eyptck7j1xmf3rz338p5tjs6vzqzy7w38kxdfka2&ep=v1_gifs_search&rid=giphy.gif&ct=g"  />

## About this project

This project focuses on creating a custom function similar to `printf`, but with limited format specifiers. The main goal is to gain a deep understanding of how the `printf` function works internally. Additionally, this project emphasizes recursive thinking and further develops logical problem-solving abilities.

## Supported Format Specifiers

The `ft_printf` function supports the following format specifiers:

| Specifier | Description | Example |
|-----------|-------------|---------|
| `%c` | Print a single character | `ft_printf("%c", 'A')` → A |
| `%s` | Print a string | `ft_printf("%s", "Hello")` → Hello |
| `%p` | Print a pointer address | `ft_printf("%p", ptr)` → 0x7fff5fbff7ac |
| `%d` | Print a signed decimal integer | `ft_printf("%d", 42)` → 42 |
| `%i` | Print a signed decimal integer | `ft_printf("%i", -42)` → -42 |
| `%u` | Print an unsigned decimal integer | `ft_printf("%u", 42U)` → 42 |
| `%x` | Print a hexadecimal (lowercase) | `ft_printf("%x", 255)` → ff |
| `%X` | Print a hexadecimal (uppercase) | `ft_printf("%X", 255)` → FF |
| `%%` | Print a literal percent sign | `ft_printf("%%")` → % |

## Building the Project

### Prerequisites
- GCC compiler
- Make utility

### Compilation
```bash
cd ft_printf
make
```

This will create a static library `libftprintf.a` that you can link with your programs.

### Clean up
```bash
make clean    # Remove object files
make fclean   # Remove object files and library
make re       # Clean and rebuild
```

## Usage Example

Here's a simple example of how to use `ft_printf`:

```c
#include "ft_printf/ft_printf.h"

int main(void)
{
    int num = 42;
    char *str = "World";
    void *ptr = &num;
    
    // Basic usage examples
    ft_printf("Hello %s!\n", str);                    // Hello World!
    ft_printf("Number: %d\n", num);                   // Number: 42
    ft_printf("Character: %c\n", 'A');                // Character: A
    ft_printf("Hex (lower): %x\n", 255);              // Hex (lower): ff
    ft_printf("Hex (upper): %X\n", 255);              // Hex (upper): FF
    ft_printf("Pointer: %p\n", ptr);                  // Pointer: 0x7fff5fbff7ac
    ft_printf("Unsigned: %u\n", 4294967295U);         // Unsigned: 4294967295
    ft_printf("Percent sign: %%\n");                  // Percent sign: %
    
    return (0);
}
```

### Compilation with your program
```bash
gcc -Wall -Wextra -Werror main.c ft_printf/libftprintf.a -o my_program
```

## Project Structure

```
.
├── README.md
└── ft_printf/
    ├── Makefile          # Build configuration
    ├── ft_printf.h       # Header file with function declarations
    ├── ft_printf.c       # Main printf implementation
    ├── ft_putchar.c      # Character output function
    ├── ft_putnbr.c       # Number output functions
    ├── ft_putptr.c       # Pointer and hexadecimal output functions
    └── ft_putstr.c       # String output function
```

## Function Details

### Core Functions

- **`ft_printf(const char *format, ...)`**: Main function that mimics printf behavior
- **`ft_putchar(int c)`**: Outputs a single character
- **`ft_puts(const char *s)`**: Outputs a string (handles NULL)
- **`ft_putnbr(int nbr, int l)`**: Outputs signed integers recursively
- **`ft_putnbr_unsigned(unsigned long long int nbr, int l)`**: Outputs unsigned integers
- **`ft_putptr(unsigned long int tmp, int l)`**: Outputs pointer addresses
- **`ft_itoh_l(unsigned long long int tmp, int l)`**: Converts to lowercase hexadecimal
- **`ft_itoh_u(unsigned long long int tmp, int l)`**: Converts to uppercase hexadecimal

### Return Value

All functions return the number of characters printed, just like the standard `printf`.

## Special Cases Handled

- **NULL strings**: `ft_printf("%s", NULL)` prints `(null)`
- **NULL pointers**: `ft_printf("%p", NULL)` prints `(nil)`
- **Negative numbers**: Properly handled with sign display
- **Zero values**: Correctly formatted for all specifiers

## Implementation Notes

- Uses recursive algorithms for number and hexadecimal conversions
- Implements variadic functions using `stdarg.h`
- Memory-efficient approach without using standard library functions like `malloc`
- Follows 42 School coding standards and norminette guidelines

## Limitations

This implementation does **not** support:
- Field width specifiers (e.g., `%10d`)
- Precision specifiers (e.g., `%.2f`)
- Flags like `#`, `+`, `-`, ` ` (space), `0`
- Floating-point numbers (`%f`, `%e`, `%g`)
- Long modifiers (`%ld`, `%lx`, etc.)

## Educational Value

This project helps understand:
- Variadic functions in C
- Recursive programming techniques
- Character-by-character output handling
- Type conversions and formatting
- Memory management without dynamic allocation
