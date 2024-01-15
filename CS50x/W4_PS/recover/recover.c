#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check for usage

    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open the the card image

    FILE *card = NULL;
    card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("fopen() returneed NULL\n");
        return 1;
    }

    // Declare variables

    uint8_t buffer[512];
    int count = 0;
    char filename[8];

    // Declare pointer img

    FILE *img = NULL;

    // Declare while loop to read from the card

    while (fread(buffer, 1, 512, card) == 512)
    {
        // Jpg header check

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close the file if a new header is found

            if (count > 0)
            {
                fclose(img);
            }

            sprintf(filename, "%03i.jpg", count);

            img = fopen(filename, "w");

            if (img == NULL)
            {
                return 1;
            }

            count++;
        }

        Write buffer to img

       if (img != NULL)
       {
            fwrite(buffer, 1, 512, img);
       }
    }

    // Close the last file and the card image

    fclose(img);
    fclose(card);
}
