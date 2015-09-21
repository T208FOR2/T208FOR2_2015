#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string fnafn, enafn;
    int ar;

    cin >> fnafn >> enafn >> ar;

    for (int i = 0; i < enafn.length(); i++) {
        enafn[i] = tolower(enafn[i]);
    }

    fnafn[0] = tolower(fnafn[0]);
    cout << fnafn[0] << enafn << ar % 100 << "@gmail.com" << endl;

    return 0;
}
