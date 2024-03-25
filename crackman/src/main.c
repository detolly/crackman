
#include <Python.h>
#include <pythonrun.h>

#include <stdio.h>
#include <sys/prx.h>
#include <sys/timer.h>

#include <print.h>

int main()
{
	// sys_prx_load_module("libfs.sprx", 0, NULL);

	Py_SetPythonHome(L"/dev_hdd0/python");
	Py_Initialize();

	// PyRun_SimpleString("a = 5");
	PyRun_SimpleString("print(\"hello from python\")");
	// PyRun_SimpleString("import datetime\na = dir(datetime)");

	printf("PyErr_Occurred = ");
	print(PyErr_Occurred());
	
	PyObject *module = PyImport_AddModule("__main__");
	PyObject *a = PyObject_GetAttrString(module,"a");
	
	print(a);

	Py_DECREF(a);

	printf("exit program\n");


	return 0;
}