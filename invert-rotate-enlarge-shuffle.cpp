
// unsigned char img2[(SIZE)*(SIZE)] = {};
void invertImage () 
{
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            img[i][j] = 255 - img[i][j];
        }
    } 
}

//---------------------------------------------
void rotateImage(){
    int degree, m;
    jump: ;
    cout << "Rotate (90), (180) or (360) degrees? ";
    cin >> degree;
    if (degree % 90 == 0)
    {
        m = degree / 90;
    }
    else{
        cout << "Invalid degree." << endl;
        goto jump;
    }

    // for (int i = 0; i < SIZE; i++)
    // {
    //     for (int j = 0; j < SIZE; j++)
    //     {
    //     image2[i][j] = image1[i][j];
    //     }
    // }

    for (int i = 0; i < m; i++)   // loops until the amount of rotates end
    {
        for (int i = 0; i < SIZE; ++i)
        {
        for (int j = i; j < SIZE; ++j)
        {
            if (i != j)   // saves time by skipping the ones transposing itself
            {
            swap (img[i][j], img[j][i]);  // transposing the matrix
            }
        }
        }

    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE/2; ++j)   // Size divided by 2 because we 2 steps not 1
        {
            swap (img[i][j], img[i][SIZE -1-j]);  // Flip horizontally
        }
    }
  }
}

//---------------------------------------------
void enlargeImage()
{
    int choice, istart, iend, jStart, jEnd;
    jump: ;
    cout << "Which quarter to enlarge 1, 2, 3 or 4? ";
    cin >> choice;
    switch (choice)
    {
        case 1:
            istart = 0;
            iend = SIZE/2;
            jStart = 0;
            jEnd = SIZE/2;
            break;
        case 2:
            istart = 0;
            iend = SIZE/2;
            jStart = SIZE/2;
            jEnd = SIZE;
            break;
        case 3:
            istart = SIZE/2;
            iend = SIZE;
            jStart = 0;
            jEnd = SIZE/2;
            break;
        case 4:
            istart = SIZE/2;
            iend = SIZE;
            jStart = SIZE/2;
            jEnd = SIZE;
            break;
        default:
            cout << "Invalid Number." << endl;
            goto jump;
   }
   for (int i = 0, pos_i = istart; i < SIZE && pos_i < iend; i += 2, pos_i++)
   {
        for (int j = 0, pos_j = jStart; j < SIZE && pos_j < jEnd; j += 2, pos_j++)
        {
            img[i][j] = img[pos_i][pos_j];
            img[i + 1][j] = img[pos_i][pos_j];
            img[i][j + 1] = img[pos_i][pos_j];
            img[i + 1][j + 1] = img[pos_i][pos_j];
        }
   }
}

//---------------------------------------------
void shuffleImage()
{

}
