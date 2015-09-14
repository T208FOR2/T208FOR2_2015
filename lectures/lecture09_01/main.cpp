#include <iostream>
#include <string>

using namespace std;

const int NUM = 10;

int main()
{
    int a[NUM];
    char b[5][3];
    string texti[3];

    for (int i = 0; i < NUM; i++) {
        a[i] = i+1;
    }

    char tmp = 'a';
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            b[i][j] = tmp;
            tmp = tmp + 1;
        }
    }

    texti[0] = "this";
    texti[1] = "is";
    texti[2] = "something";

    for (int i = 0; i < NUM; i++) {
        cout << "Element " << i << " = " << a[i] << endl;
    }

    cout << texti[0] << " - " << texti[1] << " - " << texti[2] << endl;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 5; i++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
