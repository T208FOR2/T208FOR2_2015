#include <iostream>

using namespace std;

class Timi {
public:

private:
    int minutur;
    int klst;
};


int main()
{
    Timi t1;

    t1.klst = 13;
    t1.minutur = 21;

    cout << t1.klst << ":" << t1.minutur << endl;

    t1.klst = 908374;
    t1.minutur = -448934;

    cout << t1.klst << ":" << t1.minutur << endl;

    return 0;
}
