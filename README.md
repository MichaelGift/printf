# Custom Printf Implementation
This project is a custom implementation of the printf function in C programming language. It allows you to format and print various data types to the standard output or a custom output stream.

## Getting Started
- Prerequisites
To compile and run the custom printf implementation, you'll need:

A C compiler (e.g., gcc)
Standard C library (stdio.h, stdlib.h, stdarg.h)

- Compilation
You can compile the custom printf implementation using a C compiler. For example, with gcc:

```C
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c
```


- Usage
The custom printf function is used just like the standard printf function
```C
#include "main.h"


int main() {
    _printf("Hello, %s! The answer is %d\n", "World", 42);
    return 0;
}
```
The above code will print:

```C
Hello, World! The answer is 42
```


## Supported Format Specifiers
The custom printf implementation supports the following format specifiers:

- %d, %i: Signed integers
- %u: Unsigned integers
- %c: Characters
- %s: Strings
- %o: Octal
- %x, %X: Hexadecimal
- %p: Pointers
- %b: Binary
- %r: Reverse string
- %R: ROT13 encoding
- %S: Custom conversion for 'S'

## Flags
The custom printf supports the following flags:

- +: Forces the output to be signed for signed numbers.
- -: Left-justifies the output.
- 0: Pads numbers with leading zeros.
- (space): Pads positive numbers with leading spaces.


## Acknowledgments
This custom printf implementation was created as a project for learning purposes. It is not a full replacement for the standard printf function and may not cover all edge cases and features.

## License
This project is licensed under the MIT License. Feel free to use and modify it as you see fit.
