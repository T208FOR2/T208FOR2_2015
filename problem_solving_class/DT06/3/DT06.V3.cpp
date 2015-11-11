//
//  main.cpp
//  DT07.verkefni3
//
//  Created by Silja Guðbjörg Tryggvadóttir on 29/09/15.
//  Copyright (c) 2015 siljagudbjorg. All rights reserved.
//

/*  Búið til fallið maxinrows sem tekur inn tvívítt fylki ásamt fjölda dálka og raða, og skilar til baka einvíðu kviku fylki (dynamic array) sem inniheldur stærsta gildið í hverri röð úr upprunalega fylkinu. Búið einnig til aðalfall (main function) sem býr til tvívítt fylki af heiltölum og lætur notanda skrá inn tölur í fylkið. Notið kvikt fylki til að geyma tölurnar. Fallið á að spyrja notanda um fjölda raða og dálka sem eiga að vera í fylkinu. Þegar búið er að fylla inn upplýsingar í fylkið er kallað á fallið maxinrows til að finna stærstu tölur í hverri röð og þær birtar á skjá. Að lokum á aðalfallið að nota delete skipunina til að eyða kviku breytunum.
 */

#include <iostream>

using namespace std;

int *maxInRows(int **array, int n, int m);

int main()
{
    int rows = 0, columns = 0;
    
    cout << "Enter the size of the array, number of rows and columns: " << endl;
    cin >> rows >> columns;
    cout << endl << "Enter integers for the array: " << endl;
    
    int **array;
    array = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        array[i] = new int[columns];
    }
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> array[i][j];
        }
    }
    
    cout << endl << "Maximum values in your array: " << endl;
    
    int *maxRowsArr = maxInRows(array, rows, columns);
    
    for (int i = 0; i < rows; i++)
    {
        cout << maxRowsArr[i] << endl;
    }
    
    for (int i = 0; i < rows; i++)
    {
        delete [] array[i];
    }
    delete [] array;

    delete[] maxRowsArr;
    
    return 0;
}

int *maxInRows(int **array, int n, int m)
{
    int* maxArray;
    maxArray = new int[n];
    
    for (int i = 0; i < n; i++)
    {
        maxArray[i] = array[i][0];
        for (int j = 1; j < m; j++)
        {
            if (maxArray[i] < array[i][j])
            {
                maxArray[i] = array[i][j];
            }
        }
    }
    return maxArray;
}