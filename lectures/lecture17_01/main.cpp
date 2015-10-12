#include <iostream>

using namespace std;

class Timi {
public:
    int minutur;
    int klst;
};


int main()
{
    Timi t1;

    t1.klst = 13;
    t1.minutur = 21;

    cout << t1.klst << ":" << t1.minutur << endl;

    return 0;
}
