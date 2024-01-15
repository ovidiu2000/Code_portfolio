#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing

    int h = height;
    int w = width;

    // Looping throught the pixels

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {


            if (image[i][j].rgbtBlue == 0 || image[i][j].rgbtGreen == 0 || image[i][j].rgbtRed == 0)
            {
                image[i][j].rgbtBlue = 0;
                image[i][j].rgbtGreen = 255;
                image[i][j].rgbtRed = 0;
            }
        }
    }
}
