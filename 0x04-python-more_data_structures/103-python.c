#include <Python.h>

/**
 * print_python_list - program that prints that print some basic info about Python lists 
* @PyObject: python object printed
 * @*p: python lists
#include <Python.h>

void print_python_list(PyObject *p)
 {
    if (!PyList_Check(p))
 {
        fprintf(stderr, "Invalid list object\n");
        return;
    }

    Py_ssize_t size = PyObject_Length(p);
    Py_ssize_t allocated = ((PyListObject *)p)->allocated;

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %zd\n", size);
    printf("[*] Allocated = %zd\n", allocated);

    for (Py_ssize_t i = 0; i < size; i++) 
{
        PyObject *item = PyList_GET_ITEM(p, i);
        const char *type = item->ob_type->tp_name;
        printf("Element %zd: %s\n", i, type);
    }
}

void print_python_bytes(PyObject *p)
 {
    if (!PyBytes_Check(p)) {
        fprintf(stderr, "Invalid bytes object\n");
        return;
    }

    Py_ssize_t size = PyObject_Length(p);
    Py_ssize_t max_display = (size > 10) ? 10 : size;

    printf("[.] bytes object info\n");
    printf("  Size: %zd\n", size);
    printf("  trying string: %s\n", PyUnicode_AsUTF8(PyObject_Str(p)));

    printf("  first %zd bytes: ", max_display);
    for (Py_ssize_t i = 0; i < max_display; i++)
 {
        printf("%02x", (unsigned char)PyBytes_AS_STRING(p)[i]);
        if (i < max_display - 1) {
            printf(" ");
        }
    }
    printf("\n");
}
