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
    char takn, takn2;

    cout << "Please write something:" << endl;

    takn = cin.get();
    takn2 = cin.get();
    cin.putback(takn2);
    cin.putback(takn);

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
