#include <stdio.h>

void main()
{
    char c = 'A';
    char *c_ptr = &c;

    printf ("c=%c\nc_ptr=%p\n&c_ptr=%p\n*c_ptr=%c\n", c, c_ptr, &c_ptr, *c_ptr);

}