#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// sigint handler
void sigint_handler(int sig) {
    static int numCaught = 0;
    printf("\nSIGINT signal caught! Signal number: %d\n", sig);
    numCaught++;
    if (numCaught == 2) {
        // restore default system handler
        printf("Restoring default SIGINT handler...\n");
        signal(SIGINT, SIG_DFL);
    }
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
