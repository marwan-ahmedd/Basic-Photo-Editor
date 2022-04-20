// FCI – Programming 1 – 2022 - Assignment 3 
// Program: functions-file.cpp
// Last Modification Date: 4/4/2022
// Purpose: A Menu with the option to load an image and select within 12 filters and save the new file.
// Author1 and ID and Group: Marwan Ahmed Abd El-Fatah 20210377 A
// Author2 and ID and Group: Mohamed Waleed Mohamed Abd El-Wahab 20210363 A
// Author3 and ID and Group: xxxxx xxxxx
  

#include <iostream>
#include "bmplib.h"
#include "bmplib.cpp"
unsigned char img[SIZE][SIZE];
unsigned char img2[SIZE][SIZE];
#include "invert-rotate-enlarge-shuffle.cpp"
#include "BW-flip-detect-mirror.cpp"
#include "merge-darkLight-shrink-blur.cpp"
using namespace std;

//_________________________________________
void loadImage ()
{
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Please enter file name of the image to process: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, img);
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
    writeGSBMP(imageFileName, img);
    cout << "File has been created !" << endl;
}

//_________________________________________
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
    cout << "4- Flip Image\n" << endl;
    cout << "5- Rotate Image\n" << endl;
    cout << "6- Darken and Lighten Image\n" << endl;
    cout << "7- Detect Image Edges\n" << endl;
    cout << "8- Enlarge Image\n" << endl;
    cout << "9- Shrink Image\n" << endl;
    cout << "a- Mirror 1/2 Image\n" << endl;
    cout << "b- Shuffle Image\n" << endl;
    cout << "c- Blur Image\n" << endl;
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
        flipImage();
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
      case '7':
        detectEdges();
        cout << "Filter applied successfully !" << endl;
        break;
      case '8':
        enlargeImage();
        cout << "Filter applied successfully !" << endl;
        break;
      case '9':
        shrinkImage();
        cout << "Filter applied successfully !" << endl;
        break;
      case 'a':
        mirrorImage();
        cout << "Filter applied successfully !" << endl;
        break;
      case 'b':
        shuffleImage();
        cout << "Filter applied successfully !" << endl;
        break;
      case 'c':
        blurImage();
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