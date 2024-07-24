#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])

{
    //iterating through all image pixels
    for (int i = 0, n = height - 1; i <= n; i++)
    {
        for (int j = 0, m = width - 1; j <= m; j++)
        {
            //using average formula
            int avg = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);
            // int rnd_avg = round(avg);
            //assigning new values to existing pixel values using given condition
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //iterating through all pixels of image struct
    for (int i = 0, n = height - 1; i <= n; i++)
    {
        for (int j = 0, m = width - 1; j <= m; j++)
        {
            //storing the retrived values from the given formula to new variables
            int sepia_Red = round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue));
            int sepia_Green =
                round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue));
            int sepia_Blue =
                round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue));

            // check condition if values exceed 255 or are below 0
            if (sepia_Red > 255)
            {
                sepia_Red = 255;
            }
            else if (sepia_Red < 0)
            {
                sepia_Red = 0;
            }
            if (sepia_Green > 255)
            {
                sepia_Green = 255;
            }
            else if (sepia_Green < 0)
            {
                sepia_Green = 0;
            }
            if (sepia_Blue > 255)
            {
                sepia_Blue = 0;
            }
            else if (sepia_Blue < 0)
            {
                sepia_Blue = 0;
            }
            // assigning the values
            image[i][j].rgbtRed = sepia_Red;
            image[i][j].rgbtGreen = sepia_Green;
            image[i][j].rgbtBlue = sepia_Blue;
        }
    }
    return;
}
//swap function to swap the pixel values of images (learned in lecture)
void swap(RGBTRIPLE *pixel_value_1, RGBTRIPLE *pixel_value_2);
void swap(RGBTRIPLE *pixel1, RGBTRIPLE *pixel2)
{
    RGBTRIPLE temp = *pixel1;
    *pixel1 = *pixel2;
    *pixel2 = temp;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //iterating through all pixels images
    for (int i = 0, m = height; i < m; i++)
    {
        for (int j = 0, n = width - 1; j < n; j++)
        {
            //swapping each row elements
            swap(&image[i][j], &image[i][n]);
            n--;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // declaring the copy variable for storing copy of original image pixels
    RGBTRIPLE copy[height][width];

    // iterating to store the original image pixels in copy variable to avoid the overlapping of pixel values
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j].rgbtRed = image[i][j].rgbtRed;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }

    // iterating throguh copy image variable containing all the pixels of images
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // decalring required variables to store the sum and average
            int denominator = 0;
            int sum_red = 0;
            int sum_green = 0;
            int sum_blue = 0;

            // updating average variables for Current pixel
            sum_red += copy[i][j].rgbtRed;
            sum_green += copy[i][j].rgbtGreen;
            sum_blue += copy[i][j].rgbtBlue;
            denominator++;

            // updating average variables for Top-left pixel
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                sum_red += copy[i - 1][j - 1].rgbtRed;
                sum_green += copy[i - 1][j - 1].rgbtGreen;
                sum_blue += copy[i - 1][j - 1].rgbtBlue;
                denominator++;
            }

            // updating average variables for Top pixel
            if (i - 1 >= 0)
            {
                sum_red += copy[i - 1][j].rgbtRed;
                sum_green += copy[i - 1][j].rgbtGreen;
                sum_blue += copy[i - 1][j].rgbtBlue;
                denominator++;
            }

            // updating average variables for Top-right pixel
            if (i - 1 >= 0 && j + 1 < width)
            {
                sum_red += copy[i - 1][j + 1].rgbtRed;
                sum_green += copy[i - 1][j + 1].rgbtGreen;
                sum_blue += copy[i - 1][j + 1].rgbtBlue;
                denominator++;
            }

            // updating average variables for left pixel
            if (j - 1 >= 0)
            {
                sum_red += copy[i][j - 1].rgbtRed;
                sum_green += copy[i][j - 1].rgbtGreen;
                sum_blue += copy[i][j - 1].rgbtBlue;
                denominator++;
            }

            // updating average variables for Right pixel
            if (j + 1 < width)
            {
                sum_red += copy[i][j + 1].rgbtRed;
                sum_green += copy[i][j + 1].rgbtGreen;
                sum_blue += copy[i][j + 1].rgbtBlue;
                denominator++;
            }

            // updating average variables for Bottom-left pixel
            if (i + 1 < height && j - 1 >= 0)
            {
                sum_red += copy[i + 1][j - 1].rgbtRed;
                sum_green += copy[i + 1][j - 1].rgbtGreen;
                sum_blue += copy[i + 1][j - 1].rgbtBlue;
                denominator++;
            }

            // updating average variables for Bottom pixel
            if (i + 1 < height)
            {
                sum_red += copy[i + 1][j].rgbtRed;
                sum_green += copy[i + 1][j].rgbtGreen;
                sum_blue += copy[i + 1][j].rgbtBlue;
                denominator++;
            }

            // updating average variables for Bottom-right pixel
            if (i + 1 < height && j + 1 < width)
            {
                sum_red += copy[i + 1][j + 1].rgbtRed;
                sum_green += copy[i + 1][j + 1].rgbtGreen;
                sum_blue += copy[i + 1][j + 1].rgbtBlue;
                denominator++;
            }

            // Updating the R, G and B of the original pixel using average and rounding to get nearest interger
            image[i][j].rgbtRed = round(sum_red / (float) denominator);
            image[i][j].rgbtGreen = round(sum_green / (float) denominator);
            image[i][j].rgbtBlue = round(sum_blue / (float) denominator);
        }
    }
    return;
}