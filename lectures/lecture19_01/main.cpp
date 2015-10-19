#include <iostream>

using namespace std;

class Numbers {
public:
    Numbers();
    ~Numbers();  // Destructor

    Numbers(const Numbers &copyme);  // Copy constructor

    void operator = (const Numbers & sameasme); // Assignment operator

    friend ostream& operator << (ostream& outs, const Numbers &thenums);
private:
    int n;  //Fjšldi staka
    int *p;  //Bendir ‡ fylki af n tšlum

    void initializenumbers();
};

Numbers::Numbers() {
    cout << "Constructor!" << endl;
    n = 10;
    p = new int[n];

    initializenumbers();
}

Numbers::~Numbers() {
    cout << "Destructor" << endl;
    delete [] p;
}

Numbers::Numbers(const Numbers &copyme) {
    cout << "Copy constructor!" << endl;
    n = copyme.n;
    p = new int[n];
    for (int i = 0; i < n; i++) {
        p[i] = copyme.p[i];
    }
}

void Numbers::operator = (const Numbers &sameasme) {
    cout << "Assignment operator!" << endl;

    if (n != sameasme.n) {
        delete [] p;

        n = sameasme.n;
        p = new int[n];
    }

    for (int i = 0; i < n; i++) {
        p[i] = sameasme.p[i];
    }
}

void Numbers::initializenumbers() {
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
}

ostream& operator << (ostream& outs, const Numbers &thenums) {
    for (int i = 0; i < thenums.n; i++) {
        outs << thenums.p[i] << " ";
    }
    return outs;
}

void dummyfunction(Numbers num) {
    cout << num << endl;
}

int main()
{
    Numbers thenumbers;

    cout << thenumbers << endl;
    dummyfunction(thenumbers);
    cout << "Hi!" << endl;

    Numbers thenumbers2;
    thenumbers2 = thenumbers;
    cout << thenumbers2 << endl;

    return 0;
}
