/** @file shell.c */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "log.h"


log_t Log;

/**
 * Starting point for shell.
 */

 void prefix() {
    char* buffer= (char*)malloc(sizeof(char) * 100);
    pid_t pid;

    pid=getpid();
    printf("(pid=%d)%s$ ", pid, getcwd(buffer, 100));
    free(buffer);
}

int main() {
	char *buffer=NULL;
	size_t len=0;
	ssize_t read;

	prefix();
	while((read=getline(&buffer,&len,stdin))!=-1){
	buffer[strlen(buffer)-1]='\0';
	printf("Command executed by pid=%d\n", getpid());
	free(buffer);
	buffer=NULL;
	
	}
	
	
    return 0;
}
