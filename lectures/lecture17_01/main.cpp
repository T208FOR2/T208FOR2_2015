#include <iostream>

using namespace std;

class Timi {
public:
    void set_klst(int k);
    void set_minutur(int m);

private:
    int minutur;
    int klst;
};

void Timi::set_klst(int k) {
    klst = k;
}

void Timi::set_minutur(int m) {
    minutur = m;
}


int main()
{
    Timi t1;

    t1.set_klst(13);
    t1.set_minutur(21);

    cout << t1.klst << ":" << t1.minutur << endl;

    t1.set_klst(908374);
    t1.set_minutur(-448934);

    cout << t1.klst << ":" << t1.minutur << endl;

    return 0;
}
