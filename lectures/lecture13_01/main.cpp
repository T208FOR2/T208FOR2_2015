#include <iostream>

using namespace std;

int main()
{
    int *p;

    p = new int;

    *p = 42;

    cout << *(p + 7) << endl;

    delete p;

    return 0;
}
