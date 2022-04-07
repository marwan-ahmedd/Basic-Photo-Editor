// FCI – Programming 1 – 2022 - Assignment 3 
// Program: functions-file.cpp
// Last Modification Date: 4/4/2022
// Purpose: A Menu with the option to load an image and select within 12 filters and save the new file.
// Author1 and ID and Group: MarwanAhmed 20210377 A
// Author2 and ID and Group: Mohamed Waleed Mohamed Abd El-Wahab 20210363 A
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
void mirrorImage (){
  
    string option;
    cout << "Choose which side to mirror\n1-Right side\n2-Left side\n3-Upper side\n4-Bottom side\n";
    cin >> option;
    
    if (option == "1")
    {
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){
                    image1[i][j] = image1[i][255 - j];
                }
            }
    }
    if (option == "2")
    {
        for (int i = 255; i > 0; i--){
            for (int j = 255; j > 0; j--){
                    image1[i][j] = image1[i][255 - j];
                }
            }
    }
    if (option == "3")
    {
        for (int i = 255; i > 0; i--){
            for (int j = 255; j > 0; j--){
                    image1[i][j] = image1[255 - i][j];
                }
            }
    }
    if (option == "4")
    {
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){
                    image1[i][j] = image1[255 - i][j];
                }      
            }
    }
}

//_________________________________________
void rotateImage(){
  int degree, k;
  jump: ;
  cout << "Rotate (90), (180) or (360) degrees? ";
  cin >> degree;
  if (degree % 90 == 0)
  {
    k = degree / 90;
  }
  else{
    cout << "Invalid degree." << endl;
    goto jump;
  }

  for (int i = 0; i < k; i++)   // loops until the amount of rotates end
  {
    for (int i = 0; i < SIZE; ++i)
    {
      for (int j = i; j < SIZE; ++j)
      {
        if (i != j)   // saves time by skipping the ones transposing itself
        {
          swap (image1[i][j], image1[j][i]);  // transposing the matrix
        }
      }
    }

    for (int i = 0; i < SIZE; ++i)
    {
      for (int j = 0; j < SIZE/2; ++j)   // Size divided by 2 because we 2 steps not 1
      {
        swap (image1[i][j], image1[i][SIZE -1-j]);  // Flip horizontally
      }
    }
  }
}

//_________________________________________
void darkANDLight(){
  char choice;
  cout << "Do you want to (d)arken or (l)ighten? ";
  cin >> choice;
  if (choice == 'd' || choice == 'D')
  {
    int num = 0;
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        int result = 0;
        num = image1[i][j];
        result = num / 2;

        num -= (result);
        if (num < 0)
        {
          image1[i][j] = 0;
        }
        else
          image1[i][j] = num;
      }
    }
  }

  else if (choice == 'l' || choice == 'L')
  {
    int num = 0;
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) 
      {
        int result = 0;
        num = image1[i][j];
        result = num / 2;
        if (result < 50)
          result = 100;
        num += (result);

        if (num > 255)
        {
          image1[i][j] = 250;
        }
        else
          image1[i][j] = num;
	    }
	}
  }
}
int main()
{
    char choice;
    cout << "Ahlan ya user ya habibi \2" << endl;
    loadImage ();
    
    while (true)
    {
    cout << "\nPlease select a filter to apply or 0 to exit:\n" << endl;
    cout << "1- Black & White Filter\n" << endl;
    cout << "2- Invert Filter\n" << endl;
    cout << "3- Merge Filter\n" << endl;
    cout << "4- Mirror Image\n" << endl;
    cout << "5- Rotate Image\n" << endl;
    cout << "6- Darken and Lighten Image\n" << endl;
    cout << "s- Save the image to a file\n" << endl;
    cout << "0- Exit\n" << ">> ";
    cin >> choice;

    switch (choice){
      case '1':    
        BWImage();
      cout << "Filter applied successfully !" << endl;
        break;
      case '2':
        invertImage();
        cout << "Filter applied successfully !" << endl;
        break;
      case '3':
        mergeImage();
        cout << "Filter applied successfully !" << endl;
        break;
      case '4':
        mirrorImage();
        cout << "Filter applied successfully !" << endl;
        break;
      case '5':
        rotateImage();
        cout << "Filter applied successfully !" << endl;
        break;
      case '6':
        darkANDLight();
        cout << "Filter applied successfully !" << endl;
        break;
      case 's':
        saveImage();
        break;
      case '0':
        cout << "Program Ended.";
        return 0;
      default:
        break;
    }
  }
}