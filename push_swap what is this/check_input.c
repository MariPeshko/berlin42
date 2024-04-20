#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#include <stdio.h>

static void print_error(void)
{
    printf(2, "Error\n");
    exit(1);
}