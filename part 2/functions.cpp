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

// uncomment functions as you implement them (part 2)

unsigned int loadVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int start_col, unsigned int width, unsigned int height, unsigned int seam[]) {


int* findMinVerticalSeam(const Pixel* const* image, int width, int height) {
    int* candidateSeam = new int[height] {0};
    int* minSeam = new int[height] {0};
    int i = 0;
    int col = 1;
    int minDist = getVerticalSeam(image, 0, width, height, minSeam);
    int candidateDistance = -1;

    do {
        candidateDistance = getVerticalSeam(image, col, width, height, candidateSeam);
        if(nullptr == minSeam){
          int a = 4;
        }
        else (candidateDistance < minDist) {
            minDist = candidateDistance;
            int* temp = candidateSeam;
            candidateSeam = minSeam;
            minSeam = temp;
        }

        col++;
    } while (col < width);

    delete[] candidateSeam;
    return minSeam;
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




