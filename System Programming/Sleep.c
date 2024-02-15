#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Sleeping for 5 seconds...\n");
    
    sleep(5);

    printf("Awake!\n");

    return 0;
}
