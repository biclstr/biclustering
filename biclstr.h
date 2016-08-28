#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <math.h>
#include <stdarg.h>
#include <limits.h>
#include "graph.h"
#include "fib.h"

/*#ifndef NULL
#define NULL 0
#endif*/


int cols;
int rows;
FILE * fpivot;
static int ** tpivot ;
static char ** tpivothead ;

int iARRAY_SIZE;