
C library that provides functions to calculate the QED kernel needed in the calculation of the HVP contribution to the anamalous magnetic moment of the muon. This library also provides python bindings. We are using the definitions and conventions of `arXiv:1705.01775`

# Install instructions

## C/C++

You can build the shared library and link against it or just copy the files in `src/` into your own project. If you want to build the library, do the following:

```bash
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX:PATH=<install path of your choice> ..
make install
````

In your install directory you should now have a sub-directory `include/hvpqedk` with the header file `kernel.h` and a sub-directory `lib` containing the shared object `libhvpqedk.so`. Don't forget to adapt your `LD_LIBRARY_PATH`. The link against the library is done by:

```c
#include "hvpqedk/kernel.h"
```

in your source code and adding the compile flag `-lhvpqedk`. It might be neccessary to also specify the path to the library using `-L/...` and `-I/...`, respectively.

## Python3

It is recommended to install the library with pip in a virtual environment:

```bash
pip install -e .
```

The module can be simply loaded in your python script:

```py
import hvpqedk
```