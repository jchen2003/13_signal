#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

static void signalhandler(int signo){
    if (signo == SIGINT){
        printf("Program exited due to SIGINT\n");
        exit(0);
    }
    if (signo == SIGUSR1) {
      printf("\nParent ID: %d\n", getppid());
    }
}

int main(){
    signal(SIGUSR1, signalhandler);
    signal(SIGINT, signalhandler);

    while(1){
        printf("%d\n",getpid());
        sleep(1);
    }

}