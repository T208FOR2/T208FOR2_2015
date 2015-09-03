//
//  main.cpp
//  DT03.verkefni1
//
//  Created by Silja Guðbjörg Tryggvadóttir on 31/08/15.
//  Copyright (c) 2015 siljagudbjorg. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

// Fall sem biður notandann um heiltölu, les inn töluna og skilar tölunni.
int readNumberFromUser();

// Fall sem tekur inn tvær heiltölur og skilar true/false eftir því hvort tölurnar eru eins.
bool isEqual(int number1, int number2);

// Fall sem tekur inn heiltölu, snýr henni við og skilar til baka. T.d. ef fallið tekur inn
// töluna 1234 þá á niðurstaðan að vera 4321. Hér er gott að nota heiltöludeilingu
// og afgangsvirkjann.
int reverseNumber(int numberToReverse);

// Fall sem sér um að prenta niðurstöðuna á fallegan hátt.
void printResult(int numberToPrint, bool isPalindrome);


int main()
{
    int numberToCheck, numberReversed;
    bool palindrome;
    
    numberToCheck = readNumberFromUser();
    numberReversed = reverseNumber(numberToCheck);
    palindrome = isEqual(numberToCheck, numberReversed);
    printResult(numberToCheck, palindrome);
    
    return 0;
}

int readNumberFromUser()
{
    int number;
    cout << "Please enter an integer: ";
    cin >> number;
    
    return number;
}

bool isEqual(int number1, int number2)
{
    // Athugum hvort tölurnar eru thaer somu og skilum true eda false
    return (number1 == number2);
}

int reverseNumber(int numberToReverse)
{
    int remainder = 0;
    int newNumber = 0;
    
    while (numberToReverse != 0)
    {
        // Finnum afgang ur heiltoludeilingu sem verdur tha fyrsta talan i nyju tolunni
        remainder = numberToReverse % 10;
        // Faerum toluna i naesta tugasaeti og baetum afgangnum vid i einingasaetid
        newNumber = (newNumber * 10) + remainder;
        // Setjum toluna sem nidurstodu deilingarinnar, verdur 0 i lokin thvi vid erum ad vinna med heiltoludeilingu
        numberToReverse /= 10;
    }
    
    return newNumber;
}

void printResult(int numberToPrint, bool isPalindrome)
{
    if (isPalindrome)
    {
        cout << "The number " << numberToPrint << " is a palindrome!" << endl;
    }
    else
    {
        cout << "The number " << numberToPrint << " is not a palindrome!" << endl;
    }
}