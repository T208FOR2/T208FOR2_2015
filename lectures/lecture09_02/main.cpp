#include <iostream>

//Lesa 5 heiltolur af lyklabordi og prenta ’ ofugri rod

using namespace std;

int main()
{
    int tolur[5];
    cout << "Please write 5 numbers: ";

    for (int i = 0; i < 5; i++) {
        cin >> tolur[i];
    }

    return 0;
}
