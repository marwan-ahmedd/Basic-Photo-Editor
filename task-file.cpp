// Program: Filters.cpp
// Purpose: 
// Author:  
// Date:   
// Version: 1.0

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <math.h>
#include "bmplib.cpp"
#include "bmplib.h"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image1[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];


void loadImage ();
void saveImage ();
void BWImage ();
void invertImage ();
void mergeImage ();
void flipImage ();
void rotateImage();
void darkANDLight();



int main()
{
  loadImage();
  BWImage(); // Done (Mohamed)
  // invertImage(); // Done (Marwan)
  // mergeImage(); // Done (Abo Khalifa)
  // flipImage(); // (Mohamed)
  // rotateImage(); // (Marwan)
  // darkANDLight(); // (Abo Khalifa)
  // detectEdges(); // (Mohamed)
  // enlarge(); // (Marwan)
  // shrink(); // (Abo Khalifa)
  // mirror(); // (Mohamed)
  // shuffle(); // (Marwan)
  // blur(); // (Abo Khalifa)
  saveImage();
  return 0;
}

//_________________________________________
void loadImage ()
{
  char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the source image file name: ";
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
}

//_________________________________________
void BWImage (){
    int average = 0;

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++)
        {
            average += image[i][j];
        }
    }

    average /= (SIZE * SIZE);

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++)
        {
            if(image[i][j] > average)
                image[i][j] = 255;
            else
                image[i][j] = 0;
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

}

//_________________________________________
void darkANDLight(){

}
