
#include <Python.h>

void print(PyObject *obj) 
{
    PyObject* repr = PyObject_Repr(obj);
    PyObject* str = PyUnicode_AsEncodedString(repr, "utf-8", "~E~");

    const char *bytes = PyBytes_AS_STRING(str);
    printf("%s\n", bytes);
    fflush(stdout);

    Py_XDECREF(repr);
    Py_XDECREF(str);
}