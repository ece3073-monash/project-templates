/* 
 *  ECE3073 Convolve Skeleton code
 *  Created By: ECE3073 Staff
 *  Last Modified: 18/12/2024
 *  Purpose: To take a 4-bit greyscale input image, and apply a convolution to it using the provided 3x3 kernel.
 *  Note: This function is not designed to handle the edge pixels, thus the Loops only go from 1 to height-1, and 1 to width-1
 * 
 *  Inputs:
 *      - inputImage: Pointer for a width*height 1D array for the input greyscale image 
 *      - outputImage: Pointer to a width*height 1D array for the output greyscale image
 *      - kernel: Pointer to a 3x3 1D array for the kernel
 *      - width: Integer for the width of the input/output image
 *      - height: Integer for the height of the input / output image
 * 
 *  Outputs:
 *      - ALL outputs are placed into the array determined by the pointers.
 */
void convolve(void *inputImage, void *outputImage, void *kernel, int width, int height) {
    // We will be ignoring the 1 pixel border around the image to make the function less complex 
    // This move through the image in a raster-scan order.

    for (int i = 1; i < height - 1; i++) 
    { // Outer Loop iterates through the rows
        for (int j = 1; j < width - 1; j++) 
        { // Inner Loop iterates through the columns
            // Your code goes here.
        }
    }
}
