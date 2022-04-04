// FCI – Programming 1 – 2022 - Assignment 3 
// Program: functions-file.cpp
// Last Modification Date: 4/4/2022
// Purpose: A Menu with the option to load an image and select within 12 filters and save the new file.
// Author1 and ID and Group: MarwanAhmed 20210377 A
// Author2 and ID and Group: xxxxx xxxxx
// Author3 and ID and Group: xxxxx xxxxx
  


#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <math.h>
#include "bmplib.cpp"
#include "bmplib.h"

using namespace std;
unsigned char image1[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];


//_________________________________________
void loadImage ()
{
  char imageFileName[100];

   // Get gray scale image target file name
   cout << "Please enter file name of the image to process: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image1);
}

//_________________________________________
void saveImage () 

{
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image1);
   cout << "File has been created !" << endl;
}

//_________________________________________
void BWImage (){
    int average = 0;

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++)
        {
            average += image1[i][j];
        }
    }

    average /= (SIZE * SIZE);

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++)
        {
            if(image1[i][j] > average)
                image1[i][j] = 255;
            else
                image1[i][j] = 0;
        }
    }
}

//_________________________________________
void invertImage () 
{
  for (int i = 0; i < SIZE; i++) 
  {
    for (int j = 0; j < SIZE; j++) 
    {
        image1[i][j] = 255 - image1[i][j];
    }
  } 
}

//_________________________________________
void mergeImage ()
{
  char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the second image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image2);

   // Assigning the average of pixels
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      image1[i][j] = (image1[i][j] + image2[i][j])/2;
    }
  }
}

//_________________________________________
void flipImage (){

}

//_________________________________________
void rotateImage(){

  int degree, k;
    cout << "Rotate (90), (180) or (360) degrees? ";
    cin >> degree;
    if (degree % 90 == 0)
    {
      k = degree / 90;
    }
    else{
      cout << "Invalid degree. UnChanged file will be created" << endl;
      k = 0;
    }
    
    for (int i = 0; i < k; i++)   // loops until the amount of rotates end
    {
      for (int i = 0; i < SIZE; ++i)
      {
        for (int j = i; j < SIZE; ++j)
        {
          if (i != j)   // saves time by skipping the ones transposing itself
          {
            auto tmp = image1[i][j];
            image1[i][j] = image1[j][i];    // transpose the picture
            image1[j][i] = tmp;
          }
        }
      }

      for (int i = 0; i < SIZE; ++i)
      {
        for (int j = 0; j < SIZE/2; ++j)   // Size divided by 2 because we 2 steps not 1
        {
          auto tmp = image1[i][j];
          image1[i][j] = image1[i][SIZE-1-j];   // Flip horizontally
          image1[i][SIZE-1-j] = tmp;
        }
      }
    }
}

//_________________________________________
void darkANDLight(){

}
