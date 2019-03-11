#pragma once


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define memcpy2Host(var, src, size) { \
	strncpy((char *) var.arr, src, size); \
    var.len = strlen((char *) var.arr); \
}
#define Memcpy2Local(str,varchar) { \
	memset(str, 0x00, sizeof(str)); \
	strncpy(str, (const char*)varchar.arr, varchar.len); \
}

/* CLEAR VARCHAR MACRO */
#define MemsetHost(x) { \
	memset((char *)&(x).arr, 0x00, sizeof(x.arr)); \
	x.len = 0; \
}


#define STRCPY(x,y) {memset(x, 0x00, sizeof(x)); strncpy(x, y, sizeof(x)-1);}

int testDate();
int sample1();
