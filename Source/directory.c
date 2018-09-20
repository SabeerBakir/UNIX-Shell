/*
	Name: Sabeer Bakir
	Student Number: 16333886
	Email: sabeer.bakir@ucdconnect.ie
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

void cd(char * args[]){
	char currDir[80];
	char * dir = args[1];
	getcwd(currDir, 80);
	if(strcmp(dir, "..") == 0){
		char prevDir[80];
		memset(prevDir, '\0', sizeof(prevDir));
		strncpy(prevDir, currDir, strlen(currDir) - strlen(strrchr(currDir, '/')));
		chdir(prevDir);
	}
	else{
		strcpy(currDir, strcat(currDir, "/")); //if the directory has a space in it, use "\ " to symbolise space
		if(strstr(dir, "\\")){
			dir[strlen(dir) - 1] = ' ';
			dir = strcat(dir, args[2]);
		}
		if(chdir(strcat(currDir, dir)) != 0){
			printf("No Such directory\n%s\n", dir);
		}
	}
}