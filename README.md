#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
 pid_t pid;
 int status;
 printf("Starting main program...\n");
// Fork a child process
 pid = fork();
if (pid < 0) {
 fprintf(stderr, "Fork failed\n");
 return 1;
 } else if (pid == 0) {
 // Child process
 printf("Child process executing...\n");
// Executing a command using execl
 execl("/bin/ls", "ls", "-l", NULL);
 // This line will only be reached if execl fails
 perror("execl");
 exit(EXIT_FAILURE);
 } else {
 // Parent process
 printf("Parent process waiting for child...\n");
// Wait for the child process to finish
 wait(&status);
if (WIFEXITED(status)) {
 printf("Child process terminated with status: %d\n", WEXITSTATUS(status));
 } else {
 printf("Child process terminated abnormally\n");
 }
 printf("Parent process exiting...\n");
 }
 return 0;
}
