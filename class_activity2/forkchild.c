#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();   // create child process

    if (pid < 0) {
        // fork failed
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0) {
        // Child process
        printf("Child process: executing ls command\n");

        execlp("ls", "ls", NULL);

        // If exec fails
        perror("exec failed");
        exit(1);
    }
    else {
        // Parent process
        wait(NULL);  // wait for child to finish
        printf("Parent process: child finished execution\n");
    }

    return 0;
}
