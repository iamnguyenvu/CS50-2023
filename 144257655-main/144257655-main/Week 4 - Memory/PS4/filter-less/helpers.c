#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int averageValues = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = averageValues;
            image[i][j].rgbtGreen = averageValues;
            image[i][j].rgbtRed = averageValues;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            image[i][j].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
            image[i][j].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
            image[i][j].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int balancewidth = width / 2;
    for (int i = 0; i < height; i++)
    {
        int revwidth = width - 1;
        for (int j = 0; j < balancewidth; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][revwidth];
            image[i][revwidth] = temp;
            revwidth--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // store original color values
    RGBTRIPLE store[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            store[i][j] = image[i][j];
        }
    }
    // convert to blur
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 && j == 0)
            {
                image[i][j].rgbtRed = round(
                    (store[i][j].rgbtRed + store[i][j + 1].rgbtRed + store[i + 1][j].rgbtRed + store[i + 1][j + 1].rgbtRed) / 4.0);
                image[i][j].rgbtGreen = round((store[i][j].rgbtGreen + store[i][j + 1].rgbtGreen + store[i + 1][j].rgbtGreen +
                                               store[i + 1][j + 1].rgbtGreen) /
                                              4.0);
                image[i][j].rgbtBlue = round(
                    (store[i][j].rgbtBlue + store[i][j + 1].rgbtBlue + store[i + 1][j].rgbtBlue + store[i + 1][j + 1].rgbtBlue) /
                    4.0);
            }
            else if (i == 0 && j == width - 1)
            {
                image[i][j].rgbtRed = round(
                    (store[i][j - 1].rgbtRed + store[i][j].rgbtRed + store[i + 1][j].rgbtRed + store[i + 1][j - 1].rgbtRed) / 4.0);
                image[i][j].rgbtGreen = round((store[i][j].rgbtGreen + store[i][j - 1].rgbtGreen + store[i + 1][j].rgbtGreen +
                                               store[i + 1][j - 1].rgbtGreen) /
                                              4.0);
                image[i][j].rgbtBlue = round(
                    (store[i][j].rgbtBlue + store[i][j - 1].rgbtBlue + store[i + 1][j].rgbtBlue + store[i + 1][j - 1].rgbtBlue) /
                    4.0);
            }
            else if (i == 0 && j != width - 1)
            {
                image[i][j].rgbtRed = round((store[i][j - 1].rgbtRed + store[i][j].rgbtRed + store[i][j + 1].rgbtRed +
                                             store[i + 1][j + 1].rgbtRed + store[i + 1][j].rgbtRed + store[i + 1][j - 1].rgbtRed) /
                                            6.0);
                image[i][j].rgbtGreen =
                    round((store[i][j - 1].rgbtGreen + store[i][j].rgbtGreen + store[i][j + 1].rgbtGreen +
                           store[i + 1][j].rgbtGreen + store[i + 1][j - 1].rgbtGreen + store[i + 1][j + 1].rgbtGreen) /
                          6.0);
                image[i][j].rgbtBlue =
                    round((store[i][j - 1].rgbtBlue + store[i][j].rgbtBlue + store[i][j + 1].rgbtBlue + store[i + 1][j].rgbtBlue +
                           store[i + 1][j - 1].rgbtBlue + store[i + 1][j + 1].rgbtBlue) /
                          6.0);
            }
            else if (i != height - 1 && j == 0)
            {
                image[i][j].rgbtRed = round((store[i - 1][j].rgbtRed + store[i - 1][j + 1].rgbtRed + store[i][j].rgbtRed +
                                             store[i][j + 1].rgbtRed + store[i + 1][j].rgbtRed + store[i + 1][j + 1].rgbtRed) /
                                            6.0);
                image[i][j].rgbtGreen =
                    round((store[i - 1][j].rgbtGreen + store[i - 1][j + 1].rgbtGreen + store[i][j].rgbtGreen +
                           store[i][j + 1].rgbtGreen + store[i + 1][j].rgbtGreen + store[i + 1][j + 1].rgbtGreen) /
                          6.0);
                image[i][j].rgbtBlue = round((store[i - 1][j].rgbtBlue + store[i - 1][j + 1].rgbtBlue + store[i][j].rgbtBlue +
                                              store[i][j + 1].rgbtBlue + store[i + 1][j].rgbtBlue + store[i + 1][j + 1].rgbtBlue) /
                                             6.0);
            }
            else if (i != 0 && i != height - 1 && j == width - 1)
            {
                image[i][j].rgbtRed = round((store[i - 1][j].rgbtRed + store[i - 1][j - 1].rgbtRed + store[i][j].rgbtRed +
                                             store[i][j - 1].rgbtRed + store[i + 1][j].rgbtRed + store[i + 1][j - 1].rgbtRed) /
                                            6.0);
                image[i][j].rgbtGreen =
                    round((store[i - 1][j].rgbtGreen + store[i - 1][j - 1].rgbtGreen + store[i][j].rgbtGreen +
                           store[i][j - 1].rgbtGreen + store[i + 1][j].rgbtGreen + store[i + 1][j - 1].rgbtGreen) /
                          6.0);
                image[i][j].rgbtBlue = round((store[i - 1][j].rgbtBlue + store[i - 1][j - 1].rgbtBlue + store[i][j].rgbtBlue +
                                              store[i][j - 1].rgbtBlue + store[i + 1][j].rgbtBlue + store[i + 1][j - 1].rgbtBlue) /
                                             6.0);
            }
            else if (i == height - 1 && j == 0)
            {
                image[i][j].rgbtRed = round(
                    (store[i - 1][j].rgbtRed + store[i - 1][j + 1].rgbtRed + store[i][j].rgbtRed + store[i][j + 1].rgbtRed) / 4.0);
                image[i][j].rgbtBlue = round(
                    (store[i - 1][j].rgbtBlue + store[i - 1][j + 1].rgbtBlue + store[i][j].rgbtBlue + store[i][j + 1].rgbtBlue) /
                    4.0);
                image[i][j].rgbtGreen = round((store[i - 1][j].rgbtGreen + store[i - 1][j + 1].rgbtGreen + store[i][j].rgbtGreen +
                                               store[i][j + 1].rgbtGreen) /
                                              4.0);
            }
            else if (i == height - 1 && j == width - 1)
            {
                image[i][j].rgbtRed = round(
                    (store[i - 1][j - 1].rgbtRed + store[i - 1][j].rgbtRed + store[i][j - 1].rgbtRed + store[i][j].rgbtRed) / 4.0);
                image[i][j].rgbtBlue = round(
                    (store[i - 1][j - 1].rgbtBlue + store[i - 1][j].rgbtBlue + store[i][j - 1].rgbtBlue + store[i][j].rgbtBlue) /
                    4.0);
                image[i][j].rgbtGreen = round((store[i - 1][j - 1].rgbtGreen + store[i - 1][j].rgbtGreen +
                                               store[i][j - 1].rgbtGreen + store[i][j].rgbtGreen) /
                                              4.0);
            }
            else if (i == height - 1 && j != 0 && j != width - 1)
            {
                image[i][j].rgbtRed = round((store[i - 1][j - 1].rgbtRed + store[i - 1][j].rgbtRed + store[i - 1][j + 1].rgbtRed +
                                             store[i][j - 1].rgbtRed + store[i][j].rgbtRed + store[i][j + 1].rgbtRed) /
                                            6.0);
                image[i][j].rgbtBlue =
                    round((store[i - 1][j - 1].rgbtBlue + store[i - 1][j].rgbtBlue + store[i - 1][j + 1].rgbtBlue +
                           store[i][j - 1].rgbtBlue + store[i][j].rgbtBlue + store[i][j + 1].rgbtBlue) /
                          6.0);
                image[i][j].rgbtGreen =
                    round((store[i - 1][j - 1].rgbtGreen + store[i - 1][j].rgbtGreen + store[i - 1][j + 1].rgbtGreen +
                           store[i][j - 1].rgbtGreen + store[i][j].rgbtGreen + store[i][j + 1].rgbtGreen) /
                          6.0);
            }
            else
            {
                image[i][j].rgbtRed = round((store[i - 1][j - 1].rgbtRed + store[i - 1][j].rgbtRed + store[i - 1][j + 1].rgbtRed +
                                             store[i][j - 1].rgbtRed + store[i][j].rgbtRed + store[i][j + 1].rgbtRed +
                                             store[i + 1][j - 1].rgbtRed + store[i + 1][j].rgbtRed + store[i + 1][j + 1].rgbtRed) /
                                            9.0);
                image[i][j].rgbtGreen =
                    round((store[i - 1][j - 1].rgbtGreen + store[i - 1][j].rgbtGreen + store[i - 1][j + 1].rgbtGreen +
                           store[i][j - 1].rgbtGreen + store[i][j].rgbtGreen + store[i][j + 1].rgbtGreen +
                           store[i + 1][j - 1].rgbtGreen + store[i + 1][j].rgbtGreen + store[i + 1][j + 1].rgbtGreen) /
                          9.0);
                image[i][j].rgbtBlue =
                    round((store[i - 1][j - 1].rgbtBlue + store[i - 1][j].rgbtBlue + store[i - 1][j + 1].rgbtBlue +
                           store[i][j - 1].rgbtBlue + store[i][j].rgbtBlue + store[i][j + 1].rgbtBlue +
                           store[i + 1][j - 1].rgbtBlue + store[i + 1][j].rgbtBlue + store[i + 1][j + 1].rgbtBlue) /
                          9.0);
            }
        }
    }
    return;
}
