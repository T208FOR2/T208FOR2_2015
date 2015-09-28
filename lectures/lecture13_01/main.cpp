#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int *p;
    p = new int[n];

    while (true) {
        p = new int[1000000];

        cout << "Hi!" << endl;
    }

    for (int i = 0; i < n; i++) {
        p[i] = i;
    }

    for (int i = 0; i < n; i++) {
        cout << p[i] << endl;
    }

    delete [] p;

    return 0;
}
