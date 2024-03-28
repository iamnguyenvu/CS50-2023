#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 2;
    }

    BYTE buffer[BLOCK_SIZE];
    int count = 0;
    char *filename = malloc(8 * sizeof(char));
    FILE *outfile = NULL;
    bool found_JPEG = false;

    while (fread(buffer, BLOCK_SIZE, 1, file) == 1)
    {
        // check start of JPEGs
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (found_JPEG)
            {
                fclose(outfile);
            }
            else
            {
                found_JPEG = true;
            }

            // write PJEGs filename
            sprintf(filename, "%03i.jpg", count++);
            outfile = fopen(filename, "w");

            if (outfile == NULL)
            {
                fclose(file);
                return 3;
            }
        }

        if (found_JPEG)
        {
            fwrite(buffer, BLOCK_SIZE, 1, outfile);
        }
    }
    free(filename);
    fclose(outfile);
    fclose(file);
}