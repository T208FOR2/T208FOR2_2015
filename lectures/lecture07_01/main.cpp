#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

void theoutput(ostream& outs, string thetext);

void openwritefile(ofstream& thefile, string thefilename);

int main()
{
    string t = "This is something\nthat I'm writing";
    ofstream theoutputfile;
    openwritefile(theoutputfile, "test2.txt");

    theoutput(theoutputfile, t);
    theoutput(cout, t);

    theoutputfile.close();
    return 0;
}

void theoutput(ostream& outs, string thetext) {
    outs << thetext << endl;
}

void openwritefile(ofstream& thefile, string thefilename) {
    thefile.open(thefilename.c_str());
    if (thefile.fail()) {
        cout << "can't open the file: " << thefilename << endl;
        exit(1);
    }
}

