#include <iostream>
#include <string>
using namespace std;


// Function decleration
int somefunction(int& tala1, int tala2, int& tala3);

int main()
{
    int a,b,c,d;
    cin >> a >> b >> c;
    cout << "MAIN: " << a << " " << b << " " << c << endl;

    d = somefunction(a,b,c);

    cout << "MAIN: " << a << " " << b << " " << c << " " << d << endl;

    return 0;
}

int somefunction(int& tala1, int tala2, int& tala3) {
    cout << "FUNCTION: " << tala1 << " " << tala2 << " " << tala3 << endl;

    tala1 = 42;
    tala2 = 23;
    tala3 = 5;

    cout << "FUNCTION: " << tala1 << " " << tala2 << " " << tala3 << endl;

    return 78;
}
