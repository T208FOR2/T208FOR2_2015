#include <iostream>

using namespace std;

int main()
{
    int a = 0;
    int teljari = 0;

    while (a < 10 && teljari < 3) {
        int a = 0;

        cin >> a;
        cout << "\"" << a << "\"" << endl;

        teljari++;
    }
    cout << a << endl;

    return 0;
}
