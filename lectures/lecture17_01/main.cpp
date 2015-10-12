#include <iostream>

using namespace std;

class Timi {
public:
    Timi();
    Timi(int m);
    Timi(int k, int m);

    void set_klst(int k);
    void set_minutur(int m);
    int get_klst();
    int get_minutur();

    void output();

    friend Timi addTimi(Timi t1, Timi t2);
private:
    int minutur;
    int klst;

    void fix_minutur();
    void fix_klst();
};

Timi addTimi(Timi t1, Timi t2) {
    Timi newtimi;

    newtimi.minutur = t1.minutur + t2.minutur;
    newtimi.klst = t1.klst + t2.klst;
    newtimi.fix_minutur();
    newtimi.fix_klst();

    return newtimi;
}




// ------------------ MAIN ------------------
int main()
{
    Timi t1, t2(13,101837), t3(186);

    t1.set_klst(13);
    t1.set_minutur(21);

    t1.output();
    cout << endl;
    t2.output();
    cout << endl;
    t3.output();
    cout << endl;

    t1.set_klst(908374);
    t1.set_minutur(-448934);

    t1.output();
    cout << endl;

    cout << "----- adding time ------" << endl;
    Timi t4;
    t4 = addTimi(t1,t2);
    t4.output();
    cout << endl;

    return 0;
}





// -------------------------------
// FUNCTIONS
// -------------------------------

Timi::Timi() {
    minutur = 0;
    klst = 0;
    //cout << "Hi, I'm the default constructor!" << endl;
}

Timi::Timi(int m) {
    minutur = m;
    klst = 0;

    fix_minutur();
    fix_klst();

    //cout << "Hi, I'm the constructor with a single parameter!" << endl;
}

Timi::Timi(int k, int m) {
    minutur = m;
    klst = k;

    fix_minutur();
    fix_klst();
    //cout << "Hi, I'm the constructor with two parameters!" << endl;
}

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

void Timi::output() {
    if (klst < 10) {
        cout << "0";
    }
    cout << klst;
    cout << ":";
    if (minutur < 10) {
        cout << "0";
    }
    cout << minutur;
}
