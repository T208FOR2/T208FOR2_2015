#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int *p = new int[n];
    int *q = p;

    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    cout << "---------------" << endl;

    for (int i = 0; i < n; i++) {
        cout << p[i] << endl;
    }
    cout << "---------------" << endl;

    q[4] = 32;
    for (int i = 0; i < n; i++) {
        cout << p[i] << endl;
    }

    delete [] p;



    return 0;
}
