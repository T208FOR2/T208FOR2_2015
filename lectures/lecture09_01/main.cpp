#include <iostream>
#include <string>

using namespace std;

const int NUM = 10;

int main()
{
    int a[NUM];
    string texti[3];

    for (int i = 0; i < 2*NUM; i++) {
        a[i] = i+1;
    }

    texti[0] = "this";
    texti[1] = "is";
    texti[2] = "something";

    for (int i = 0; i < 2*NUM; i++) {
        cout << "Element " << i << " = " << a[i] << endl;
    }

    cout << texti[0] << " - " << texti[1] << " - " << texti[2] << endl;

    cout << texti[512] << endl;

    return 0;
}
