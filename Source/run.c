/*
	Name: Sabeer Bakir
	Student Number: 16333886
	Email: sabeer.bakir@ucdconnect.ie
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include "shell.h"


int run(char * args[], char * command){
	if(strcmp(command, "\n") == 0){ //do nothing if Enter is pressed
		return 1;
	}
	if(strcmp(args[0], "cd") == 0){ //Change directory commands
		cd(args);
		return 1;
	}
	
	pid_t child_pid;
	int child_status;
	if((child_pid = fork()) == 0){ // create child process
		//sleep(10);
		
		// redirect builtin with format "program > "filename.txt" "
		if(!!strstr(command, ">")){ //if > is present
			char* filename = strchr(command, '>');
			filename = filename + 2;
			filename[strlen(filename) - 1] = '\0'; //remove '\n'
			int file = open(filename, O_WRONLY | O_CREAT| O_TRUNC, 0666);
			if(dup2(file, 1) < 0){
				fprintf(stderr, "Error moving file to stdout file descriptor\n");
				return EXIT_FAILURE;
			}
			
			char temp[] = ""; // blank string to append to
			command = strncat(temp, command, strlen(command) - strlen(filename) - 2); //return everything before the >
			
			close(file);
			args = getArgs(command); // remake arguments to pass into execvp as we do not want > going in
		}
		execvp(args[0], args);
		printf("Unknown Command\n");
		exit(0);
	}
	else{
		signal(SIGINT, SIG_IGN);
		//printf("parent waiting\n");
		wait(&child_status);
		signal(SIGINT, SIG_DFL);
	}
	//printf("parent exiting\n");
	return 1;
	
}