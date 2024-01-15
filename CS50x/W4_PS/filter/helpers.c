#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int red = 0;
    int green = 0;
    int blue = 0;
    int rounded = 0;
    float calc;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            red = image[i][j].rgbtRed;
            green = image[i][j].rgbtGreen;
            blue = image[i][j].rgbtBlue;

            calc = (red + green + blue) / 3.0;
            rounded = round(calc);

            image[i][j].rgbtRed = rounded;
            image[i][j].rgbtGreen = rounded;
            image[i][j].rgbtBlue = rounded;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int red = 0;
    int green = 0;
    int blue = 0;

    float sepiaRed;
    float sepiaGreen;
    float sepiaBlue;

    // Loop

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            red = image[i][j].rgbtRed;
            green = image[i][j].rgbtGreen;
            blue = image[i][j].rgbtBlue;

            // Calculathing the values

            sepiaRed = 0.393 * red + 0.769 * green + 0.189 * blue;
            sepiaGreen = 0.349 * red + 0.686 * green + 0.168 * blue;
            sepiaBlue = 0.272 * red + 0.534 * green + 0.131 * blue;

            if (round(sepiaRed) >= 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = round(sepiaRed);
            }

            if (round(sepiaGreen) >= 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = round(sepiaGreen);
            }

            if (round(sepiaBlue) >= 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = round(sepiaBlue);
            }
        }
    }

    return;
}

// Reflect image horizontally

void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    // Alocating memory

    RGBTRIPLE *buffer = malloc(sizeof(RGBTRIPLE));

    // Conditions

    if (width % 2 == 0 || width == 3)
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < (width / 2); j++)
            {
                *buffer = image[i][j];
                image[i][j] = image[i][(width - 1) - j];
                image[i][(width - 1) - j] = *buffer;
            }
        }
    }

    else
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < (width / 2) - 1; j++)
            {
                *buffer = image[i][j];
                image[i][j] = image[i][(width - 1) - j];
                image[i][(width - 1) - j] = *buffer;
            }
        }
    }

    free(buffer);
    return;
}

// Blur image

