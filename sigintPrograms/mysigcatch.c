#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// sigint handler
void sigint_handler(int sig) {
    printf("\nSIGINT signal caught!\n");
    exit(0);
}

int main() {
    // register handler
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        perror("signal");
        exit(EXIT_FAILURE);
    }
    
    while(1) {
        printf("Press ^C to send a SIGINT signal\n");
        sleep(3);
    }
    
    return 0;
}
