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

    theoutputfile.open("test.txt");
    if (theoutputfile.fail()) {
        cout << "can't open the file..." << endl;
        exit(1);
    }

    theoutput(cout, t);

    theoutputfile.close();
    return 0;
}

void theoutput(ostream& outs, string thetext) {
    outs << thetext << endl;
}
