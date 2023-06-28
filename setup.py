#!/usr/bin/env python

import setuptools
from distutils.core import setup, Extension
import sysconfig

libname = 'hvpqedk'
author = 'Christian Zimmermann'
author_email = 'christian.zimmermann@univ-amu.fr'
version = '0.0.1'

inc_dirs = ['hvpqedk/kernel/src','src']
lib_dirs = []
extra_compile_args = sysconfig.get_config_var('CFLAGS').split()

extension_args = dict(
    language = 'c',
    include_dirs = inc_dirs,
    libraries = [],
    library_dirs = lib_dirs,
    extra_compile_args = extra_compile_args,
)

if __name__ == "__main__":

    setup(
        name = libname,
        packages = setuptools.find_packages(),
        version = version,
        include_dirs = inc_dirs,
        ext_modules = [Extension(
            'hvpqedk',
            [
                'src/kernel.c',
                'hvpqedk/kernel/src/kernel_wrapper.c',
                'hvpqedk/kernel/kernel.c'
            ],
            **extension_args
        )],
        author = author,
        author_email = author_email,
    )
