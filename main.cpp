#include <iostream>
#include "functions-file.cpp"
using namespace std;

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