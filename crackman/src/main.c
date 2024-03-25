
#include <Python.h>
#include "pythonrun.h"

#include <stdio.h>
#include <sys/prx.h>

// SYS_MODULE_INFO(crackman, 0, 1, 1);
// SYS_MODULE_START(start);
// SYS_MODULE_STOP(stop);
// SYS_MODULE_EXIT(stop);

// void __exit_user_prx_modules()
// {

// };
// void __fini()
// {

// };
// void _exit()
// {

// };

#include <sys/timer.h>
#include <print.h>

int main()
{
	sys_prx_load_module("libfs.sprx", 0, NULL);

	Py_SetPythonHome(L"/dev_hdd0/python/lib");
	Py_Initialize();

	PyRun_SimpleString("with open('test.txt', 'w+') as f:\n\tf.write('greetings')\n\n");
	
	PyObject *module = PyImport_AddModule("__main__");
	PyObject *a = PyObject_GetAttrString(module,"a");
	
	print(a);

	Py_DECREF(a);
	Py_DECREF(module);

	printf("exit program\n");


	return 0;
}