#include <iostream>

using namespace std;

class Numbers {
public:
    Numbers();

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

int main()
{
    Numbers thenumbers;

    cout << thenumbers << endl;

    return 0;
}
