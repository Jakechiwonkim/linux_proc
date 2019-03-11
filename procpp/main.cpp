//#include <stdio.h>

#include "main.h"

int main() {
	printf("-----------------------------------------------------\n");
	printf("  Pro*C Test ! \n");
	printf("-----------------------------------------------------\n");


/* Connect to ORACLE--
 * Copy the username into the VARCHAR.
 * Set the length component of the VARCHAR. */
	ORA_CONNECT("SCOTT", "TIGER", "XE");

	testDate();

	sample1();


	ORA_COMMIT();

#ifndef __LINUX__
	system("pause");
#endif

	return 0;
}