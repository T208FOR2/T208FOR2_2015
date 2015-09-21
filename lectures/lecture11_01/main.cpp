#include <iostream>

using namespace std;

int main()
{
    char takn[100] = "Hi there!";

    takn[9] = 'X';
    cout << endl << "012345678901234567890" << endl;
    cout << takn << endl << endl;

    strcpy(takn,"Goodbye!");
    cout << takn << endl << endl;


    return 0;
}
