/*
	Name: Sabeer Bakir
	Student Number: 16333886
	Email: sabeer.bakir@ucdconnect.ie
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include "shell.h"

static void catch_function(int signo){
	//printf("Signal %d caught\n", signo);
	fflush(stdout);
}

int main(int argc, char* argv[]){
	
	char* command;	// command
	char** args;	// args for command
	int state;		// state of shell
	
	if(signal(SIGINT, catch_function) == SIG_ERR){ // Ctrl + C check
		fprintf(stderr, "An error occurred while setting a signal.\n");
		return EXIT_FAILURE;
	}
	if(raise(SIGINT) != 0){
		fprintf(stderr, "Error raising the signal.\n");
		return EXIT_FAILURE;
	}
	
	do{
		char currDir[100]; // String for current working directory
		getcwd(currDir, 100);
		fflush(stdout); // flush stdout and stdin before doing commands to remove anything that might be in there
		fflush(stdin);
		printf("%s%s# ",currentTime(), currDir);
		command = getCommand(); //read in the command from user
		if(strcmp("exit\n", command) == 0 || feof(stdin)){ //exit on Ctrl + D or "exit" is typing in shell
			printf("\n");
			state = 0;
			break;
		}
		args = getArgs(command); // seperate the arguments
		state = run(args, command); // run the commands
		
	} while (state);
	
	free(args);
	
	exit(EXIT_SUCCESS);
}

