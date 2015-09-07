#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

void theoutput(ostream& outs, string thetext);

int main()
{
    string t = "This is something\nthat I'm writing";
    ofstream theoutputfile;

    theoutput(cout, t);

    return 0;
}

void theoutput(ostream& outs, string thetext) {
    outs << thetext << endl;
}
