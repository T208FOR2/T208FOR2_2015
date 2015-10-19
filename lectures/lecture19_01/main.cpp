#include <iostream>

using namespace std;

class Numbers {
public:
    Numbers();

private:
    int n;  //Fjšldi staka
    int *p;  //Bendir ‡ fylki af n tšlum
};

Numbers::Numbers() {
    cout << "Constructor!" << endl;
    n = 0;
    p = NULL;
}

int main()
{
    Numbers thenumbers;

    return 0;
}
