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

    void reverseprint(Numbers num);
}


int main() {
    using namespace stable;
    using namespace beta;

    Numbers thenumbers;

    for (int j = 0; j < 100; j++)
    {
        thenumbers.add(j);
    }

    beta::dummyfunction(thenumbers);
    reverseprint(thenumbers);

    cout << "Hi!" << endl;

    return 0;
}

namespace beta {
    void reverseprint(Numbers num) {
        for (int i = num.getsize() - 1; i >= 0; i--) {
            cout << num[i] << " ";
        }
        cout << endl;
    }
}

