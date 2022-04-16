unsigned char temp[4][SIZE/2][SIZE/2] = {};
unsigned char quarter[(SIZE/2)*(SIZE/2)] = {};

//---------------------------------------------
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
        case 1:         // First Quarter
            istart = 0;
            iend = SIZE/2;
            jStart = 0;
            jEnd = SIZE/2;
            break;
        case 2:         // Second Quarter
            istart = 0;
            iend = SIZE/2;
            jStart = SIZE/2;
            jEnd = SIZE;
            break;
        case 3:         // Third Quarter
            istart = SIZE/2;
            iend = SIZE;
            jStart = 0;
            jEnd = SIZE/2;
            break;
        case 4:         // Fourth Quarter
            istart = SIZE/2;
            iend = SIZE;
            jStart = SIZE/2;
            jEnd = SIZE;
            break;
        default:        // Number > 4 or Number < 1
            cout << "Invalid Number." << endl;
            goto jump;
   }
   for (int i = 0, pos_i = istart; i < SIZE && pos_i < iend; i += 2, pos_i++)
   {
        for (int j = 0, pos_j = jStart; j < SIZE && pos_j < jEnd; j += 2, pos_j++)
        {               // Duplicates each pixel 4 times
            img[i][j] = img[pos_i][pos_j];
            img[i + 1][j] = img[pos_i][pos_j];
            img[i][j + 1] = img[pos_i][pos_j];
            img[i + 1][j + 1] = img[pos_i][pos_j];
        }
   }
}

//---------------------------------------------
void extractQuarter(unsigned char * & ptr, int quarter) {
    int startRow = 0, endRow = SIZE/2, startCol = 0, endCol = SIZE/2;
    // Determine boundries according to quarter
    if (quarter == 2) {
        startCol = SIZE / 2;
        endCol = SIZE;
    }
    else if (quarter == 3) {
        startRow = SIZE / 2;
        endRow = SIZE;
    }
    else if (quarter == 4) {
        startRow = SIZE / 2;
        startCol = SIZE / 2;
        endRow = SIZE;
        endCol = SIZE;
    }
    if (quarter < 1 or quarter > 4)
        cout << "Unrecognized quarter!\n";
    
    int k = 0;
    for (int i = startRow; i < endRow; i++) {
        for (int j = startCol; j < endCol; j++) {
            ptr[k++] = img[i][j];
        }   // Due to the squential organization of memory we can               
    }       // store the image row-by-row with a single iterator(m)
}

//---------------------------------------------
void shuffleImage() {
    string order;
    unsigned char *pQuarter = quarter; // Point at a quarter-sized 2D array to store a quarter into.
    unsigned char *pTemp = &temp[0][0][0]; // Point at temp 3D array (divided into 4 quarters)
    int k = 0;
    cout << "New order of quarters ?\n";
    cin.ignore(); // For getline() to work properly
    getline(cin, order);
    // Shuffle process:                       
    for (int i = 0; i < order.length(); i++) 
    {                       // Fill a temp. array with the shuffled image
        if (order[i] == ' ') {                 // a quarter per iteration
            continue; 
        } 
        extractQuarter(pQuarter, (int) (order[i] - '0'));
        for (int j = 0; j < ((SIZE * SIZE) / 4); j++) {
            pTemp[k] = pQuarter[j]; // Store extracted-quarter[original] inside current quarter[temp]
            k++;
        }
    }
    // Transfer temp. array into original image.
    int qrtr = 0, row = 0, col = 0;
    for (int i = 0; i < SIZE; i++) { // Store a 3D array into a 2D array
        if (i == SIZE / 2) {
            qrtr += 2; // Go to next half (Vertically)
            row = 0;
        }
        col = 0;
        for (int j = 0; j < SIZE; j++) {
            if (j == SIZE / 2) {
                qrtr++; // Go to next quarter(Horizontally), same row
                col = 0;
            }
            img[i][j] = temp[qrtr][row][col];
            col++;
        }
        qrtr--; // Go back to previous quarter(Horizontally), new row
        row++;
    }
}
