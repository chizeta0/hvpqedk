
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

PyMethodDef Ktilde_methods[] = {
    { "Ktilde", Ktilde_wrapper, METH_VARARGS| METH_KEYWORDS,
      "Calculate Ktilde according to arXiv:1705.01775" },
    { NULL, NULL, 0, NULL }
};

