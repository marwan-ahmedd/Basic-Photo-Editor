unsigned char img2[SIZE][SIZE];
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
    int num;
	cout << endl << "What size do you want to convert to \n Enter the number 2 , 3 or 4 \n"
		<< "2 - to convernt 1/2\n"
		<< "3 - to convernt 1/3\n"
		<< "4 - to convernt 1/4\n";
	cin >> num;

	for (int i = 0; i < SIZE / num; i++) {
		for (int j = 0; j < SIZE / num; j++) {
			img2[i][j] = img[i * num][j * num];
		}
	}
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; j++)
        {
            img[i][j] = img2[i][j];
        }
    }
}

//------------------------------------------
void blurImage()
{
    int n1;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			int result = 0;
			n1 = img[i][j];
			n1 += img[i][j + 1];
			n1 += img[i + 1][j];
			n1 += img[i + 1][j + 1];
			n1 += img[i][j + 2];
			n1 += img[i + 2][j];
			n1 += img[i + 1][j + 2];
			n1 += img[i + 2][j + 1];
			n1 += img[i + 2][j + 2];
			n1 += img[i + 3][j];
			n1 += img[i + 3][j + 1];
			n1 += img[i + 3][j + 2];
			n1 += img[i + 3][j + 3];
			n1 += img[i][j + 3];
			n1 += img[i + 1][j + 3];
			n1 += img[i + 2][j + 3];
			n1 += img[i][j + 4];
			n1 += img[i + 1][j + 4];
			n1 += img[i + 2][j + 4];
			n1 += img[i + 3][j + 4];
			n1 += img[i + 4][j + 4];
			n1 += img[i + 4][j];
			n1 += img[i + 4][j + 2];
			n1 += img[i + 4][j + 1];
			n1 += img[i + 4][j + 3];
			n1 += img[i][j + 5];
			n1 += img[i + 1][j + 5];
			n1 += img[i + 2][j + 5];
			n1 += img[i + 3][j + 5];
			n1 += img[i + 4][j + 5];
			n1 += img[i + 5][j + 5];
			n1 += img[i + 5][j];
			n1 += img[i + 5][j + 1];
			n1 += img[i + 5][j + 2];
			n1 += img[i + 5][j + 3];
			n1 += img[i + 5][j + 4];
			result = n1 / 36;
			img[i][j] = result;
		}
	}
}