void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE(*copy)[width] = calloc(height, width * sizeof(RGBTRIPLE));

    if (copy == NULL)
    {
        printf("Not enough memory to store image.\n");
        return;
    }

    // Declarare variabile

    float blue1, blue2, blue3 = 0.0;
    float green1, green2, green3 = 0.0;
    float red1, red2, red3 = 0.0;

    // Algorith for finding the value of the individual pixel.

    // Top left corner

    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            if (k == 0 && l == 0)
            {
                red1 = (image[k][l].rgbtRed + image[k][l + 1].rgbtRed + image[k + 1][l].rgbtRed + image[k + 1][l + 1].rgbtRed);
                blue1 = (image[k][l].rgbtBlue + image[k][l + 1].rgbtBlue + image[k + 1][l].rgbtBlue + image[k + 1][l + 1].rgbtBlue);
                green1 =
                    (image[k][l].rgbtGreen + image[k][l + 1].rgbtGreen + image[k + 1][l].rgbtGreen + image[k + 1][l + 1].rgbtGreen);

                copy[k][l].rgbtBlue = round(blue1 / 4.0);
                copy[k][l].rgbtGreen = round(green1 / 4.0);
                copy[k][l].rgbtRed = round(red1 / 4.0);
            }
        }
    }

    // Pixels in the first column

    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            if (k > 0 && k < (height - 1) && l == 0)
            {
                red1 = (image[k][l].rgbtRed + image[k - 1][l].rgbtRed + image[k - 1][l + 1].rgbtRed);
                red2 = (image[k][l + 1].rgbtRed + image[k + 1][l + 1].rgbtRed + image[k + 1][l].rgbtRed);

                green1 = (image[k][l].rgbtGreen + image[k - 1][l].rgbtGreen + image[k - 1][l + 1].rgbtGreen);
                green2 = (image[k][l + 1].rgbtGreen + image[k + 1][l + 1].rgbtGreen + image[k + 1][l].rgbtGreen);

                blue1 = (image[k][l].rgbtBlue + image[k - 1][l].rgbtBlue + image[k - 1][l + 1].rgbtBlue);
                blue2 = (image[k][l + 1].rgbtBlue + image[k + 1][l + 1].rgbtBlue + image[k + 1][l].rgbtBlue);

                copy[k][l].rgbtBlue = round((blue1 + blue2) / 6.0);
                copy[k][l].rgbtGreen = round((green1 + green2) / 6.0);
                copy[k][l].rgbtRed = round((red1 + red2) / 6.0);
            }
        }
    }

    // Bottom left corner

    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            if (k == height - 1 && l == 0)
            {
                red1 = (image[k][l].rgbtRed + image[k - 1][l].rgbtRed + image[k - 1][l + 1].rgbtRed + image[k][l + 1].rgbtRed);
                blue1 = (image[k][l].rgbtBlue + image[k - 1][l].rgbtBlue + image[k - 1][l + 1].rgbtBlue + image[k][l + 1].rgbtBlue);
                green1 =
                    (image[k][l].rgbtGreen + image[k - 1][l].rgbtGreen + image[k - 1][l + 1].rgbtGreen + image[k][l + 1].rgbtGreen);

                copy[k][l].rgbtBlue = round(blue1 / 4.0);
                copy[k][l].rgbtGreen = round(green1 / 4.0);
                copy[k][l].rgbtRed = round(red1 / 4.0);
            }
        }
    }

    // Pixels from the last row

    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            if (k == (height - 1) && l > 0 && l < width - 1)
            {
                red1 = (image[k][l].rgbtRed + image[k][l - 1].rgbtRed + image[k - 1][l - 1].rgbtRed);
                red2 = (image[k - 1][l].rgbtRed + image[k - 1][l + 1].rgbtRed + image[k][l + 1].rgbtRed);

                blue1 = (image[k][l].rgbtBlue + image[k][l - 1].rgbtBlue + image[k - 1][l - 1].rgbtBlue);
                blue2 = (image[k - 1][l].rgbtBlue + image[k - 1][l + 1].rgbtBlue + image[k][l + 1].rgbtBlue);

                green1 = (image[k][l].rgbtGreen + image[k][l - 1].rgbtGreen + image[k - 1][l - 1].rgbtGreen);
                green2 = (image[k - 1][l].rgbtGreen + image[k - 1][l + 1].rgbtGreen + image[k][l + 1].rgbtGreen);

                copy[k][l].rgbtBlue = round((blue1 + blue2) / 6.0);
                copy[k][l].rgbtGreen = round((green1 + green2) / 6.0);
                copy[k][l].rgbtRed = round((red1 + red2) / 6.0);
            }
        }
    }

    // Bottom right corner

    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            if (k == (height - 1) && l == width - 1)
            {
                red1 = (image[k][l].rgbtRed + image[k][l - 1].rgbtRed + image[k - 1][l - 1].rgbtRed + image[k - 1][l].rgbtRed);
                blue1 = (image[k][l].rgbtBlue + image[k][l - 1].rgbtBlue + image[k - 1][l - 1].rgbtBlue + image[k - 1][l].rgbtBlue);
                green1 =
                    (image[k][l].rgbtGreen + image[k][l - 1].rgbtGreen + image[k - 1][l - 1].rgbtGreen + image[k - 1][l].rgbtGreen);

                copy[k][l].rgbtBlue = round(blue1 / 4.0);
                copy[k][l].rgbtGreen = round(green1 / 4.0);
                copy[k][l].rgbtRed = round(red1 / 4.0);
            }
        }
    }

    // Pixels from the last column

    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            if (k < (height - 1) && k > 0 && l == (width - 1))
            {
                red1 = (image[k][l].rgbtRed + image[k + 1][l].rgbtRed + image[k + 1][l - 1].rgbtRed);
                red2 = (image[k][l - 1].rgbtRed + image[k - 1][l - 1].rgbtRed + image[k - 1][l].rgbtRed);

                blue1 = (image[k][l].rgbtBlue + image[k + 1][l].rgbtBlue + image[k + 1][l - 1].rgbtBlue);
                blue2 = (image[k][l - 1].rgbtBlue + image[k - 1][l - 1].rgbtBlue + image[k - 1][l].rgbtBlue);

                green1 = (image[k][l].rgbtGreen + image[k + 1][l].rgbtGreen + image[k + 1][l - 1].rgbtGreen);
                green2 = (image[k][l - 1].rgbtGreen + image[k - 1][l - 1].rgbtGreen + image[k - 1][l].rgbtGreen);

                copy[k][l].rgbtBlue = round((blue1 + blue2) / 6.0);
                copy[k][l].rgbtGreen = round((green1 + green2) / 6.0);
                copy[k][l].rgbtRed = round((red1 + red2) / 6.0);
            }
        }
    }

    // Right top corner

    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            if (k == 0 && l == (width - 1))
            {
                red1 = (image[k][l].rgbtRed + image[k][l - 1].rgbtRed + image[k + 1][l - 1].rgbtRed + image[k + 1][l].rgbtRed);
                blue1 = (image[k][l].rgbtBlue + image[k][l - 1].rgbtBlue + image[k + 1][l - 1].rgbtBlue + image[k + 1][l].rgbtBlue);
                green1 =
                    (image[k][l].rgbtGreen + image[k][l - 1].rgbtGreen + image[k + 1][l - 1].rgbtGreen + image[k + 1][l].rgbtGreen);

                copy[k][l].rgbtBlue = round(blue1 / 4.0);
                copy[k][l].rgbtGreen = round(green1 / 4.0);
                copy[k][l].rgbtRed = round(red1 / 4.0);
            }
        }
    }

    // First row of pixels

    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            if (k == 0 && l > 0 && l < width - 1)
            {

                red1 = image[k][l - 1].rgbtRed + image[k][l].rgbtRed + image[k][l + 1].rgbtRed;
                red2 = image[k + 1][l - 1].rgbtRed + image[k + 1][l].rgbtRed + image[k + 1][l + 1].rgbtRed;

                blue1 = image[k][l - 1].rgbtBlue + image[k][l].rgbtBlue + image[k][l + 1].rgbtBlue;
                blue2 = image[k + 1][l - 1].rgbtBlue + image[k + 1][l].rgbtBlue + image[k + 1][l + 1].rgbtBlue;

                green1 = image[k][l - 1].rgbtGreen + image[k][l].rgbtGreen + image[k][l + 1].rgbtGreen;
                green2 = image[k + 1][l - 1].rgbtGreen + image[k + 1][l].rgbtGreen + image[k + 1][l + 1].rgbtGreen;

                copy[k][l].rgbtBlue = round((blue1 + blue2) / 6.0);
                copy[k][l].rgbtGreen = round((green1 + green2) / 6.0);
                copy[k][l].rgbtRed = round((red1 + red2) / 6.0);
            }
        }
    }

    // Inside pixels

    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            if (k > 0 && k < height - 1 && l > 0 && l < width - 1)
            {
                red1 = (image[k - 1][l - 1].rgbtRed + image[k - 1][l].rgbtRed + image[k - 1][l + 1].rgbtRed);
                red2 = (image[k][l - 1].rgbtRed + image[k][l].rgbtRed + image[k][l + 1].rgbtRed);
                red3 = (image[k + 1][l - 1].rgbtRed + image[k + 1][l].rgbtRed + image[k + 1][l + 1].rgbtRed);

                green1 = (image[k - 1][l - 1].rgbtGreen + image[k - 1][l].rgbtGreen + image[k - 1][l + 1].rgbtGreen);
                green2 = (image[k][l - 1].rgbtGreen + image[k][l].rgbtGreen + image[k][l + 1].rgbtGreen);
                green3 = (image[k + 1][l - 1].rgbtGreen + image[k + 1][l].rgbtGreen + image[k + 1][l + 1].rgbtGreen);

                blue1 = (image[k - 1][l - 1].rgbtBlue + image[k - 1][l].rgbtBlue + image[k - 1][l + 1].rgbtBlue);
                blue2 = (image[k][l - 1].rgbtBlue + image[k][l].rgbtBlue + image[k][l + 1].rgbtBlue);
                blue3 = (image[k + 1][l - 1].rgbtBlue + image[k + 1][l].rgbtBlue + image[k + 1][l + 1].rgbtBlue);

                copy[k][l].rgbtBlue = round((blue1 + blue2 + blue3) / 9.0);
                copy[k][l].rgbtGreen = round((green1 + green2 + green3) / 9.0);
                copy[k][l].rgbtRed = round((red1 + red2 + red3) / 9.0);
            }
        }
    }

    // loop that copy  pixels from "copy" to "image"

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }

    // Freeing "copy"

    free(copy);
}