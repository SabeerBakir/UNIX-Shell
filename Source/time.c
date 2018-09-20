/*
	Name: Sabeer Bakir
	Student Number: 16333886
	Email: sabeer.bakir@ucdconnect.ie
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* currentTime(void){
	time_t rawtime;
	struct tm * info;
	char* buf = calloc(20,sizeof(char));
	
	time(&rawtime);
	info = localtime(&rawtime);
	strftime(buf, 80, "[%d/%m %I:%M%p]", info); // time formatting

	return buf;
}
