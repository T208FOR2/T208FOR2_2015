#include <iostream>
#include <string>

using namespace std;


int main()
{
    unsigned int pos;
    string tmp = "Hellothere!";

    pos = tmp.find_first_of("lol");

    cout << pos << endl;

    return 0;
}
