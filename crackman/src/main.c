
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

int stop(void)
{
	return 0;
}

int start(size_t argc, void* argp)
{
	//sys_prx_load_module(SYS_APP_HOME "/libfs.sprx", 0, NULL);

	return 0;
}

#include <sys/timer.h>

int main()
{
	puts("greetings");
	Py_SetPythonHome(L"/dev_hdd0/python/lib");
	Py_Initialize();
	puts("after py_initialize");

	PyRun_SimpleString("a = 5");
	
	PyObject *module = PyImport_AddModule("__main__");
	PyObject *a = PyObject_GetAttrString(module,"a");
	printf("a = %d\n", PyLong_AsLong(a));
	Py_DECREF(a);

	printf("exit program\n");


	return 0;
}