#include <iostream>

using namespace std;

int main()
{
    int tala1 = 42, tala2 = 23;
    int *p1, *p2;

    p1 = &tala1;
    p2 = &tala2;

    *p2 = *p1;

    *p1 = 17;

    cout << tala1 << " - " << tala2 << endl;

    return 0;
}
