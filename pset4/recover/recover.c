#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        return 2;
    }

    BYTE buffer[BLOCK_SIZE];
    char filename[8];
    int count = 0;
    FILE *img;

    // Repeat until end of card and read 512 bytes into a buffer
    while (fread(buffer, BLOCK_SIZE, 1, file))
    {
        //check if is a jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (count != 0)
            {
                fclose(img);
            }

            sprintf(filename, "%03i.jpg", count++);
            img = fopen(filename, "w");
            fwrite(buffer, BLOCK_SIZE, 1, img);
        }
        else if (count > 0)
        {
            fwrite(buffer, BLOCK_SIZE, 1, img);
        }
    }

    // Close files
    fclose(img);
    fclose(file);
    return 0;
}