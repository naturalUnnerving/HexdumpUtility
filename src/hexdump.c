/*output hex from a program ROM to standard output, break line every 16 bits.
index each line with adress of first bit.*/

//Simple hexdump utility
//by Gianlucas Sherrill Velarde
//Version 1.0 (4/6/24)

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    //open the file
    FILE *f = fopen(argv[1], "rb");

    //if file invalid set faliure return status 1
    if (f == NULL) {
        printf("Error: could not interpret file\n");
        exit(1);
    }

    //get file size
    fseek(f, 0L, SEEK_END);
    int size = ftell(f);
    fseek(f, 0L, SEEK_SET);

    //set buffer to file size
    unsigned char *buffer = malloc(size);

    //read file
    fread(buffer, size, 1, f);
    fclose(f);

    //output hex from buffer to standard output, success return status 0
    int i = 0;
    
    while (i < size) {
        if (i % 16 == 0) {
            printf("\n");
            printf("%04x ", i);
        }
        printf("%02x ", buffer[i]);
        i++;
    }

    return 0;
}
