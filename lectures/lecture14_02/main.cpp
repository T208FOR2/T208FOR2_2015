#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int **p = new int*[n];
    for (int i = 0; i < n; i++) {
        p[i] = new int[m];
    }

    // Add numbers to the array
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            p[i][j] = k++;
        }
    }

    // print the array
        for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        delete [] p[i];
    }
    delete [] p;

    return 0;
}
