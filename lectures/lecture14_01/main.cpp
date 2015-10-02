#include <iostream>

using namespace std;

int* staekkafylki(int *p, int& n);

int main()
{
    int *fylki;
    int n = 2, currentnumber, usedelements = 0;

    fylki = new int[n];
    for (int i = 0; i < n; i++) {
        fylki[i] = 0;
    }

    cin >> currentnumber;
    while ( currentnumber >= 0 ) {
        fylki[ usedelements++ ] = currentnumber;

        if (usedelements == n) {
            fylki = staekkafylki(fylki, n);
        }

        cin >> currentnumber;
    }


    cout << "The numbers you wrote are: ";
    for (int i = 0; i < usedelements; i++) {
        cout << fylki[i] << " ";
    }
    cout << endl;

    delete [] fylki;

    return 0;
}

int* staekkafylki(int *p, int& n) {

    int* tmp = new int[2*n];
    for (int i = 0; i < 2*n; i++) {
        tmp[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        tmp[i] = p[i];
    }

    delete [] p;
    n = n*2;

    return tmp;
}
