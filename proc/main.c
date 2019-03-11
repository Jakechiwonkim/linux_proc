
#include "sample1.h"
int main(int argc, char *argv[]){

	
	oracle_connect("SCOTT", "TIGER" , "XE");
	
	toDate();
	
	emp_7900();
	
	
	disconnect();
	
	
	return 0;
}