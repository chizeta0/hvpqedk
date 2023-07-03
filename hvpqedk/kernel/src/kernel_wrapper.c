
/*************************************************************************************
 *  File: kernel_wrapper.c
 *  Copyright (c) 2023 Christian Zimmermann. All rights reserved
 *
 *************************************************************************************/

#include "kernel_wrapper.h"
#include "kernel.h"
#include "rratio.h"

PyObject* Ktilde_wrapper(PyObject* self, PyObject* args, PyObject* kwds)
{
    static char* kwlist[] = { "t", "m_mu" , NULL };
    double t;
    double m_mu;
    if(!PyArg_ParseTupleAndKeywords(args, kwds, "dd|", kwlist, &t, &m_mu)){
	return NULL;
    }

    const double ret = Ktilde(t, m_mu);
    
    return PyFloat_FromDouble(ret);
}

PyObject* mu2_ft_wrapper(PyObject* self, PyObject* args, PyObject* kwds)
{
    static char* kwlist[] = { "t", "m_mu" , NULL };
    double t;
    double m_mu;
    if(!PyArg_ParseTupleAndKeywords(args, kwds, "dd|", kwlist, &t, &m_mu)){
	return NULL;
    }

    const double ret = mu2_ft(t, m_mu);

    return PyFloat_FromDouble(ret);
}

PyObject* mu2_ft_small_wrapper(PyObject* self, PyObject* args, PyObject* kwds)
{
    static char* kwlist[] = { "t_hat", NULL };
    double t_hat;
    if(!PyArg_ParseTupleAndKeywords(args, kwds, "d|", kwlist, &t_hat)){
	return NULL;
    }

    const double ret = mu2_ft_small(t_hat);

    return PyFloat_FromDouble(ret);
}

PyObject* mu2_ft_large_wrapper(PyObject* self, PyObject* args, PyObject* kwds)
{
    static char* kwlist[] = { "t_hat", NULL };
    double t_hat;
    if(!PyArg_ParseTupleAndKeywords(args, kwds, "d|", kwlist, &t_hat)){
	return NULL;
    }

    const double ret = mu2_ft_large(t_hat);

    return PyFloat_FromDouble(ret);
}

PyObject* f_BW_wrapper(PyObject* self, PyObject* args, PyObject* kwds)
{
    static char* kwlist[] = { "s", "C", "M", "Gamma", NULL };
    double s, C, M, Gamma;
    if(!PyArg_ParseTupleAndKeywords(args, kwds, "dddd|", kwlist, &s, &C, &M, &Gamma)){
	return NULL;
    }

    const double retx = f_BW(s, C, M, Gamma);

    return PyFloat_FromDouble(retx);
}

PyObject* Rratio_wrapper(PyObject* self, PyObject* args, PyObject* kwds)
{
    static char* kwlist[] = { "s", NULL };
    double s;
    if(!PyArg_ParseTupleAndKeywords(args, kwds, "d|", kwlist, &s)){
	return NULL;
    }

    const double ret = Rratio(s);

    return PyFloat_FromDouble(ret);
}


PyDoc_STRVAR(hvpqedk_Ktilde_doc,
	     "Ktilde($module, t, m_mu, /)\n--\n\n"
	     "Calculate Ktilde according to arXiv:1705.01775 using expansions of ftilde, see eqs (58), (60)");

PyDoc_STRVAR(hvpqedk_mu2_ft_doc,
	     "mu2_ft($module, t, m_mu, /)\n--\n\n"
	     "Calculate f tilde according to arXiv:1705.01775 using expansions (58) or (60)");

PyDoc_STRVAR(hvpqedk_mu2_ft_small_doc,
	     "mu2_ft_small($module, t_hat, /)\n--\n\n"
	     "Calculate expansion of ftilde according to arXiv:1705.01775, eq (58)");

PyDoc_STRVAR(hvpqedk_mu2_ft_large_doc,
	     "mu2_ft_large($module, t_hat, /)\n--\n\n"
	     "Calculate expansion of ftilde according to arXiv:1705.01775, eq (60)");

PyDoc_STRVAR(hvpqedk_f_BW_doc,
	     "hvpqedk_f_BW($module, s, C, M, Gamma, /)\n--\n\n"
	     "Calculate the Breit-Wigner function");

PyDoc_STRVAR(hvpqedk_Rratio_doc,
	     "hvpqedk_Rratio($module, s, /)\n--\n\n"
	     "Calculate the R-ratio according to eq (18) in arXiv:1107.4388");

PyMethodDef hvpqedk_kernel_methods[] = {
    { "Ktilde", Ktilde_wrapper, METH_VARARGS| METH_KEYWORDS, hvpqedk_Ktilde_doc },
    { "mu2_ft", mu2_ft_wrapper, METH_VARARGS| METH_KEYWORDS, hvpqedk_mu2_ft_doc },
    { "mu2_ft_small", mu2_ft_small_wrapper, METH_VARARGS| METH_KEYWORDS, hvpqedk_mu2_ft_small_doc },
    { "mu2_ft_large", mu2_ft_large_wrapper, METH_VARARGS| METH_KEYWORDS, hvpqedk_mu2_ft_large_doc },
    { "f_BW", f_BW_wrapper, METH_VARARGS| METH_KEYWORDS, hvpqedk_f_BW_doc },
    { "Rratio", Rratio_wrapper, METH_VARARGS| METH_KEYWORDS, hvpqedk_Rratio_doc },
    { NULL, NULL, 0, NULL }
};

