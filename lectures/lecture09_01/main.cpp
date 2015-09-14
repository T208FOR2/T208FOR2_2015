#include <iostream>
#include <string>

using namespace std;

const int NUM = 10;

int main()
{
    int a[NUM];
    string texti[3];

    for (int i = 0; i < NUM+1; i++) {
        a[i] = i+1;
    }

    texti[0] = "this";
    texti[1] = "is";
    texti[2] = "something";

    for (int i = 0; i < NUM+1; i++) {
        cout << "Element " << i << " = " << a[i] << endl;
    }

    cout << texti[0] << " - " << texti[1] << " - " << texti[2] << endl;

    return 0;
}
