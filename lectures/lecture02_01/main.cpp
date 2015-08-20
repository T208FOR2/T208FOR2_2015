#include <iostream>

using namespace std;

int main()
{
    cout << endl;
    int a = INT_MAX;

    cout << a << endl << endl;
    cout << a - 2 << endl;
    cout << a - 1 << endl;
    cout << a << endl;
    cout << a + 1 << endl;

    unsigned int b = 0;
    cout << b << endl;
    cout << b-1 << endl << endl;

    long long c = LONG_LONG_MAX;
    cout << c << endl << endl;

    double d = 0.1;
    cout << d << endl;
    cout.precision(20);
    cout << d << endl;
    cout << d + 0.000000000000000001 << endl;

    cout << endl;
    return 0;
}
