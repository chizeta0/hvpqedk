
/*************************************************************************************
 *  File: kernel.c
 *  Copyright (c) 2023 Christian Zimmermann. All rights reserved
 *
 *************************************************************************************
 *
 *  Python module 'hvpqedk'
 *
 *************************************************************************************/

#include <Python.h>
#include "kernel_wrapper.h"

static struct PyModuleDef hvpqedk_mod = {
    PyModuleDef_HEAD_INIT,
    "hvpqedk",
    NULL,
    -1,
    hvpqedk_kernel_methods
};

PyMODINIT_FUNC PyInit_hvpqedk(void)
{
    return PyModule_Create(&hvpqedk_mod);
}

