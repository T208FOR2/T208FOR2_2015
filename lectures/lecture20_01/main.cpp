#include <iostream>
#include "Numbers.h"

using namespace std;

namespace stable {
    void dummyfunction(Numbers num) {
        cout << num << endl;
    }
}

namespace beta {
    void dummyfunction(Numbers num) {
        for (int i = 0; i < num.getsize(); i++) {
            cout << num[i] << endl;
        }
        cout << endl;
    }
}

int main() {
    Numbers thenumbers;

    for (int j = 0; j < 100; j++)
    {
        thenumbers.add(j);
    }

    dummyfunction(thenumbers);

    cout << "Hi!" << endl;

    return 0;
}


