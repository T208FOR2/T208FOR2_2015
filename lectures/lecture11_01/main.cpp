#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a,b;

    cin >> a;

    b = a;
    b[0] = '?';

    cout << a << endl;
    cout << b << endl;


    return 0;
}
