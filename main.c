#include <stdio.h>
#include <stdlib.h>  // For atoi() function

int main(int argc, char *argv[]) {
    printf("Number of arguments: %d\n", argc);

    printf("Arguments passed to the program (converted to integers):\n");
    for (int i = 1; i < argc; i++) {
        int num = atoi(argv[i]);  // Convert argument to integer using atoi()
        printf("argv[%d]: %d\n", i, num);
    }

    for (int i = 1; i < argc; i++) {
        int num = atoi(argv[i]);  // Convert string to integer
        num += 10;  // Modify the number (e.g., add 10 to each number)
        printf("Modified argv[%d]: %d\n", i, num);  // Print modified number
    }

    return 0;
}

