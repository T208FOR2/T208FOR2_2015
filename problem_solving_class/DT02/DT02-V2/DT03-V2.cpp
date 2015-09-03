//
//  main.cpp
//  DT03.verkefni2
//
//  Created by Silja Guðbjörg Tryggvadóttir on 31/08/15.
//  Copyright (c) 2015 siljagudbjorg. All rights reserved.
//

#include <iostream>
using namespace std;

// Fall sem athugar hvort tala se frumtala eda ekki, skilar true(1) eda false(0)
bool isPrime(int number);

int main()
{
    int number;
    cin >> number;
    
    if (number <= 0)
    {
        cout << 0 << endl;
        return 0;
    }
    
    bool primeNum;
    primeNum = isPrime(number);
    
    // Her er talan ekki frumtala og tvi frumtattum vid hana
    if (!primeNum)
    {
        // Keyrum for-lykkju sem byrjar ad athuga hvort 2 se frumthattur
        for (int i = 2; i <= number; i++)
        {
            // Ef deiling med frumtaetti gengur upp prentum vid ut frumthattinn med kommu eda an kommu
            if (number % i == 0)
            {
                if (number == i)
                {
                    cout << i << endl;
                }
                else
                {
                    cout << i << ", ";
                }
                // Breytum tolunni i nidurstodu deilingarinnar og finnum thannig naesta frumthatt
                number /= i;
                // Laekkum fyrst i til ad prenta orugglega alla frumtaettina, t.d. ef talan er tvideilanleg med vidkomandi frumtaetti
                i--;
            }
        }
    }
    // Her er talan frumtala og vid prentum hana thvi ut gildir baedi fyrir 1 og adrar frumtolur
    else
    {
        cout << number << endl;
    }
    
    return 0;
}

bool isPrime(int number)
{
    for (int i = 2; i <= number/2; i++)
    {
        // Ef talan er 4 eda haerri fer hun i gegnum for-lykkjuna, ef hun er deilanleg med einhverri tolu er hun ekki frumtala og fallid skilar false(0) gildi
        if (number % i == 0)
        {
            return false;
        }
    }
    // Ef talan er 1, 2 eda 3 eda onnur frumtala forum vid hingad og fallid skilar true(1) gildi
    return true;
}