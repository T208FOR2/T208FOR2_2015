#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    int b = 0;

    while (b < a) {
        cout << ++b << " - hello!" << endl;
    }

    return 0;
}

