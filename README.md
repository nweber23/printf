*This project has been created as part of the 42 curriculum by nweber.*

# ft_printf

## Description

`ft_printf` is a recreation of the C standard library's `printf` function.
The goal of the project is to understand and reimplement a variadic
function from scratch: parsing a format string at runtime, pulling
arguments of varying types off a `va_list`, and writing formatted output
with `write(2)` instead of the buffered `stdio` implementation glibc uses.

The mandatory part supports the conversions `%c %s %p %d %i %u %x %X %%`.
The bonus part extends the parser to also understand field width, the
flags `- 0 + # ` (space) `, and a precision specifier, in any combination,
for every supported conversion — matching the behaviour of the real
`printf` for those cases.

## Instructions

### Build

```sh
make        # builds libftprintf.a with the mandatory conversions only
make bonus  # builds libftprintf.a with flags/width/precision support
```

Both rules produce the same archive name, `libftprintf.a`, at the root of
the repository, built from `srcs/*.c` and the bundled `libft` (in
`libft/`, compiled through its own Makefile as a first step). `make clean`
removes object files, `make fclean` also removes the archive, and `make
re` rebuilds from scratch.

### Use in a project

```sh
cc your_file.c -I./includes -L. -lftprintf -o your_program
```

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("%-10s|%05d|%#x\n", "hi", 42, 255);
    return (0);
}
```

### Run the (ungraded) regression tests

A small harness under `tests/` compares `ft_printf`'s output and return
value against `snprintf` for every flag/width/precision combination. It
is not required for evaluation but is useful while working on the
project or during a defence:

```sh
make bonus
cd tests && make run
```

## Algorithm and data structures

Formatting is split into three stages, one function group per stage:

1. **Parsing** (`parse_bonus.c`) walks the characters right after a `%`
   and fills a `t_format` struct — one field per flag, plus `width` and
   `precision` — before finally reading the conversion letter. Keeping
   every parsed property in a single struct means the rest of the
   pipeline never re-parses the format string; it only reads flags off
   that struct.
2. **Building** (`numeric_bonus.c`, `handlers_bonus.c`) turns the current
   variadic argument into two independently-computed strings: a
   *prefix* (a sign, a space, or a `0x`/`0X` base prefix) and the
   *digits*/content itself, already left-padded with zeros if a
   precision was requested. Separating prefix from digits is what makes
   zero-padding correct: `%06d` on `-42` has to print `-00042`, i.e. the
   zeros belong **between** the sign and the digits, not before the
   sign.
3. **Output** (`output_bonus.c`) is a single generic function,
   `output_padded`, that takes that prefix/digits pair plus the format
   struct and decides how to pad to the requested width: spaces on the
   right for `-`, zeros between prefix and digits for `0` (only for
   numeric conversions, and only when no precision was given, exactly
   like glibc), or spaces on the left otherwise. Every conversion —
   `%d`, `%x`, `%s`, `%c`, `%p` — funnels through this same function,
   which is what keeps width/flag handling consistent across
   conversions instead of duplicated per conversion.

Numbers are converted to strings with a small manual base-conversion
routine (`get_digits`) rather than reusing `ft_itoa`, because `ft_itoa`
only handles `int`, while `%x`/`%X`/`%p`/`%u` need to build strings from
`unsigned long` values in base 10 or 16. Intermediate strings are
heap-allocated (`malloc`/`free` are explicitly allowed external
functions for this project) so that width padding can be computed from
a known length instead of writing to `fd 1` character-by-character and
guessing the total size in advance.

## Resources

- [`man 3 printf`](https://man7.org/linux/man-pages/man3/printf.3.html) —
  the reference conversion/flag/width/precision semantics this project
  is validated against.
- [C99 standard, §7.19.6.1 (`fprintf`)](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf) —
  precise rules for how flags interact with precision and width.
- 42's own `ft_printf` subject PDF, for the list of required
  conversions and the bonus flag list.

### AI usage

Claude (Anthropic, Sonnet 5, via Claude Code) was used to:

- Design the bonus parsing/formatting architecture (the
  parse → build → pad-and-write pipeline described above).
- Write the bonus source files (`srcs/*_bonus.c`,
  `includes/ft_printf_bonus.h`) and the `bonus` Makefile rule.
- Write the regression test harness in `tests/` that compares output
  against `snprintf`, and use it (plus `valgrind`) to verify the
  implementation before committing.
- Write this README.

The mandatory `ft_printf` implementation (`srcs/ft_printf.c`,
`srcs/putnbr.c`, `srcs/putstr.c`) and the `libft` library predate this
AI-assisted session and were written by hand.
