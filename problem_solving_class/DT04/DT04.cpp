//
//  main.cpp
//  DT05.verkefni1
//
//  Created by Silja Guðbjörg Tryggvadóttir on 14/09/15.
//  Copyright (c) 2015 siljagudbjorg. All rights reserved.
//

#include <iostream>

using namespace std;

void createArray(int arr[]); // Fall sem bidur notanda um #NUM heiltolur og vistar thaer i fylkid
void reverseArray(int arr[]); // Snyr fylkinu vid t.a. 4 - 3 - 2 - 1 verdur 1 - 2 - 3 - 4
// void reverseArray2(int arr[]); // Snyr fylkinu vid a annan hatt
void printArray(int arr[]); // Prentar ut stokin i fylkinu
int maxValue(int arr[]); // Finnur haesta gildid i fylkinu og skilar thvi
int minValue(int arr[]); // Finnur laegsta gildid i fylkinu og skilar thvi

// Skilgreinum fasta fyrir staerd fylkisins, tha thurfum vid bara ad breyta a einum stad ef vid viljum adra staerd
const int NUM = 10;

int main()
{
    int array[NUM], maxval = 0, minval = 0;
    
    createArray(array);
    cout << "Your array: " << endl;
    printArray(array); // Prentum fylkid sem notandi slo inn
    
    reverseArray(array);
    cout << "Your array reversed: " << endl;
    printArray(array); // Prentum vidsnuid fylki og sjaum muninn
    
    /* reverseArray2(array);
    cout << "Your array reversed: " << endl;
    printArray(array); */
    
    maxval = maxValue(array);
    minval = minValue(array);
    
    cout << "Maximum value: " << maxval << endl;
    cout << "Minimum value: " << minval << endl;
    
    return 0;
}

void createArray(int arr[])
{
    cout << "Please enter 10 integers: " << endl;
    
    for (int i = 0; i < NUM; i++) // ATH vid forum fra 0 upp i 9 thvi staerd fylkisins er 10
    {
        cin >> arr[i];
    }
}

void reverseArray(int arr[])
{
    int tmp; // Breyta til ad geyma stakid sem vid erum ad vinna med
    
    for (int i = 0; i < NUM/2; i++)
    {
        // Yfirskrifum alltaf tvo stok i hverri keyrslu, s.s. i fyrstu itrun breytum vid staki nr.0  og nr.NUM-1
        tmp = arr[i];
        arr[i] = arr[NUM-1-i];
        arr[NUM-1-i] =  tmp;
    }
}

/*void reverseArray2(int arr[])
 {
    int tmp[NUM];
 
    for (int i = 0; i < NUM; i++)
    {
        tmp[i] =  arr[NUM-i-1];
    }
 
    for (int i = 0; i < NUM; i++)
    {
        arr[i] = tmp[i];
    }
 }*/



void printArray(int arr[])
{
    for (int i = 0; i < NUM - 1; i++)
    {
        cout << arr[i] << " | "; // Prentum stokin med striki a milli (nema seinasta stakid)
    }
    cout << arr[NUM - 1] << endl << endl; // Seinasta stakid
}

int maxValue(int arr[])
{
    int max = arr[0];
    
    for (int i = 0; i < NUM; i++) // Itrum i gegnum oll stokin til ad finna staersta stakid
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    
    return max;
}
    
int minValue(int arr[])
{
    int min = arr[0];
    
    for (int i = 0; i < NUM; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    
    return min;
}