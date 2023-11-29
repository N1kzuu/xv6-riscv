#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]){
    
    int n = 2;
    int pid;

    for(int i = 0; i < n; i++){
        pid = fork();
        if(pid < 0){
            printf("Error in fork\n");
            exit(1);
        }
        if(pid == 0){
            set_priority(i, getppid());
            for(int j = 1; j <= 60; j++){
                printf("PID %d: %d\n", getppid(), j);
                sleep(1);

            }
            exit(0);
        }
        wait(0);

    }
    exit(0);
}