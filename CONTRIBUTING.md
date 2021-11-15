# Contribution guidelines because why not

Just to standardise some things and make it clear


## File names

File names should use `PascalCase`.

Header files should always end with `.hpp` if it's C++, or `.h` if it's C.
Same goes for source files - `.cpp` if it's C++, or `.h` if it's C.

## Dependencies

***NO BOOST!*** I cannot stress this enough do *NOT* use boost it is bad and bloated.

Generally try to use maintained software.


## Naming conventions

Namespaces, funciton names, variables, and parameter names should use `dromedaryCase`.

Type definitions (e.g. classes and `typedef`s) should use `PascalCase`.


## Include guards

Use `#ifndef`-`#define` include guards, by using `UPPERCASE_SNAKE_CASE`.

The define names should be `CHLOVER_{MODULE}_{NAME}_{EXTENSION}`.
For example, if the module is engine and the file name is Assets.hpp, it should be `CHLOVER_ENGINE_ASSETS_HPP`.