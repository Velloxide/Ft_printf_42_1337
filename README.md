*This project has been created as part of the 42 curriculum by saboutay.*

# ft_printf

## Description

ft_printf is a recode of the C `printf()` function, built as a static library (`libftprintf.a`).
The goal is to learn how variadic functions work in C (`va_list`, `va_start`, `va_arg`, `va_end`).

The prototype is:

```c
int	ft_printf(const char *format, ...);
```

It returns the number of printed characters, or `-1` on error.

**Mandatory conversions:** `c` `s` `p` `d` `i` `u` `x` `X` `%`

**Bonus:** flags `-` `0` `.` `#` `+` and space, plus the minimum field width.

## Instructions

```bash
make          # builds libftprintf.a (mandatory)
make bonus    # builds libftprintf.a (with bonus)
make clean    # removes object files
make fclean   # removes object files and libftprintf.a
make re       # fclean + all
```

Use it in your code:

```bash
cc main.c libftprintf.a -I includes -I libft
```

## Algorithm and data structure

The format string is read once, from left to right, with no buffer:

1. A normal character is written directly with `write`.
2. On `%`, the specification is parsed (flags, width, precision, type) and stored in a `t_spec` struct.
3. A dispatcher calls the right print function according to the type.
4. Each function returns the number of characters printed (or `-1` if `write` fails), and all counts are added to get the final return value.

`t_spec` holds everything about one conversion:

```c
typedef struct s_spec
{
	int		minus;
	int		zero;
	int		plus;
	int		space;
	int		hash;
	int		width;
	int		prec;
	char	type;
}	t_spec;
```

I chose a struct because it avoids global variables and keeps parsing separate from printing: the parser fills the struct, and the print functions only read it. Adding a new flag only touches the parser and the functions that use it. `prec` is `-1` when there is no precision, which is needed because `%.0d` and `%d` behave differently.

## Resources

- `man 3 printf`, `man 3 stdarg`
- [Linux man pages](https://man7.org/linux/man-pages/)
- [GNU C Library manual](https://www.gnu.org/software/libc/manual/)
- [cppreference](https://en.cppreference.com/)
- [codebrowser](https://codebrowser.dev/glibc)
- [geeksforgeeks](https://www.geeksforgeeks.org)
- [open-std.org](https://www.open-std.org/jtc1/sc22/wg14/www/projects#9899)

**Use of AI:** AI was used occasionally as a reference to clarify theoretical concepts. All the code, logic, testing, and debugging were done entirely by me.
