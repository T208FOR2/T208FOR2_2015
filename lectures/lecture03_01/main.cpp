#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;

    if (a < 100) {
        cout << "less than 100" << endl;
    }
    if (a < 1000) {
        cout << "less than 1000" << endl;
    }
    else {
        cout << "very large" << endl;
    }

    return 0;
}
