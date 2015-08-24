#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    bool success = true;

    success = (a % b == 0);

    if (((a % b == 0) && (a % 2 == 0) && (b >= 0)) || (a < b)) {
        cout << "yes!" << endl;
    }
    else {
        cout << "no" << endl;
    }

    return 0;
}
