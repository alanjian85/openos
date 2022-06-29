# OpenOS
An Operating System that is already... opened

![strange](https://memeprod.ap-south-1.linodeobjects.com/user-gif-post/1636467937100.gif)

## Requirements

This simple operating system provides its own standard library, so it doesn't require any external compiler headers, except the following:
* `stdint.h` - The restriction of static integer sizes is helpful in interfaces related to low-level facilities
* `stddef.h` - For better portability, the use of `size_t` in `stddef.h` is allowed