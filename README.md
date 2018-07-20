# ft_printf

The versatility of the printf function in C represents a great exercise in programming. It one of the main computer science principles discovered in this project are variadic functions. The key to a successful ft_printf is a well-structured and good extensible code. Using jump tables and pointer functions will be essential in achieving this task.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

Tested on macOS High Sierra with gcc version 9.1.0

### Installing

1. `git clone https://github.com/nikrom17/ft_printf.git`
2. `cd ft_printf`
3. run `make` to compile the library and produce a `libftprintf.a` file
4. to make use of the library run `gcc -L. -lftprintf your_c_file.c` while in the `ft_printf/` directory
	* you can move the `libftprintf.a` file into your project repo **but** you must also copy over the `libft.h` and `ft_printf.h` header file
	* if you decide to move the library, run `gcc -L<path_to_library> -lftprintf your_c_file.c`
5. Makefile commands:
	* `re`, `clean`, `fclean`, and `all`

## Authors

**Nik Roman**
