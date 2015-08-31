#include <iostream>

using namespace std;

int main()
{
    int a = 0;

    while (true) {
        a++;

        if (a % 2 == 1) {
            continue;
        }

        cout << a << endl;

        if (a > 10) {
            break;
        }
    }

    cout << a << endl;

    return 0;
}
