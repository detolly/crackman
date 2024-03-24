
#include "pythonrun.h"
#include <Python.h>

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

int main()
{
	puts("greetings");
	Py_Initialize();
	puts("after py_initialize");

	// PyRun_SimpleStringFlags("print(\"hello from python\")", NULL);

	return 0;
}