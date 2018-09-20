/*
	Name: Sabeer Bakir
	Student Number: 16333886
	Email: sabeer.bakir@ucdconnect.ie
*/

#include <stdio.h>
#include <stdlib.h>

char * getCommand(void){
	// simple getline
	char* line = NULL;
	size_t len = 0;
	getline(&line, &len, stdin);
	return line;
}