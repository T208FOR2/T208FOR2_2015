#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a,b;

    cin >> a >> b;

    if (a <= b) {
        cout << a << " is before " << b << endl;
    }
    else {
        cout << a << " is after " << b << endl;
    }

    return 0;
}
