void mergeImage ()
{
    char imageFileName[100];
    unsigned char img2[SIZE][SIZE];

    // Get gray scale image file name
    cout << "Enter the second image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, img2);

    // Assigning the average of pixels
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            img[i][j] = (img2[i][j] + img[i][j])/2;
        }
    }
}
//------------------------------------------

void darkANDLight()
{
    char choice;
    cout << "Do you want to (d)arken or (l)ighten? ";
    cin >> choice;

    if (choice == 'd' || choice == 'D')
    {
        int num = 0;
        for (int i = 0; i < SIZE; i++) 
        {
            for (int j = 0; j < SIZE; j++) 
            {
                int result = 0;
                num = img[i][j];
                result = num / 2;

                num -= (result);
                if (num < 0)
                {
                    img[i][j] = 0;
                }
                else
                    img[i][j] = num;
            }
        }
    }

    else if (choice == 'l' || choice == 'L')
    {
        int num = 0;
        for (int i = 0; i < SIZE; i++) 
        {
            for (int j = 0; j < SIZE; j++) 
            {
                int result = 0;
                num = img[i][j];
                result = num / 2;

                if (result < 50)
                    result = 100;
                num += (result);

                if (num > 255)
                {
                    img[i][j] = 250;
                }
                else
                    img[i][j] = num;
            }
        }
    }
}

//------------------------------------------
void shrinkImage()
{

}

//------------------------------------------
void blurImage()
{

}
