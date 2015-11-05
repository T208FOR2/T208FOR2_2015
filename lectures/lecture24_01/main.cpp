#include <iostream>
#include <string>

using namespace std;


int main()
{
    unsigned int pos;
    string tmp = "Hello...there!";

    pos = tmp.find_first_of("'.!?\n\t \"");
    while (pos < tmp.length()) {
        tmp[pos] = '?';
        pos = tmp.find_first_of("'.!?\n\t \"",pos+1);
    }

    cout << tmp << endl;

    return 0;
}
