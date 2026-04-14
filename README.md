# Libft

Libft is a custom C library developed for the 42 curriculum. It provides a clean set of
standard-like helpers for strings, memory, files, and linked lists.

## Features

- Character classification and conversion functions
- Memory and string utilities
- Allocation helpers
- File descriptor output helpers
- Singly linked list helpers

## Build

Build the project with:

```bash
make
```

This produces:

- `libft.a`
- `libft.dylib` on macOS
- `libft.so` on Linux

Useful targets:

```bash
make clean
make fclean
make re
make docs
```

## Documentation

The project documentation is generated with Doxygen. The local HTML output is written to
`docs/html/index.html`.

## Usage

Include the public header in your project:

```c
#include "libft.h"
```

Then compile and link against the library file that matches your platform.

## Project structure

```text
includes/   Public headers
src/        Library source files
docs/       Generated Doxygen output
Makefile    Build and documentation targets
Doxyfile    Doxygen configuration
```
