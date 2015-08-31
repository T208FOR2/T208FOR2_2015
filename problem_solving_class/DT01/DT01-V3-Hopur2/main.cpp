//
//  main.cpp
//  DT02.verkefni3
//
//  Created by Silja Guðbjörg Tryggvadóttir on 24/08/15.
//  Copyright (c) 2015 siljagudbjorg. All rights reserved.
//

#include <iostream>
using namespace std;


int main()
{
    int number, count = 2;
    
    cout << "Enter a number: " << endl;
    cin >> number;
    
    while (count <= number/2)
    {
        if (number % count == 0)
        {
            cout << number << " is not a prime number!" << endl;
            return 0;
        }
        count++;
    }
    
    cout << number << " is a prime number!" << endl;
    
    return 0;
}