void BWImage (){
    int average = 0;

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++)
        {
            average += img[i][j];
        }
    }

    average /= (SIZE * SIZE);

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++)
        {
            if(img[i][j] > average)
                img[i][j] = 255;
            else
                img[i][j] = 0;
        }
    }
}

//------------------------------------------
void flipImage()
{
    
    string option;

    cout << "Do you want to flip the image\n1- Vertically\n2- Horizontally\n";
    cin >> option;

    if(option == "1"){

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                img2[i][j] = img[i][255 - j];
            }
        }
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                img[i][j] = img2[i][j];
            }
        }
    }
    else if (option == "2"){

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                img2[i][j] = img[255 - i][j];
            }
        }
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                img[i][j] = img2[i][j];
            }
        }
    }
    
}


//------------------------------------------
void detectEdges()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (img[i][j] > (img[i + 1][j + 1] + 15) || img[i][j] > (img[i][j + 1] + 15) || img[i][j] > (img[i + 1][j] + 15) && img[i][j] != 255 ){

                img[i][j] = 0;
            }
            else{

                img[i][j] = 255;
            }   
        }
    }

}

//------------------------------------------
void mirrorImage ()
{
    string option;
    cout << "Choose which side to mirror\n1-Right side\n2-Left side\n3-Upper side\n4-Bottom side\n";
    cin >> option;

    if (option == "1")
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                img[i][j] = img[i][255 - j];
            }
        }
    }
    if (option == "2")
    {
        for (int i = 255; i > 0; i--)
        {
            for (int j = 255; j > 0; j--)
            {
                img[i][j] = img[i][255 - j];
            }
        }
    }
    if (option == "3")
    {
        for (int i = 255; i > 0; i--)
        {
            for (int j = 255; j > 0; j--)
            {
                img[i][j] = img[255 - i][j];
            }
        }
    }
    if (option == "4")
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                img[i][j] = img[255 - i][j];
            }      
        }
    }
}
