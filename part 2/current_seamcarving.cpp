#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using std::cout, std::endl, std::string;

void initializeImage(Pixel image[][MAX_HEIGHT]) {
  // iterate through columns
  for (unsigned int col = 0; col < MAX_WIDTH; col++) {
    // iterate through rows
    for (unsigned int row = 0; row < MAX_HEIGHT; row++) {
      // initialize pixel
      image[col][row] = {0, 0, 0};
    }
  }
}

unsigned int loadVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int start_col, unsigned int width, unsigned int height, unsigned int seam[]) {
    // Set the first element of the seam array to the starting column
    seam[0] = start_col;
    // Initialize the energy of the seam to zero
    unsigned int seam_energy = energy(image, start_col, 0, width, height);
    // Iterate through the rest of the rows in the image
    unsigned int row = 1;
    while (row < height) {
        // Get the energy of the pixel to the left of the current seam pixel
        unsigned int left_energy = (start_col > 0) ? energy(image, start_col - 1, row, width, height) : numeric_limits<unsigned int>::max();
        // Get the energy of the pixel directly below the current seam pixel
        unsigned int center_energy = energy(image, start_col, row, width, height);
        // Get the energy of the pixel to the right of the current seam pixel
        unsigned int right_energy = (start_col < width-1) ? energy(image, start_col+1, row, width, height) : numeric_limits<unsigned int>::max();
        // Find the minimum of the three energies
        unsigned int min_energy = min(left_energy, min(center_energy, right_energy));
        // Add the minimum energy to the seam energy
        seam_energy += min_energy;
        // Set the current seam pixel to the column with the minimum energy
        if (min_energy == center_energy) {
            seam[row] = start_col;
        } else if (min_energy == right_energy) {
            seam[row] = start_col + 1;
            start_col++;
        } else {
            seam[row] = start_col - 1;
            start_col--;
        }
        row++;
    }
    return seam_energy;
}

void findMinVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height, unsigned int seam[]) {
    unsigned int min_energy = numeric_limits<unsigned int>::max();
    for (unsigned int col = 0; col < width; col++) {
        unsigned int current_seam[MAX_HEIGHT];
        unsigned int current_seam_energy = loadVerticalSeam(image, col, width, height, current_seam);
        if (current_seam_energy < min_energy) {
            min_energy = current_seam_energy;
            for (unsigned int row = 0; row < height; row++) {
                seam[row] = current_seam[row];
            }
        }
    }
}

void removeVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int& width, unsigned int height, unsigned int verticalSeam[]) {
    unsigned int j = 0;
    do {
        unsigned int i = verticalSeam[j];
        do {
            image[i][j] = image[i+1][j];
            i++;
        } while (i < width - 1);
        j++;
    } while (j < height);
    width--;
}

void loadImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int& width, unsigned int& height) {
  // TODO: implement (part 1)
}

void outputImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height) {
  // TODO: implement (part 1)
}

unsigned int energy(Pixel image[][MAX_HEIGHT], unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
  // TODO: implement (part 1)
  return 0;
}