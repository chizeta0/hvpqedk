
#include "kernel_wrapper.h"
#include "kernel.h"

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

PyMethodDef hvpqedk_kernel_methods[] = {
    { "Ktilde", Ktilde_wrapper, METH_VARARGS| METH_KEYWORDS,
      "Calculate Ktilde according to arXiv:1705.01775 using expansions of ftilde, see eqs (58), (60)" },
    { "mu2_ft", mu2_ft_wrapper, METH_VARARGS| METH_KEYWORDS,
      "Calculate f tilde according to arXiv:1705.01775 using expansions (58) or (60)" },
    { "mu2_ft_small", mu2_ft_small_wrapper, METH_VARARGS| METH_KEYWORDS,
      "Calculate expansion of ftilde according to arXiv:1705.01775, eq (58)" },
    { "mu2_ft_large", mu2_ft_large_wrapper, METH_VARARGS| METH_KEYWORDS,
      "Calculate expansion of ftilde according to arXiv:1705.01775, eq (60)" },
    { NULL, NULL, 0, NULL }
};

