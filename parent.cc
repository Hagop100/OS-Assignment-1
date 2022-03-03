#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h>
#include <string>
#include <cstring>
#include <iostream>

int main(int argc, char *argv[]) {

	//counts the number of children
	int childIndex = 0;

	std::cout << "I have " << (argc - 1)/2 << " children.\n";

	//for loop that handles the execution of the number of times we will call execvp()
	for(int i = 1; i <= argc-1; i += 2) {
		pid_t pid = fork(); //fork will be called argc-1 number of times
		childIndex++; //incrementation of childIndex

		//creation of char* array to pass into exec
		//we place the file name in the 0th index
		//then place the childIndex in the 1st index(must properly convert int to char*)
		//then place the gender-name pair in the next two indices
		//NULL terminated
		char* childArgs[] = {(char*)"./child", const_cast<char*>(std::to_string(childIndex).c_str()), argv[i], argv[i+1], NULL};

		//pid == 0 means we are in the child process
		if(pid == 0) {
			//Child
			execvp(childArgs[0], childArgs); //pass in filename in first parameter and the remaining array in the second parameter 
		}
		//pid < 0 means fork() failure
		else if(pid < 0) {
			perror("Fork failed"); //display error message that fork failed
			exit(1); //exit the program with a return value of 1
		}
		//pid > 0 means we are in the parent process
		else if(pid > 0) {
			//Parent
			wait(NULL); //wait system call ensures that parent waits for all children to execute
		}
	}

	std::cout << "All child processes terminated. Parent exits.\n";
	
	return 0;
}