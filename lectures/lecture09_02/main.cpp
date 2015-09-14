#include <iostream>

//Lesa 5 heiltolur af lyklabordi og prenta ’ ofugri rod

using namespace std;

void dosomething(int a[], int n);

int main()
{
    int tolur[5];
    cout << "Please write 5 numbers: ";

    for (int i = 0; i < 5; i++) {
        cin >> tolur[i];
    }

    dosomething(tolur, 5);

    for (int i = 0; i < 5; i++) {
        cout << tolur[i] << endl;
    }

    return 0;
}

void dosomething(int a[], int n) {
    for (int i = 0; i < 5; i++) {
        a[i] = 42;
    }
}


