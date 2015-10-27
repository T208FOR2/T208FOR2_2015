/* Verkefni 1 */
#include <iostream>
#include "DoubleArray.h"

using namespace std;



int main()
{
    DoubleArray DA1, DA2(5, 3.7);
    cout << DA2 << endl;

    cin >> DA1;
    cout << DA1 << endl;

    if(DA1 > DA2) {
        cout << "DA1 has the higher average!" << endl;
    } else {
        cout << "DA2 has the higher average!" << endl;
    }

    cout << "DA1 + DA2 = " << DA1 + DA2 << endl;
    return 0;
}
