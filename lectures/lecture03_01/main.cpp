#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    bool success = (a % b == 0);

    if (success) {
        cout << "yes!" << endl;
    }
    else {
        cout << "no" << endl;
    }

    return 0;
}
