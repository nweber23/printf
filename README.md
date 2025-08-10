# ft_printf

A custom implementation of the C standard library `printf` function, developed as part of the 42 School curriculum.

## Overview

This project recreates the behavior of `printf`, supporting various format specifiers and returning the number of characters printed. The implementation focuses on proper memory management, error handling, and cross-platform compatibility.

## Features

### Supported Format Specifiers
- `%c` - Single character
- `%s` - String of characters
- `%d` / `%i` - Signed decimal integer
- `%u` - Unsigned decimal integer
- `%x` - Hexadecimal (lowercase)
- `%X` - Hexadecimal (uppercase)
- `%p` - Pointer address
- `%%` - Literal percent sign

### Cross-Platform Support
- **Linux**: NULL pointers display as `(nil)`
- **macOS**: NULL pointers display as `0x0`

## Project Structure

```
.
├── Makefile
├── includes/
│   └── ft_printf.h
├── srcs/
│   ├── ft_printf.c      # Main printf implementation
│   ├── putnbr.c         # Numeric conversion functions
│   └── putstr.c         # String and character output functions
└── libft/               # Required libft library (dependency)
```

## Compilation

### Prerequisites
- A `libft` library in the `./libft/` directory
- GCC or compatible C compiler

### Build Commands
```bash
make            # Compile the library
make clean      # Remove object files
make fclean     # Remove object files and library
make re         # Rebuild from scratch
```

The compilation produces `libftprintf.a` which can be linked to your projects.

## Usage

### Include in your project
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s! Number: %d\n", "World", 42);
    return (0);
}
```

### Compile your program
```bash
gcc -Wall -Wextra -Werror your_program.c -L. -lftprintf
```

## Implementation Details

- **Error Handling**: All functions return -1 on write errors, following standard printf behavior
- **Memory Safety**: No dynamic allocation, uses stack-based recursion for number conversion
- **Performance**: Optimized recursive algorithms for numeric base conversions
- **Standards Compliance**: Follows 42 School coding standards (Norminette)

## Return Value

Returns the number of characters printed, or -1 if an error occurs during output.

## Author

**nweber** - 42 Heilbronn Student
