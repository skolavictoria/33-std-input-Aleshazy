#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Error: No words to count.\n");
        return 1;
    }
    int count[argc - 1];
    for (int i = 1; i < argc; i++) {
        count[i - 1] = 1;
        for (int j = i + 1; j < argc; j++) {
            if (strcmp(argv[i], argv[j]) == 0) {
                count[i - 1]++;
                for (int k = j; k < argc - 1; k++) {
                    argv[k] = argv[k + 1];
                }
                argc--;
                j--;
            }
        }
    }
    for (int i = 1; i < argc; i++) {
        printf("%s: %d\n", argv[i], count[i - 1]);
    }
    return 0;
}
