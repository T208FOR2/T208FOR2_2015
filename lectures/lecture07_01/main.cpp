#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cctype>

using namespace std;

void clearcin();

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

    clearcin();
    cout << "Press Enter to continue." << endl;
    cin.get();

    return 0;
}

void clearcin() {
    char takn;
    takn = cin.get();
    while (takn != '\n') {
        takn = cin.get();
    }
}
