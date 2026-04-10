#include <stdio.h>

int main() {
    FILE *source;
    FILE *destination;
    int c;

    source = fopen("source.txt", "r");

    if (source == NULL) {
        printf("Error: cannot open source file\n");
        return 1;
    }

    destination = fopen("copy.txt", "w");

    if (destination == NULL) {
        printf("Error: cannot create destination file\n");
        fclose(source);
        return 1;
    }

    c = fgetc(source);
    while (c != EOF) {
        fputc(c, destination);
        c = fgetc(source);
    }

    fclose(source);
    fclose(destination);

    printf("File copied successfully\n");

    return 0;
}
