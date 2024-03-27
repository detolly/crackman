
#include <Python.h>
#include <pythonrun.h>

#include <stdio.h>
#include <sys/timer.h>
#include <sys/prx.h>

#include <print.h>

SYS_MODULE_INFO(crackman, 0, 1, 1);
SYS_MODULE_START(main);
SYS_MODULE_STOP(stop);
SYS_MODULE_EXIT(stop);

int __exit_user_prx_modules() {}
int __fini() {}
int _exit() {}

int stop()
{
	return 0;
}

int main()
{
	// sys_prx_load_module("libfs.sprx", 0, NULL);

	Py_SetPythonHome(L"/dev_hdd0/python");
	Py_Initialize();

	// int ret = PyRun_SimpleString("def getnum():\n\treturn 20000");
	int ret = PyRun_SimpleString("with open('/dev_hdd0/python/run/test.txt', 'x') as f:\n\tf.write('greetings')\n\n");

	if (ret != 0) {
		printf("PyErr_Occurred = ");
		print(PyErr_Occurred());
	}

	// ret = PyRun_SimpleString("a = getnum()");
	
	// if (ret != 0) {
	// 	printf("PyErr_Occurred = ");
	// 	print(PyErr_Occurred());
	// }

	PyObject *module = PyImport_AddModule("__main__");
	PyObject *a = PyObject_GetAttrString(module,"a");
	
	print(a);

	Py_DECREF(a);

	printf("exit program\n");
	return 0;
}