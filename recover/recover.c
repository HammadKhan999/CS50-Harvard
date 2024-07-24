#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
 // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
// Opening file using the name in command line argument
  FILE* file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Invalid File\n");
        return 1;
    }

    //declaring required variables
    unsigned char buffer[512];
    int BLOCK_SIZE = 512;
    bool isfirst_file = true;
    int i = 0;
    FILE* write_file = NULL;

    int num = fread(buffer, 1, 512, file);
    //checking the output of fread function to be 512 or 0
    printf("number of elements in file: %i\n",num);

    // using the given while loop to keep iterating the elements of each block of 512 bytes using fread function
    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        // using the given condition to identify the JPG pattern
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //checking if write file is not NULL then close it and open new file
            if (write_file != NULL)
            {
                fclose(write_file);
            }
            // opening new write file to write the elements of blocks of JPG
            char filename[8];
            sprintf(filename, "%03i.jpg", i);
            write_file = fopen(filename, "w");
           //using bool to check if our opened file is first file or not
            if (isfirst_file)
            {
                isfirst_file  = false;
            }
            //updating the write file counter to make new file
            i++;
        }
        //writing the elements to opened write file using fwrite function if the file is opened
        if (write_file != NULL)
        {
            fwrite(buffer, 1, 512, write_file);
        }
    }

    //closing the write_file if writing to file is done and avoid memory wastage
    if (write_file != NULL)
    {
        fclose(write_file);
    }
    //closing file to avoid memory errors
    fclose(file);

    return 0;
}