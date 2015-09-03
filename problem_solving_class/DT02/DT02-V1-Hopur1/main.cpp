#include <iostream>

using namespace std;

int getNumb();

void printResult(int UserNumb, int UserNumbrev);

bool sameNumb(int tala1, int tala2);

int palindrome(int UserNumb);


int main()
{
    int UserNumb = getNumb();
    int UserNumbrev = palindrome(UserNumb);
    printResult(UserNumb, UserNumbrev);
}


int getNumb()
{
    int tala;
    cout << "Please enter a number" << endl;
    cin >> tala;
    return tala;
}

bool sameNumb(int tala1, int tala2)
{
    if(tala1 == tala2)
    {
        return true;
    }
    return false;
}

void printResult(int UserNumb, int UserNumbrev)
{
    if(sameNumb(UserNumb, UserNumbrev))
    {
        cout << UserNumb << " is a palindrome number" << endl;
    }
    else
    {
        cout << UserNumb << " is not a palindrome number" << endl;
    }
}

int palindrome(int UserNumb)
{
    int UserNumbrev = 0;
    int remainder = 0;

    while(UserNumb >= 1)
    {
        remainder = UserNumb % 10;
        UserNumbrev = ((UserNumbrev*10) + remainder);
        UserNumb = UserNumb/10;
    }

    return UserNumbrev;

}
