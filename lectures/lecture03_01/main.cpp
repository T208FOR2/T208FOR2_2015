#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;

    if (a < 1000) {
        cout << "less than 1000" << endl;
    }
    else if (a < 100) {
        cout << "less than 100" << endl;
    }
    else {
        cout << "very small" << endl;
    }

    return 0;
}
