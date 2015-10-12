#include <iostream>

using namespace std;

class Timi {
public:
    void set_klst(int k);
    void set_minutur(int m);
    int get_klst();
    int get_minutur();

    void output();
private:
    int minutur;
    int klst;

    void fix_minutur();
    void fix_klst();
};

void Timi::output() {
    cout << klst;
    cout << ":";
    cout << minutur;
}

// ------------------ MAIN ------------------
int main()
{
    Timi t1;

    t1.set_klst(13);
    t1.set_minutur(21);

    t1.output();
    cout << endl;

    t1.set_klst(908374);
    t1.set_minutur(-448934);

    t1.output();
    cout << endl;

    return 0;
}





// -------------------------------
// FUNCTIONS
// -------------------------------

void Timi::set_klst(int k) {
    klst = k;
    fix_klst();
}

void Timi::set_minutur(int m) {
    minutur = m;
    fix_minutur();
    fix_klst();
}

int Timi::get_klst() {
    return klst;
}
int Timi::get_minutur() {
    return minutur;
}

void Timi::fix_minutur() {
    while (minutur < 0) {
        minutur += 60;
        klst--;
    }
    while (minutur >= 60) {
        minutur -= 60;
        klst++;
    }
}

void Timi::fix_klst() {
    while (klst < 0) {
        klst += 24;
    }
    while (klst >= 24) {
        klst -= 24;
    }
}

