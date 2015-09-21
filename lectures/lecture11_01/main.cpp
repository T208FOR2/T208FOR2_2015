#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string fnafn, enafn;
    int ar;

    cin >> fnafn >> enafn >> ar;


    cout << tolower(fnafn[0]) << enafn << ar % 100 << "@gmail.com" << endl;

    return 0;
}
