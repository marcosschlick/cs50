#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE *red = &image[i][j].rgbtRed;
            BYTE *green = &image[i][j].rgbtGreen;
            BYTE *blue = &image[i][j].rgbtBlue;

            // Take average of red, green, and blue
            int average = round((*red + *green + *blue) / 3.0);

            // Update pixel values
            *red = average;
            *green = average;
            *blue = average;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE *red = &image[i][j].rgbtRed;
            BYTE *green = &image[i][j].rgbtGreen;
            BYTE *blue = &image[i][j].rgbtBlue;

            // Compute sepia values
            int sepiaRed = round(0.393 * *red + 0.769 * *green + 0.189 * *blue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            int sepiaGreen = round(0.349 * *red + 0.686 * *green + 0.168 * *blue);
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            int sepiaBlue = round(0.272 * *red + 0.534 * *green + 0.131 * *blue);
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // Update pixel with sepia values
            *red = sepiaRed;
            *green = sepiaGreen;
            *blue = sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (int) (width / 2); j++)
        {
            // Swap pixels
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = tmp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Blur pixels
            float validPixels = 0;
            int red = 0;
            int green = 0;
            int blue = 0;

            for (int k = -1; k < 2; k++)
            {
                int tmpHeight = i + k;
                if (tmpHeight < 0 || tmpHeight >= height)
                {
                    continue;
                }

                for (int l = -1; l < 2; l++)
                {
                    int tmpWidth = j + l;
                    if (tmpWidth < 0 || tmpWidth >= width)
                    {
                        continue;
                    }

                    red += copy[tmpHeight][tmpWidth].rgbtRed;
                    green += copy[tmpHeight][tmpWidth].rgbtGreen;
                    blue += copy[tmpHeight][tmpWidth].rgbtBlue;

                    validPixels++;
                }
            }
            image[i][j].rgbtRed = round(red / validPixels);
            image[i][j].rgbtGreen = round(green / validPixels);
            image[i][j].rgbtBlue = round(blue / validPixels);
        }
    }
}

