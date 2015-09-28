#include <iostream>

using namespace std;

int main()
{
    int a[10];
    int *p;

    for (int i = 0; i < 10; i++) {
        a[i] = i;
    }

    p = a;

    for (int i = 0; i < 10; i++) {
        cout << p[i] << endl;
    }

    return 0;
}
