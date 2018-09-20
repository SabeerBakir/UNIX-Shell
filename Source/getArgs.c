/*
	Name: Sabeer Bakir
	Student Number: 16333886
	Email: sabeer.bakir@ucdconnect.ie
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

char** getArgs(char* line){
	
	char ** output_str = malloc(sizeof(char *));
	char* command = calloc(strlen(line), sizeof(char)); // create copy of command to make sure the original command is not edited
	strcpy(command, line);
	
	if(output_str == NULL){
		fprintf(stderr, "Error allocating memory");
		exit(EXIT_FAILURE);
	}
	
	// seperation of the arguments
	int count = 0;
	char* temp = strtok(command, " \n");
	while(temp != NULL){
		output_str[count] = temp;
		count++;
		output_str = realloc(output_str, (count + 1) * sizeof(char*));
		if(output_str == NULL){
			fprintf(stderr, "Error allocating memory");
		}
		temp = strtok(NULL, " \n");
	}
	
	output_str = realloc(output_str, (count + 1) * sizeof(char*));
	if(output_str == NULL){
		fprintf(stderr, "Error allocating memory");
	}
	output_str[count] = NULL; //set final argument as NULL such that execvp works correctly
	return output_str;
	
}