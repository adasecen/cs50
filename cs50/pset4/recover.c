#include <stdint.h>
#include <stdio.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check usage
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open file
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        return 1;
    }


    FILE *img = NULL;
    BYTE buffer[512];
    char filename[8];
    int counter = 0;

    while (fread(buffer, sizeof(BYTE), 512, file) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0) //0xli baslayan 16 terimin gösterimi
        {
            if (counter == 0) // 0'dan basladıgımda

            {
                sprintf(filename, "%03i.jpg", counter); // videoda vardı
                img = fopen(filename, "w");
                fwrite(&buffer, sizeof(BYTE), 512, img);
                counter += 1;
            }
            else if (counter > 0)
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                fwrite(&buffer, sizeof(BYTE), 512, img);
                counter += 1;
            }
        }
        else if (counter > 0)
        {
            fwrite(&buffer, sizeof(BYTE), 512, img);
        }
    }

    // Close file
    fclose(file);
    fclose(img);
}
