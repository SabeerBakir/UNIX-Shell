/*
	Name: Sabeer Bakir
	Student Number: 16333886
	Email: sabeer.bakir@ucdconnect.ie
*/

#ifndef HEADER_FILE
#define HEADER_FILE

// Funcition Declaration
char * getCommand(void);
char ** getArgs(char* line);
int run(char * args[], char* command);
char* currentTime(void);
void cd(char ** args);

#endif