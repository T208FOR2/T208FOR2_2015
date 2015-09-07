#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cctype>

using namespace std;

int main()
{
    int tala;
    string texti;
    char takn;

    cout << "Please write something:" << endl;

    takn = cin.get();
    cin.putback('X');

    if (isdigit(takn)) {
        cin >> tala;
        cout << "You wrote a number: " << tala << endl;
    }
    else if (isalpha(takn)) {
        cin >> texti;
        cout << "You wrote some text: " << texti << endl;
    }
    else {
        cin >> texti;
        cout << "I have no idea what this is: " << texti << endl;
    }

    return 0;
}
