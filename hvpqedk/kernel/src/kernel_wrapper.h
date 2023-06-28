
/*************************************************************************************
 *  File: kernel_wrapper.h
 *  Copyright (c) 2023 Christian Zimmermann. All rights reserved
 *
 *************************************************************************************
 *
 *  Python wrappers for hvpqedk kernel functions
 *
 *************************************************************************************/

#ifndef __python_hvpqedk_kernel_wrapper_h__
#define __python_hvpqedk_kernel_wrapper_h__

#include <Python.h>

extern PyObject* Ktilde_wrapper(PyObject* self, PyObject* args, PyObject* kwds);
extern PyObject* mu2_ft_wrapper(PyObject* self, PyObject* args, PyObject* kwds);
extern PyObject* mu2_ft_small_wrapper(PyObject* self, PyObject* args, PyObject* kwds);
extern PyObject* mu2_ft_large_wrapper(PyObject* self, PyObject* args, PyObject* kwds);

extern PyMethodDef hvpqedk_kernel_methods[];

#endif
