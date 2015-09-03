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

// Fall sem gerir það sama og fallið fyrir ofan, nema aðeins önnur aðferð notuð
int reverseNumber2(int numberToReverse);

// Fall sem sér um að prenta niðurstöðuna á fallegan hátt.
void printResult(int numberToPrint, bool isPalindrome);

// Onnur utfaersla a printResault fallinu. Her er hinsvegar kallad a reverseNumber og isEqual follin
void printResult2(int number);


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

// Hin utfaerslan er betri thar sem einungis er ein while lykkja og forritid lengur ad keyra thetta fall.
int reverseNumber2(int numberToReverse)
{
    int remainder = 0;
    int newNumber = 0;
    int tugur = 1;
    
    // Finnum fyrst hversu mörg "tugasæti" talan hefur
    while(number > tugur * 10)
    {
        tugur = tugur * 10;
    }
    
    while (numberToReverse != 0)
    {
        // Finnum afgang ur heiltoludeilingu sem verdur tha fyrsta talan i nyju tolunni
        remainder = numberToReverse % 10;
        // Margfoldum afganginn með þeim "tug" sem á vid, t.d 1000 eða 100
        newNumber = newNumber + remainder*tugur;
        // Setjum toluna sem nidurstodu deilingarinnar, verdur 0 i lokin thvi vid erum ad vinna med heiltoludeilingu
        numberToReverse /= 10;
        // Laekkum tugasaetið um eitt, 1000 verdur ad 100 o.s.frv
        tugur = tugur / 10;
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

void printResult2(int number)
{
    // snuum tolunni vid
    int reversedNumber = reverseNumber(number);
    
    // athugum hvort tolurnar eru eins og prentum ut videigandi skilabod
    if (isEqual(number, reversedNumber))
    {
        cout << "The number " << numberToPrint << " is a palindrome!" << endl;
    }
    else
    {
        cout << "The number " << numberToPrint << " is not a palindrome!" << endl;
    }
}
