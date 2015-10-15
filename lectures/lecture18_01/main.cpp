#include <iostream>

using namespace std;

class Timi {
public:
    Timi();
    Timi(int m);
    Timi(int k, int m);

    void set_klst(int k);
    void set_minutur(int m);
    int get_klst() const;
    int get_minutur() const;

    void output() const;

    // old ugly version of adding
    friend Timi addTimi(const Timi &t1, const Timi &t2);
    friend Timi operator + (const Timi &t1, const Timi &t2);

    friend bool operator > (const Timi &t1, const Timi &t2);
    friend bool operator == (const Timi &t1, const Timi &t2);
    friend bool operator >= (const Timi &t1, const Timi &t2);
    friend bool operator < (const Timi &t1, const Timi &t2);
private:
    int minutur;
    int klst;

    void fix_minutur();
    void fix_klst();
};




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

    t4 = t1 + t2;
    t4.output();
    cout << endl;

    t4 = t1 + t2 + t3 + t1 + t2 + t3;
    t4.output();
    cout << endl;

    if (t1 > t2) {
        t1.output();
        cout << endl;
    }
    else {
        t2.output();
        cout << endl;
    }

    return 0;
}





// -------------------------------
// FUNCTIONS
// -------------------------------

bool operator < (const Timi &t1, const Timi &t2) {
    return !(t1 >= t2);
}

bool operator >= (const Timi &t1, const Timi &t2) {
    return (t1 > t2 || t1 == t2);
}

bool operator == (const Timi &t1, const Timi &t2) {
    return (t1.minutur == t2.minutur && t1.klst == t2.klst);
}

bool operator > (const Timi &t1, const Timi &t2) {
    if (t1.klst > t2.klst) {
        return true;
    }
    else if (t1.klst == t2.klst && t1.minutur > t2.minutur) {
        return true;
    }
    return false;
}


Timi operator + (const Timi &t1, const Timi &t2) {
    Timi newtimi;

    newtimi.minutur = t1.minutur + t2.minutur;
    newtimi.klst = t1.klst + t2.klst;
    newtimi.fix_minutur();
    newtimi.fix_klst();

    return newtimi;
}

Timi addTimi(const Timi &t1, const Timi &t2) {
    Timi newtimi;

    newtimi.minutur = t1.minutur + t2.minutur;
    newtimi.klst = t1.klst + t2.klst;
    newtimi.fix_minutur();
    newtimi.fix_klst();

    return newtimi;
}

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

int Timi::get_klst() const {
    return klst;
}
int Timi::get_minutur() const {
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

void Timi::output() const {
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
